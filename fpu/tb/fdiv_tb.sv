`timescale 1ns / 1ps

module tb_fdiv;

    // ============================================================
    // 1. 信号定義
    // ============================================================
    reg clk;
    reg rst_n;
    reg input_valid;
    reg [31:0] a, b;
    wire [31:0] result;
    wire out_valid;

    // �?スト設�?
    int TEST_COUNT = 10000; // �?ストする回数
    int ERROR_COUNT = 0;

    // DUT (Device Under Test) のインスタンス�?
    fdiv u_fdiv (
        .clk(clk),
        .rst_n(rst_n),
        .input_valid(input_valid),
        .input_a(a),
        .input_b(b),
        .result(result),
        .out_valid(out_valid)
    );

    // ============================================================
    // 2. クロ�?ク生�??
    // ============================================================
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100MHz (10ns period)
    end

    // ============================================================
    // 3. ゴール�?ンモ�?ル & スコアボ�?��? (期�?値管�?)
    // ============================================================
    
    // 期�?される結果を�?�納する構�??�?
    typedef struct {
        shortreal r_a;
        shortreal r_b;
        logic [31:0] expected_bits;
        string case_type; // �?バッグ用: "Random", "Zero", "NaN" etc.
    } expected_t;

    expected_t result_queue[$]; // キュー (FIFO)

    // ビット�?�をSystemVerilogの32bit実数(float)に変換する関数
    function shortreal bits2real(input [31:0] val);
        return $bitstoshortreal(val);
    endfunction

    // 実数をビ�?ト�?�に変換する関数
    function [31:0] real2bits(input shortreal val);
        return $shortrealtobits(val);
    endfunction

// --- 期待値計算タスク ---
    // PCのCPUを使って正しい割り算を行い、キューに積む
    task predict_and_push(input [31:0] in_a, input [31:0] in_b, input string c_type);
        expected_t exp;
        shortreal ra, rb, rres;
        logic [31:0] temp_bits_check; // 追加: 判定用の一時変数
        
        ra = bits2real(in_a);
        rb = bits2real(in_b);
        rres = ra / rb; // PC側での除算

        exp.r_a = ra;
        exp.r_b = rb;
        exp.expected_bits = real2bits(rres);
        exp.case_type = c_type;

        // Vivado XSIM対策: $isnanを使わずにビットパターンで判定
        temp_bits_check = $shortrealtobits(rres);
        
        // 指数部がAll 1 (FF) かつ 仮数部が0ではない = NaN
        if (temp_bits_check[30:23] == 8'hFF && temp_bits_check[22:0] != 0) begin
            exp.expected_bits = 32'h7FC00000; // Canonical NaNに統一
        end

        result_queue.push_back(exp);
    endtask

    // ============================================================
    // 4. 入力生�? (ラン�?�?ス�?ィミュラス)
    // ============================================================
    initial begin
        // 初期�?
        rst_n = 0;
        input_valid = 0;
        a = 0; b = 0;
        
        // リセ�?ト解除
        #100;
        @(posedge clk);
        rst_n = 1;
        #20;

        $display("=== Simulation Start: %0d cases ===", TEST_COUNT);

        repeat (TEST_COUNT) begin
            @(posedge clk);
            
            // ラン�?�?に「休み」を入れる (スループットテスト�?�ため常にValidにはしな�?)
            // if ($urandom_range(0, 10) > 8) begin
            //     input_valid <= 0;
            //     continue;
            // end
            
            input_valid <= 1;

            // --- ラン�?�?値の生�?�戦略 ---
            // randcaseを使って、特殊な値が�?�る確�?を操作す�?
            randcase
                80: begin // 通常のラン�?�? (正規化数など)
                    a <= $urandom();
                    b <= $urandom();
                    predict_and_push(a, b, "Random");
                end
                5: begin // ゼロ除�? (A / 0)
                    a <= $urandom();
                    b <= 32'h00000000; // +0.0
                    predict_and_push(a, 32'h00000000, "DivByZero");
                end
                5: begin // ゼロの割り�? (0 / B)
                    a <= 32'h00000000;
                    b <= $urandom();
                    predict_and_push(32'h00000000, b, "ZeroDiv");
                end
                5: begin // 無限大 (Inf) を含�?
                    a <= 32'h7F800000; // +Inf
                    b <= $urandom();
                    predict_and_push(32'h7F800000, b, "InfInput");
                end
                5: begin // NaN を含�?
                    a <= 32'h7FC00001; // SNaN
                    b <= $urandom();
                    predict_and_push(32'h7FC00001, b, "NaNInput");
                end
            endcase
        end

        input_valid <= 0;
        
        // パイプラインが空になるまで�?つ (適当に100サイクル)
        repeat(100) @(posedge clk);
        
        if (ERROR_COUNT == 0)
            $display("\n=== TEST PASSED: All %0d cases matched! ===\n", TEST_COUNT);
        else
            $display("\n=== TEST FAILED: %0d errors found. ===\n", ERROR_COUNT);
            
        $finish;
    end

    // ============================================================
    // 5. 出力モニタ & 自動チェ�?ク
    // ============================================================
    always @(posedge clk) begin
        if (out_valid) begin
            expected_t exp;
            logic [31:0] dut_res;
            logic [31:0] golden_res;
            int diff;

            if (result_queue.size() == 0) begin
                $error("Error: Unexpected output valid!");
                $stop;
            end

            exp = result_queue.pop_front(); // キューから取り出�?
            dut_res = result;
            golden_res = exp.expected_bits;

            // --- 比�?ロジ�?ク ---
            if (dut_res === golden_res) begin
                // 完�?��?致
                // $display("OK: %f / %f = %f", exp.r_a, exp.r_b, bits2real(dut_res));
            end else begin
                // 不�?致の場合�?�許容�?囲�?かチェ�?ク (ULP: Unit in Last Place)
                // 丸めモード�?�違いで、整数表現として ±1 の誤差は許容する
                
                // 符号違い or �?数違いは即アウ�? (NaN除�?)
                if (dut_res[31:23] !== golden_res[31:23]) begin
                    // NaN同士の比�?はビット�?致しな�?ことがある�?�で特別扱�?
                    if ((dut_res[30:23] == 8'hFF && dut_res[22:0] != 0) &&
                        (golden_res[30:23] == 8'hFF && golden_res[22:0] != 0)) begin
                        // どちらもNaNならOKとする
                    end else begin
                        report_error(exp, dut_res);
                    end
                end else begin
                    // 仮数部の差�?を計�?
                    diff = $signed({1'b0, dut_res[22:0]}) - $signed({1'b0, golden_res[22:0]});
                    if (diff < 0) diff = -diff;

                    // 誤差�?1以下なら�?�丸め誤差」として許容する
                    if (diff <= 1) begin
                        // $display("Warning: Rounding diff (ULP=1) accepted. DUT:%h Ref:%h", dut_res, golden_res);
                    end else begin
                        report_error(exp, dut_res);
                    end
                end
            end
        end
    end

    // エラー表示用タスク
    task report_error(input expected_t exp, input [31:0] dut_res);
        ERROR_COUNT++;
        $display("---------------------------------------------------");
        $display("ERROR at time %t: Case [%s]", $time, exp.case_type);
        $display("  Input A : %h (%f)", real2bits(exp.r_a), exp.r_a);
        $display("  Input B : %h (%f)", real2bits(exp.r_b), exp.r_b);
        $display("  Expected: %h (%f)", exp.expected_bits, bits2real(exp.expected_bits));
        $display("  Actual  : %h (%f)", dut_res, bits2real(dut_res));
        $display("---------------------------------------------------");
        // エラーが多すぎたら止める
        if (ERROR_COUNT > 10) $stop;
    endtask

endmodule