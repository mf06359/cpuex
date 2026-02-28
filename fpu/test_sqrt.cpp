#include <iostream>
#include <verilated.h>
#include "Vfsqrt_10.h"
#include <vector>
#include <deque>
#include <cmath>
#include <iomanip>

// 共用体を使ってfloatとuint32_tのビット変換を行う
union FloatBits {
    float f;
    uint32_t u;
};

const uint32_t CONST_NAN = 0x7FC00000;

// C++側のリファレンスモデル（期待値計算）
uint32_t compute_expected(uint32_t input_bits) {
    FloatBits in_val;
    in_val.u = input_bits;

    uint32_t sign = (input_bits >> 31) & 0x1;
    uint32_t exp = (input_bits >> 23) & 0xFF;
    uint32_t mant = input_bits & 0x7FFFFF;

    // Case 1: NaN入力 (指数がALL 1で仮数が0以外)
    if (exp == 0xFF && mant != 0) {
        return CONST_NAN;
    }

    // Case 2: ゼロ入力 (+0 or -0)
    if ((input_bits & 0x7FFFFFFF) == 0) {
        return (sign << 31);
    }

    // Case 3: 負の数 (ただし-0は除く)
    if (sign == 1) {
        return CONST_NAN;
    }

    // 通常の計算
    // std::sqrtを使って計算
    float result_f = std::sqrt(in_val.f);
    
    if (std::isnan(result_f)) {
        return CONST_NAN;
    }

    FloatBits res_val;
    res_val.f = result_f;
    return res_val.u;
}

// スコアボード用の構造体
struct Transaction {
    uint32_t input;
    uint32_t expected;
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // モジュールのインスタンス化
    Vfsqrt_10* top = new Vfsqrt_10;

    // --- 全数調査設定 ---
    // 2^32 = 4,294,967,296
    const uint64_t TOTAL_PATTERNS = 1ULL << 32; 
    
    // 非正規化数の数 (符号2通り * 仮数部が0以外の2^23-1通り)
    const uint64_t DENORM_COUNT = 2ULL * 0x7FFFFF;
    // テストする総パターン数
    const uint64_t TARGET_PATTERNS = TOTAL_PATTERNS - DENORM_COUNT;
    
    std::deque<Transaction> scoreboard;

    // ループ用変数は uint64_t にする (32bitだとオーバーフローするため)
    uint64_t input_iterator = 0; 
    uint64_t checked_count = 0;
    uint64_t success_count = 0;
    uint64_t error_count = 0;

    // リセット処理
    top->clk = 0;
    top->rst_n = 0;
    top->eval();
    for(int i=0; i<10; i++) {
        top->clk = !top->clk;
        top->eval();
    }
    top->rst_n = 1;

    std::cout << "Starting EXHAUSTIVE simulation (0x00000000 to 0xFFFFFFFF)..." << std::endl;
    std::cout << "Skipping denormalized numbers." << std::endl;
    std::cout << "Target patterns: " << TARGET_PATTERNS << std::endl;
    std::cout << "This may take a while..." << std::endl;

    // プログレスバー更新頻度 (0.1% ごとに更新)
    uint64_t update_interval = TARGET_PATTERNS / 1000; 

    // 指定したパターン数を検証するまでループ
    while (checked_count < TARGET_PATTERNS && !Verilated::gotFinish()) {
        // --- クロック立ち上がり ---
        top->clk = 1;
        top->eval();

        // 非正規化数をスキップして次の有効な入力を探す
        while (input_iterator < TOTAL_PATTERNS) {
            uint32_t exp = (input_iterator >> 23) & 0xFF;
            uint32_t mant = input_iterator & 0x7FFFFF;
            if (exp == 0 && mant != 0) {
                input_iterator++; // 0以外の非正規化数はスキップ
            } else {
                break; // 有効な入力が見つかった
            }
        }

        // 1. 入力の供給 (全パターン網羅まで)
        if (input_iterator < TOTAL_PATTERNS) {
            top->input_a = (uint32_t)input_iterator;
            top->input_valid = 1;

            // 期待値を計算してキューに入れる
            uint32_t expected = compute_expected((uint32_t)input_iterator);
            scoreboard.push_back({(uint32_t)input_iterator, expected});
            
            input_iterator++;
        } else {
            // 入力終了後はvalidを下げる
            top->input_valid = 0;
        }

        // --- クロック立ち下がり ---
        top->clk = 0;
        top->eval();

        // 2. 出力の確認
        if (top->out_valid) {
            if (scoreboard.empty()) {
                std::cerr << "\nError: Received output but scoreboard is empty!" << std::endl;
                break;
            }

            Transaction t = scoreboard.front();
            scoreboard.pop_front();

            uint32_t res = top->result;
            uint32_t exp = t.expected;
            bool match = false;

            // 完全一致または1ULPの誤差を許容
            if (res == exp) {
                match = true;
            } else if ((res > exp ? res - exp : exp - res) <= 1) {
                 // NaN領域以外のズレならOKとする
                 // (指数部がオール1でない場合)
                 if ((exp & 0x7F800000) != 0x7F800000) {
                     match = true;
                 }
            }

            // RTLがNaNを返す場合
            if (exp == CONST_NAN) {
                match = (res == CONST_NAN);
            }

            if (match) {
                success_count++;
            } else {
                error_count++;
                // エラー詳細は最初の10件だけ表示
                if (error_count <= 10) {
                    FloatBits in_f, out_f, exp_f;
                    in_f.u = t.input; out_f.u = res; exp_f.u = exp;
                    std::cout << "\n[Mismatch] Input: 0x" << std::hex << t.input << " (" << in_f.f << ")"
                              << "\n\tExpected: 0x" << exp << " (" << exp_f.f << ")"
                              << "\n\tGot:      0x" << res << " (" << out_f.f << ")" << std::dec << std::endl;
                }
            }
            checked_count++;

            // プログレス表示
            if (checked_count % update_interval == 0) {
                double progress = (double)checked_count / TARGET_PATTERNS * 100.0;
                std::cout << "\rProgress: " << std::fixed << std::setprecision(1) << progress << "% "
                          << "(" << checked_count << "/" << TARGET_PATTERNS << ")" 
                          << " Errors: " << error_count << std::flush;
            }
        }
    }

    std::cout << "\n\nSimulation Finished." << std::endl;
    std::cout << "Total Tests: " << checked_count << std::endl;
    std::cout << "Success:     " << success_count << std::endl;
    std::cout << "Errors:      " << error_count << std::endl;

    if (error_count == 0) {
        std::cout << "\nPASSED: All target patterns matched." << std::endl;
    } else {
        std::cout << "\nFAILED: " << error_count << " mismatches detected." << std::endl;
    }

    top->final();
    delete top;
    return 0;
}
