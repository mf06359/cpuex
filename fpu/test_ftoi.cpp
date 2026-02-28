#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <thread>
#include <atomic>
#include <mutex>
#include <iomanip>
#include <verilated.h>
#include "Vitof.h" 

// --- 設定 ---
// パイプライン段数（itofの実装に合わせて変更してください）
const int LATENCY = 2; 

union FloatBits {
    float f;
    uint32_t u;
};

// --- グローバル変数 ---
std::atomic<uint64_t> g_total_checked(0);
std::atomic<uint64_t> g_total_errors(0);
std::mutex g_print_mutex;

// --- 期待値計算 ---
uint32_t compute_expected(uint32_t input_bits) {
    // 入力を符号付き整数として解釈
    int32_t in_val = (int32_t)input_bits;
    
    // floatへキャスト (ここで丸めが発生する)
    float result_f = static_cast<float>(in_val);
    
    FloatBits res_val;
    res_val.f = result_f;
    return res_val.u;
}

// --- ワーカースレッド ---
void worker_thread(uint32_t start_addr, uint32_t end_addr, int thread_id) {
    Vitof* top = new Vitof;
    
    struct Transaction {
        uint32_t input;
        uint32_t expected;
    };
    std::deque<Transaction> scoreboard;

    top->clk = 0;
    top->rst_n = 0;
    top->eval();
    for(int i=0; i<5; i++) { top->clk = !top->clk; top->eval(); top->clk = !top->clk; top->eval(); }
    top->rst_n = 1;

    uint64_t local_errors = 0;
    uint64_t local_checked = 0;

    for (uint64_t i = start_addr; i <= end_addr; ++i) {
        uint32_t input_val = (uint32_t)i;

        // Input
        top->clk = 1; top->eval();
        
        // --- 修正箇所: ポート名を in_i に変更 ---
        top->in_i = input_val; 
        
        top->input_valid = 1;

        scoreboard.push_back({input_val, compute_expected(input_val)});

        // Output check
        top->clk = 0; top->eval();
        if (top->out_valid) {
            if (scoreboard.empty()) break;
            Transaction t = scoreboard.front(); scoreboard.pop_front();

            // --- 修正箇所: ポート名を out_f に変更 ---
            uint32_t res = top->out_f;
            uint32_t exp = t.expected;

            // 1 ULP 許容 (丸めモードの違い対策)
            uint32_t diff = (res > exp) ? (res - exp) : (exp - res);
            
            if (diff > 1) {
                 local_errors++;
                 if (local_errors <= 3) {
                    std::lock_guard<std::mutex> lock(g_print_mutex);
                    FloatBits out_f, exp_f; out_f.u = res; exp_f.u = exp;
                    std::cerr << "[itof Error] In: " << (int32_t)t.input 
                              << " Exp: " << exp_f.f << " (0x" << std::hex << exp << ")"
                              << " Got: " << out_f.f << " (0x" << res << ")" << std::dec << std::endl;
                 }
            }
            local_checked++;
        }
        
        if (local_checked % 0x10000 == 0) {
            g_total_checked += 0x10000;
            local_checked = 0;
        }
    }

    // Drain pipeline
    top->input_valid = 0;
    for (int k = 0; k < LATENCY + 5; k++) {
        top->clk = 1; top->eval(); top->clk = 0; top->eval();
        if (top->out_valid && !scoreboard.empty()) {
            Transaction t = scoreboard.front(); scoreboard.pop_front();
            
            // --- 修正箇所: ポート名を out_f に変更 ---
            uint32_t res = top->out_f;
            uint32_t diff = (res > t.expected) ? (res - t.expected) : (t.expected - res);
            
            if (diff > 1) local_errors++;
            local_checked++;
        }
    }

    g_total_checked += local_checked;
    g_total_errors += local_errors;
    top->final();
    delete top;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    const uint64_t TOTAL_TESTS = 0xFFFFFFFFULL + 1; // 全32bit整数
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 4;

    std::cout << "Starting itof Exhaustive Test (" << num_threads << " threads)..." << std::endl;

    std::vector<std::thread> threads;
    uint64_t range = TOTAL_TESTS / num_threads;

    for (unsigned int i = 0; i < num_threads; ++i) {
        uint32_t start = i * range;
        uint32_t end = (i == num_threads - 1) ? 0xFFFFFFFF : (start + range - 1);
        threads.emplace_back(worker_thread, start, end, i);
    }

    while(g_total_checked < TOTAL_TESTS) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\rProgress: " << std::fixed << std::setprecision(1) 
                  << (double)g_total_checked / TOTAL_TESTS * 100.0 << "% Errors: " << g_total_errors << std::flush;
        if (g_total_errors > 1000) break; 
    }
    
    for (auto& t : threads) t.join();
    
    std::cout << "\nFinished. Total Errors: " << g_total_errors << std::endl;
    return 0;
}
