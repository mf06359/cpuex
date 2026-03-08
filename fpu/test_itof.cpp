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

using namespace std;

const int LATENCY = 2; 

union FloatBits {
    float f;
    uint32_t u;
};

atomic<uint64_t> g_total_checked(0);
atomic<uint64_t> g_total_errors(0);
mutex g_print_mutex;

uint32_t compute_expected(uint32_t input_bits) {
    int32_t in_val = (int32_t)input_bits;
    
    float result_f = static_cast<float>(in_val);
    
    FloatBits res_val;
    res_val.f = result_f;
    return res_val.u;
}

void worker_thread(uint32_t start_addr, uint32_t end_addr, int thread_id) {
    Vitof* top = new Vitof;
    
    struct Transaction {
        uint32_t input;
        uint32_t expected;
    };
    deque<Transaction> scoreboard;

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
        
        top->in_i = input_val; 
        
        top->input_valid = 1;

        scoreboard.push_back({input_val, compute_expected(input_val)});

        top->clk = 0; top->eval();
        if (top->out_valid) {
            if (scoreboard.empty()) break;
            Transaction t = scoreboard.front(); scoreboard.pop_front();

            uint32_t res = top->out_f;
            uint32_t exp = t.expected;

            uint32_t diff = (res > exp) ? (res - exp) : (exp - res);
            
            if (diff >= 1) {
                 local_errors++;
                 if (local_errors <= 3) {
                    lock_guard<mutex> lock(g_print_mutex);
                    FloatBits out_f, exp_f; out_f.u = res; exp_f.u = exp;
                    cerr << "[itof Error] In: " << (int32_t)t.input 
                              << " Exp: " << exp_f.f << " (0x" << hex << exp << ")"
                              << " Got: " << out_f.f << " (0x" << res << ")" << dec << endl;
                 }
            }
            local_checked++;
        }
        
        if (local_checked % 0x10000 == 0) {
            g_total_checked += 0x10000;
            local_checked = 0;
        }
    }

    top->input_valid = 0;
    for (int k = 0; k < LATENCY + 5; k++) {
        top->clk = 1; top->eval(); top->clk = 0; top->eval();
        if (top->out_valid && !scoreboard.empty()) {
            Transaction t = scoreboard.front(); scoreboard.pop_front();
            
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
    const uint64_t TOTAL_TESTS = 0xFFFFFFFFULL + 1; 
    unsigned int num_threads = thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 4;

    cout << "Starting itof Exhaustive Test (" << num_threads << " threads)..." << endl;

    vector<thread> threads;
    uint64_t range = TOTAL_TESTS / num_threads;

    for (unsigned int i = 0; i < num_threads; ++i) {
        uint32_t start = i * range;
        uint32_t end = (i == num_threads - 1) ? 0xFFFFFFFF : (start + range - 1);
        threads.emplace_back(worker_thread, start, end, i);
    }

    while(g_total_checked < TOTAL_TESTS) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\rProgress: " << fixed << setprecision(1) 
                  << (double)g_total_checked / TOTAL_TESTS * 100.0 << "% Errors: " << g_total_errors << flush;
        if (g_total_errors > 1000) break; 
    }
    
    for (auto& t : threads) t.join();
    
    cout << "\nFinished. Total Errors: " << g_total_errors << endl;
    return 0;
}
