#include <iostream>
#include <iomanip>
#include <bitset>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop_fmul_sqrt.h"

// 32ビットを4ビットずつ区切って表示するヘルパー関数
void print_binary(uint32_t val) {
    std::string s = std::bitset<32>(val).to_string();
    for (int i = 0; i < 32; i++) {
        if (i > 0 && i % 4 == 0) std::cout << "_";
        std::cout << s[i];
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vtop_fmul_sqrt* top = new Vtop_fmul_sqrt;

    // 波形出力設定
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("wave.vcd");

    int time_counter = 0;
    auto tick = [&]() {
        top->clk = 0; top->eval(); tfp->dump(time_counter++);
        top->clk = 1; top->eval(); tfp->dump(time_counter++);
    };

    // リセット処理
    top->rst_n = 0;
    top->input_valid = 0;
    for(int i=0; i<5; i++) tick();
    top->rst_n = 1;
    tick();

    // --- 【修正箇所】ビットによる入力設定 ---
    // 例: a = 1.0 (0x3f800000), b = 4.0 (0x40800000)
    uint32_t input_a_bits = 0x4e800000; 
    uint32_t input_b_bits = 0x3f800000; 

    // 2進数で直接書きたい場合は 0b を使います（C++14以降）
    // uint32_t input_b_bits = 0b01000000100000000000000000000000;

    top->a = input_a_bits;
    top->b = input_b_bits;
    top->input_valid = 1;
    tick();
    top->input_valid = 0;

    // 結果が出るまで待機
    bool success = false;
    for (int i = 0; i < 100; i++) {
        tick();
        if (top->out_valid) {
            uint32_t res_bits = top->result;

            std::cout << "========================================" << std::endl;
            std::cout << "Calculation Finished!" << std::endl;
            
            std::cout << "Input a:  ";
            print_binary(input_a_bits);
            std::cout << " (0x" << std::hex << std::setw(8) << std::setfill('0') << input_a_bits << ")" << std::endl;

            std::cout << "Input b:  ";
            print_binary(input_b_bits);
            std::cout << " (0x" << std::hex << std::setw(8) << std::setfill('0') << input_b_bits << ")" << std::endl;

            std::cout << "Result:   ";
            print_binary(res_bits);
            std::cout << " (0x" << std::hex << std::setw(8) << std::setfill('0') << res_bits << ")" << std::endl;
            std::cout << "========================================" << std::endl;
            
            success = true;
            break;
        }
    }

    if (!success) std::cout << "Timeout!" << std::endl;

    tfp->close();
    delete top;
    return 0;
}
