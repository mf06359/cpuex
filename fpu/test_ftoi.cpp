#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <thread>
#include <atomic>
#include <mutex>
#include <iomanip>
#include <chrono>
#include <verilated.h>
#include "Vftoi.h" 

using namespace std;

const int LATENCY = 2; 

union FloatBits {
    float f;
    uint32_t u;
};

atomic<uint64_t> g_total_checked(0);
atomic<uint64_t> g_total_errors(0);
atomic<uint64_t> g_total_skipped(0); // NaNでスキップした数
mutex g_print_mutex;

// 期待値の計算
int32_t compute_expected(uint32_t input_bits) {
    FloatBits in_val;
    in_val.u = input_bits;
    
    // 巨大すぎる値の飽和処理
    if (in_val.f >= 2147483648.0f) return 2147483647;
    if (in_val.f <= -2147483649.0f) return -2147483648;

    return static_cast<int32_t>(in_val.f);
}

void worker_thread(uint32_t start_addr, uint32_t end_addr, int thread_id) {
    Vftoi* top = new Vftoi;
    
    struct Transaction {
        uint32_t input_bits;
        int32_t expected;
    };
    deque<Transaction> scoreboard;

    top->clk = 0;
    top->rst_n = 0;
    top->eval();
    for(int i=0; i<5; i++) { top->clk = 1; top->eval(); top->clk = 0; top->eval(); }
    top->rst_n = 1;

    uint64_t local_errors = 0;
    uint64_t local_checked = 0;
    uint64_t local_skipped = 0;

    for (uint64_t i = start_addr; i <= (uint64_t)end_addr; ++i) {
        uint32_t input_val = (uint32_t)i;

        // --- NaN判定 ---
        // 指数部(30:23)が全1 かつ 仮数部(22:0)が非ゼロ
        bool is_nan = ((input_val & 0x7f800000) == 0x7f800000) && ((input_val & 0x007fffff) != 0);
        
        if (is_nan) {
            local_skipped++;
            // 進捗表示のために一定数ごとに共有変数へ反映
            if ((local_checked + local_skipped) % 0x20000 == 0) {
                g_total_checked += 0x20000;
            }
            continue;
        }

        // --- シミュレーション実行 (NaN以外) ---
        top->clk = 1; 
        top->in_f = input_val; 
        top->input_valid = 1;
        top->eval();

        scoreboard.push_back({input_val, compute_expected(input_val)});

        top->clk = 0; 
        top->eval();

        if (top->out_valid) {
            if (!scoreboard.empty()) {
                Transaction t = scoreboard.front(); 
                scoreboard.pop_front();

                int32_t res = (int32_t)top->out_i;
                int32_t exp = t.expected;

                if (res != exp) {
                    local_errors++;
                    if (local_errors <= 5) {
                        lock_guard<mutex> lock(g_print_mutex);
                        FloatBits in_f; in_f.u = t.input_bits;
                        cerr << "\n[ftoi Error] In: 0x" << hex << setw(8) << setfill('0') << t.input_bits 
                             << " (" << dec << in_f.f << ") Exp: " << exp << " Got: " << res << endl;
                    }
                }
                local_checked++;
            }
        }
        
        if ((local_checked + local_skipped) % 0x20000 == 0) {
            g_total_checked += 0x20000;
        }
    }

    // パイプライン・フラッシュ
    top->input_valid = 0;
    for (int k = 0; k < LATENCY + 10; k++) {
        top->clk = 1; top->eval(); top->clk = 0; top->eval();
        if (top->out_valid && !scoreboard.empty()) {
            Transaction t = scoreboard.front(); 
            scoreboard.pop_front();
            if ((int32_t)top->out_i != t.expected) local_errors++;
            local_checked++;
        }
    }

    g_total_checked += ((local_checked + local_skipped) % 0x20000); 
    g_total_errors += local_errors;
    g_total_skipped += local_skipped;
    top->final();
    delete top;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    const uint64_t TOTAL_TESTS = 0x100000000ULL; 
    unsigned int num_threads = thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 4;

    cout << "Starting ftoi Exhaustive Test (NaNs excluded, " << num_threads << " threads)..." << endl;

    vector<thread> threads;
    uint64_t range = TOTAL_TESTS / num_threads;

    for (unsigned int i = 0; i < num_threads; ++i) {
        uint32_t start = i * range;
        uint32_t end = (i == num_threads - 1) ? 0xFFFFFFFF : (start + range - 1);
        threads.emplace_back(worker_thread, start, end, i);
    }

    while(g_total_checked < TOTAL_TESTS) {
        this_thread::sleep_for(chrono::milliseconds(500));
        double progress = (double)g_total_checked / TOTAL_TESTS * 100.0;
        cout << "\rProgress: " << fixed << setprecision(2) << progress 
             << "% | Errors: " << dec << g_total_errors 
             << " | Skipped(NaN): " << g_total_skipped << flush;
        
        if (g_total_errors > 5000) break; 
    }
    
    for (auto& t : threads) t.join();
    
    cout << "\nFinished. Total Errors: " << g_total_errors 
         << " | Total Skipped: " << g_total_skipped << endl;
    return (g_total_errors == 0) ? 0 : 1;
}
