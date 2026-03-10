#include <iostream>
#include <iomanip>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vfdiv.h" // Verilatorが生成するヘッダ

// 32bit浮動小数点を表示用の共用体
union FloatConv {
    float f;
    uint32_t i;
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vfdiv* top = new Vfdiv;

    // VCD波形出力の設定 (任意)
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    uint32_t tick = 0;
    auto reset_and_sync = [&]() {
        top->clk = 0; top->eval(); tfp->dump(tick++);
        top->clk = 1; top->eval(); tfp->dump(tick++);
    };

    // --- 初期化 ---
    top->rst_n = 0;
    top->input_valid = 0;
    for(int i=0; i<5; i++) reset_and_sync();
    top->rst_n = 1;
    reset_and_sync();

    std::cout << "Enter Hex values for input_a and input_b (e.g., 40000000 40800000 for 2.0 / 4.0)" << std::endl;
    std::cout << "Type 'q' to quit." << std::endl;

    std::string s_a, s_b;
    while (std::cin >> s_a && s_a != "q") {
        std::cin >> s_b;

        // 文字列を16進数として数値に変換
        uint32_t val_a = std::stoul(s_a, nullptr, 16);
        uint32_t val_b = std::stoul(s_b, nullptr, 16);

        FloatConv fa, fb;
        fa.i = val_a; fb.i = val_b;

        // --- 入力供給 ---
        top->input_a = val_a;
        top->input_b = val_b;
        top->input_valid = 1;
        
        std::cout << "\nInput A: " << std::hex << val_a << " (" << fa.f << ")" << std::endl;
        std::cout << "Input B: " << std::hex << val_b << " (" << fb.f << ")" << std::endl;

        reset_and_sync();
        top->input_valid = 0;

        // パイプラインのレイテンシ分（Stage 1~3 + 出力レジスタ）待機
        // このモジュールは約4クロックで結果が出ます
        for (int i = 0; i < 10; i++) {
            reset_and_sync();
            if (top->out_valid) {
                FloatConv res;
                res.i = top->result;
                std::cout << "Result:  " << std::hex << std::setw(8) << std::setfill('0') << top->result 
                          << " (" << res.f << ")" << std::endl;
                break;
            }
        }
        std::cout << "---------------------------------------" << std::endl;
    }

    tfp->close();
    delete top;
    return 0;
}
