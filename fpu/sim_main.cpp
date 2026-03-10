#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include "Vfsqrt.h"
#include "verilated.h"

// 32bit浮動小数点のビット解釈用共用体
union FloatConv {
    float f;
    uint32_t i;
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vfsqrt* top = new Vfsqrt;

    // 初期化
    top->clk = 0;
    top->rst_n = 0;
    top->input_valid = 0;
    top->eval();

    // リセット解除
    top->rst_n = 1;
    top->clk = 1;
    top->eval();
    top->clk = 0;
    top->eval();

    float test_val;
    std::cout << "平方根を計算したい数値を入力してください: ";
    if (!(std::cin >> test_val)) return 0;

    FloatConv in_conv;
    in_conv.f = test_val;

    // 入力セット (パイプラインの開始)
    top->input_a = in_conv.i;
    top->input_valid = 1;

    // パイプラインを数サイクル回す (モジュールの遅延に合わせる)
    for (int i = 0; i < 10; i++) {
        top->clk = !top->clk;
        top->eval();
        
        // input_validは1クロックだけONにする
        if (i == 0 && top->clk == 0) top->input_valid = 0;

        // 結果が有効になったら表示
        if (top->out_valid && top->clk == 1) {
            FloatConv out_conv;
            out_conv.i = top->result;

            std::cout << "\n--- シミュレーション結果 ---" << std::endl;
            std::cout << "入力: " << test_val << " (0x" << std::hex << in_conv.i << ")" << std::endl;
            std::cout << "出力: " << out_conv.f << " (0x" << std::hex << out_conv.i << ")" << std::endl;
            std::cout << "期待値 (sqrtf): " << std::sqrt(test_val) << std::endl;
            break;
        }
    }

    top->final();
    delete top;
    return 0;
}
