#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <iomanip>
#include <random>
#include <verilated.h>
#include "Vfadd.h"

const int ESTIMATED_LATENCY = 3;
const int NUM_RANDOM_TRIALS = 10000; 

using namespace std;

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
    fres.f = fa.f + fb.f;
    return fres.u;
}

bool check_result(uint32_t result, uint32_t expected) {
    if (is_inf(result) || is_inf(expected)) return true;

    FloatBits res_f, exp_f;
    res_f.u = result;
    exp_f.u = expected;

    if (isnan(res_f.f) && isnan(exp_f.f)) return true;

    if (result == expected) return true;

    // +0 and -0
    if (res_f.f == 0.0f && exp_f.f == 0.0f) return true;

    if ((result >> 31) == (expected >> 31)) {
        int32_t diff = (int32_t)result - (int32_t)expected;
        if (abs(diff) < 1) return true;
    }

    return false;
}


int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vfadd* top = new Vfadd;

    deque<Transaction> scoreboard;
    
    mt19937 gen(12345);
    uniform_int_distribution<uint32_t> dist_mant(0, 0x7FFFFF);
    uniform_int_distribution<uint32_t> dist_sign(0, 1);

    uint64_t total_tests = 0;
    uint64_t error_count = 0;
    uint64_t skipped_count = 0;

    top->clk = 0;
    top->rst_n = 0;
    top->eval();
    for(int i = 0; i < 5; i++) {
        top->clk = 1; top->eval(); 
        top->clk = 0; top->eval(); 
    }
    top->rst_n = 1;

    cout << "Starting fadd Test..." << endl;

    for (int exp_a = 0; exp_a <= 255; exp_a++) {
        if (exp_a % 16 == 0) {
            cout << "\rProgress: exponent a " << exp_a << "/254  Errors: " << error_count << flush;
        }

        for (int exp_b = 1; exp_b <= 254; exp_b++) {
            struct MantPair { uint32_t ma; uint32_t mb; };
            vector<MantPair> test_mants;

            uint32_t maxmantissa = 0x7FFFFF;
            test_mants.push_back({0, 0});
            test_mants.push_back({0, maxmantissa});
            test_mants.push_back({maxmantissa, 0});
            test_mants.push_back({maxmantissa, maxmantissa});

            for (int k = 0; k < NUM_RANDOM_TRIALS; k++) {
                test_mants.push_back({dist_mant(gen), dist_mant(gen)});
            }

            for (const auto& mp : test_mants) {
                uint32_t sign_a = dist_sign(gen);
                uint32_t sign_b = dist_sign(gen);

                uint32_t val_a = make_float(sign_a, exp_a, mp.ma);
                uint32_t val_b = make_float(sign_b, exp_b, mp.mb);
                uint32_t expected = compute_expected(val_a, val_b);

                auto is_special = [](uint32_t bits) {
                    uint32_t exp = (bits >> 23) & 0xFF;
                    return (exp == 0 || exp == 0xFF);
                };

                if (is_special(val_a) || is_special(val_b) || is_special(expected)) {
                    skipped_count++;
                    continue;
                }

                // set inputs
                top->clk = 1;
                top->eval();
                
                top->input_a = val_a;
                top->input_b = val_b;
                top->input_valid = 1;

                scoreboard.push_back({val_a, val_b, expected});
                total_tests++;

                // output
                top->clk = 0;
                top->eval();

                if (top->out_valid) {
                    Transaction t = scoreboard.front();
                    scoreboard.pop_front();

                    if (!check_result(top->result, t.expected)) {
                        error_count++;
                        if (error_count <= 10) {
                            FloatBits fa, fb, fres, fexp;
                            fa.u = t.a; fb.u = t.b; fres.u = top->result; fexp.u = t.expected;
                            cout << "\n[Mismatch] A=" << fa.f << " B=" << fb.f
                                      << "\n\tExp: " << fexp.f << " (0x" << hex << t.expected << ")"
                                      << "\n\tGot: " << fres.f << " (0x" << top->result << ")" << dec << endl;
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

finish:
    cout << "\n\nSimulation Finished." << endl;
    cout << "Total Valid Tests: " << total_tests << endl;
    cout << "Errors:            " << error_count << endl;

    if (error_count == 0) cout << "PASSED" << endl;
    else cout << "FAILED" << endl;

    top->final();
    delete top;
    return 0;
}
