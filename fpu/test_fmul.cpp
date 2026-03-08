#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <iomanip>
#include <random>
#include <verilated.h>
#include "Vfmul.h" 

const int ESTIMATED_LATENCY = 3; 
const int NUM_RANDOM_TRIALS = 10000; 

union FloatBits {
    float f;
    uint32_t u;
};

struct Transaction {
    uint32_t a;
    uint32_t b;
    uint32_t expected;
};

uint32_t make_float(uint32_t sign, uint32_t exp, uint32_t mant) {
    return (sign << 31) | ((exp & 0xFF) << 23) | (mant & 0x7FFFFF);
}

bool is_denormal(uint32_t bits) {
    uint32_t exp = (bits >> 23) & 0xFF;
    uint32_t mant = bits & 0x7FFFFF;
    return (exp == 0 && mant != 0);
}

bool is_nan_or_inf(uint32_t bits) {
    uint32_t exp = (bits >> 23) & 0xFF;
    return (exp == 0xFF);
}

bool is_zero(uint32_t bits) {
    return (bits & 0x7FFFFFFF) == 0;
}

bool is_ignore_target(uint32_t bits) {
    if (is_nan_or_inf(bits)) return true;
    if (is_denormal(bits))   return true; 
    return false;
}

uint32_t compute_expected(uint32_t a_bits, uint32_t b_bits) {
    FloatBits fa, fb, fres;
    fa.u = a_bits;
    fb.u = b_bits;
    fres.f = fa.f * fb.f; 
    return fres.u;
}

bool check_result(uint32_t result, uint32_t expected) {
    if (is_ignore_target(expected)) return true;

    if (result == expected) return true;

    FloatBits res_f, exp_f;
    res_f.u = result;
    exp_f.u = expected;

    if (is_zero(result) && is_zero(expected)) return true;

    if ((result >> 31) == (expected >> 31)) {
        int32_t diff = (int32_t)result - (int32_t)expected;
        if (std::abs(diff) <= 1) return true;
    }

    return false;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vfmul* top = new Vfmul; 

    std::deque<Transaction> scoreboard;
    std::mt19937 gen(12345);
    std::uniform_int_distribution<uint32_t> dist_mant(0, 0x7FFFFF);
    std::uniform_int_distribution<uint32_t> dist_sign(0, 1);

    uint64_t total_tests = 0;
    uint64_t error_count = 0;
    uint64_t skipped_count = 0;

    top->clk = 0;
    top->rst_n = 0;
    top->eval();
    for(int i=0; i<5; i++) { top->clk=1; top->eval(); top->clk=0; top->eval(); }
    top->rst_n = 1;

    std::cout << "Starting fmul Test" << std::endl;

    for (int exp_a = 0; exp_a <= 254; ++exp_a) {
        if (exp_a % 16 == 0) {
            std::cout << "\rProgress: ExpA " << std::setw(3) << exp_a << "/254 | Errors: " << error_count << std::flush;
        }

        for (int exp_b = 0; exp_b <= 254; ++exp_b) {
            std::vector<std::pair<uint32_t, uint32_t>> test_mants;

            uint32_t M = 0x7FFFFF;
            test_mants.push_back({0, 0});
            test_mants.push_back({0, M});
            test_mants.push_back({M, 0});
            test_mants.push_back({M, M});

            for (int k = 0; k < NUM_RANDOM_TRIALS; ++k) {
                test_mants.push_back({dist_mant(gen), dist_mant(gen)});
            }

            for (const auto& mp : test_mants) {
                uint32_t sign_a = dist_sign(gen);
                uint32_t sign_b = dist_sign(gen);

                uint32_t val_a = make_float(sign_a, exp_a, mp.first);
                uint32_t val_b = make_float(sign_b, exp_b, mp.second);
                uint32_t expected = compute_expected(val_a, val_b);

                if (is_ignore_target(val_a) || is_ignore_target(val_b) || is_ignore_target(expected)) {
                    skipped_count++;
                    continue;
                }

                top->clk = 1;
                top->input_a = val_a;
                top->input_b = val_b;
                top->input_valid = 1;
                top->eval();

                scoreboard.push_back({val_a, val_b, expected});
                total_tests++;

                top->clk = 0;
                top->eval();

                if (top->out_valid) {
                    if (!scoreboard.empty()) {
                        Transaction t = scoreboard.front();
                        scoreboard.pop_front();

                        if (!check_result(top->result, t.expected)) {
                            error_count++;
                            if (error_count <= 10) {
                                FloatBits fa, fb, fres, fexp;
                                fa.u = t.a; fb.u = t.b; fres.u = top->result; fexp.u = t.expected;
                                std::cout << "\n[Mismatch] A=" << fa.f << " (0x" << std::hex << t.a << ") "
                                          << "B=" << fb.f << " (0x" << t.b << ")"
                                          << "\n\tExpected: " << fexp.f << " (0x" << t.expected << ")"
                                          << "\n\tGot     : " << fres.f << " (0x" << top->result << ")" 
                                          << std::dec << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }

    top->input_valid = 0;
    for (int i = 0; i < ESTIMATED_LATENCY + 10; ++i) {
        top->clk = 1; top->eval();
        top->clk = 0; top->eval();
        if (top->out_valid && !scoreboard.empty()) {
            Transaction t = scoreboard.front();
            scoreboard.pop_front();
            if (!check_result(top->result, t.expected)) error_count++;
        }
    }

    std::cout << "\n\nSimulation Finished." << std::endl;
    std::cout << "Total Valid Tests: " << total_tests << std::endl;
    std::cout << "Errors           : " << error_count << std::endl;

    if (error_count == 0 && total_tests > 0) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    top->final();
    delete top;
    return 0;
}
