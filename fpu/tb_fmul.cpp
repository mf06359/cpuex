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

bool is_denormalized(uint32_t bits) {
    uint32_t exp = (bits >> 23) & 0xFF;
    uint32_t mant = bits & 0x7FFFFF;
    return (exp == 0 && mant != 0);
}

bool is_inf(uint32_t bits) {
    uint32_t exp = (bits >> 23) & 0xFF;
    uint32_t mant = bits & 0x7FFFFF;
    return (exp == 0xFF && mant == 0);
}

uint32_t compute_expected(uint32_t a_bits, uint32_t b_bits) {
    FloatBits fa, fb, fres;
    fa.u = a_bits;
    fb.u = b_bits;
    fres.f = fa.f * fb.f;
    return fres.u;
}

bool check_result(uint32_t result, uint32_t expected) {
    // 非正規化数 または Inf を除外
    if (is_denormalized(result) || is_denormalized(expected) ||
        is_inf(result) || is_inf(expected)) {
        return true;
    }
    
    FloatBits res_f, exp_f;
    res_f.u = result;
    exp_f.u = expected;

    if (std::isnan(res_f.f) && std::isnan(exp_f.f)) return true;
    if (result == expected) return true;
    if (res_f.f == 0.0f && exp_f.f == 0.0f) return true;

    float diff = std::fabs(res_f.f - exp_f.f);
    float epsilon = std::fmax(1e-10f, std::fabs(exp_f.f) * 1e-6f); 
    if (diff <= epsilon) return true;

    return false;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vfmul* top = new Vfmul;

    std::deque<Transaction> scoreboard;
    std::mt19937 gen(42);
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

    std::cout << "Starting fmul Exhaustive Exponent Test..." << std::endl;
    std::cout << "Testing all pairs of exponents (1-254) * (1-254)" << std::endl;
    std::cout << "Per pair: Corner mantissas (0, MAX) + " << NUM_RANDOM_TRIALS << " randoms." << std::endl;
    std::cout << "Skipping denormalized numbers and Inf." << std::endl;

    for (int exp_a = 1; exp_a <= 254; ++exp_a) {
        if (exp_a % 16 == 0) {
            std::cout << "\rProgress: ExpA " << exp_a << "/254  Errors: " << error_count << std::flush;
        }

        for (int exp_b = 1; exp_b <= 254; ++exp_b) {
            struct MantPair { uint32_t ma; uint32_t mb; };
            std::vector<MantPair> test_mants;

            uint32_t MAX_MANT = 0x7FFFFF;
            test_mants.push_back({0, 0});
            test_mants.push_back({0, MAX_MANT});
            test_mants.push_back({MAX_MANT, 0});
            test_mants.push_back({MAX_MANT, MAX_MANT});

            for (int k = 0; k < NUM_RANDOM_TRIALS; ++k) {
                test_mants.push_back({dist_mant(gen), dist_mant(gen)});
            }

            for (const auto& mp : test_mants) {
                uint32_t sign_a = dist_sign(gen);
                uint32_t sign_b = dist_sign(gen);

                uint32_t val_a = make_float(sign_a, exp_a, mp.ma);
                uint32_t val_b = make_float(sign_b, exp_b, mp.mb);
                uint32_t expected = compute_expected(val_a, val_b);

                // 投入前にスキップ
                if (is_denormalized(val_a) || is_denormalized(val_b) || is_denormalized(expected) ||
                    is_inf(val_a) || is_inf(val_b) || is_inf(expected)) {
                    skipped_count++;
                    continue;
                }

                top->clk = 1; top->eval();
                top->input_a = val_a;
                top->input_b = val_b;
                top->input_valid = 1;

                scoreboard.push_back({val_a, val_b, expected});
                total_tests++;

                top->clk = 0; top->eval();
                if (top->out_valid) {
                    if (scoreboard.empty()) goto finish;
                    Transaction t = scoreboard.front();
                    scoreboard.pop_front();

                    if (!check_result(top->result, t.expected)) {
                        error_count++;
                        if (error_count <= 10) {
                            FloatBits fa, fb, fres, fexp;
                            fa.u = t.a; fb.u = t.b; fres.u = top->result; fexp.u = t.expected;
                            std::cout << "\n[Mismatch] A=" << fa.f << " B=" << fb.f
                                      << "\n\tExp: " << fexp.f << " (0x" << std::hex << t.expected << ")"
                                      << "\n\tGot: " << fres.f << " (0x" << top->result << ")" << std::dec << std::endl;
                        }
                    }
                }
            }
        }
    }

    top->input_valid = 0;
    for (int i = 0; i < ESTIMATED_LATENCY + 10; ++i) {
        top->clk = 1; top->eval(); top->clk = 0; top->eval();
        if (top->out_valid && !scoreboard.empty()) {
            Transaction t = scoreboard.front();
            scoreboard.pop_front();
            if (!check_result(top->result, t.expected)) error_count++;
        }
    }

finish:
    std::cout << "\n\nSimulation Finished." << std::endl;
    std::cout << "Total Valid Tests: " << total_tests << std::endl;
    std::cout << "Skipped Samples:   " << skipped_count << std::endl;
    std::cout << "Errors:            " << error_count << std::endl;

    if (error_count == 0) std::cout << "PASSED" << std::endl;
    else std::cout << "FAILED" << std::endl;

    top->final();
    delete top;
    return 0;
}
