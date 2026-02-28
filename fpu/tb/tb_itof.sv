`timescale 1ns / 1ps
`default_nettype none

module tb_itof;

    // ========================================================================
    // 信号定義
    // ========================================================================
    logic        clk;
    logic        rst_n;
    logic [31:0] in_i;
    logic        input_valid;
    wire  [31:0] out_f;
    wire         out_valid;

    // 統計用変数
    int error_count = 0;
    int test_count = 0;

    // ========================================================================
    // DUT (Device Under Test) インスタンス
    // ========================================================================
    itof dut (
        .clk        (clk),
        .rst_n      (rst_n),
        .in_i       (in_i),
        .input_valid(input_valid),
        .out_f      (out_f),
        .out_valid  (out_valid)
    );

    // ========================================================================
    // クロック生成 (10ns = 100MHz)
    // ========================================================================
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // ========================================================================
    // ヘルパー関数: ビット列と実数の変換表示用
    // ========================================================================
    function shortreal b2r(logic [31:0] b);
        return $bitstoshortreal(b);
    endfunction

    // ========================================================================
    // 期待値管理用キュー
    // ========================================================================
    typedef struct {
        int          input_int;
        logic [31:0] expected_bits;
    } transaction_t;

    transaction_t expected_q[$];

    // ========================================================================
    // タスク: 入力ドライブ
    // ========================================================================
    task drive_input(input int val);
        transaction_t trans;
        shortreal     real_val;

        // クロック同期
        @(posedge clk);
        
        // 入力セット
        in_i        <= val;
        input_valid <= 1'b1;

        // 期待値計算 (SystemVerilogのキャスト機能を使用)
        // 符号付き整数として解釈してから浮動小数点へ変換
        real_val = shortreal'(val); 

        // 期待値をキューに保存
        trans.input_int     = val;
        trans.expected_bits = $shortrealtobits(real_val);
        expected_q.push_back(trans);
        
        test_count++;
        
        // 次のサイクルのためにValidを下げる
        // (連続入力したい場合はここを調整するか、ループ内で呼ぶ)
        @(posedge clk);
        input_valid <= 1'b0;
        in_i        <= 'x; // デバッグ用に不定値にしておく
    endtask

    // ========================================================================
    // モニタープロセス (出力チェック)
    // ========================================================================
    initial begin
        wait(rst_n == 0);
        wait(rst_n == 1);

        forever begin
            @(posedge clk);
            #1; // 出力安定待ち

            if (out_valid) begin
                transaction_t trans;
                
                if (expected_q.size() == 0) begin
                    $error("Error: Unexpected output valid asserted!");
                    error_count++;
                end else begin
                    trans = expected_q.pop_front();

                    // ビット完全一致チェック
                    if (out_f !== trans.expected_bits) begin
                        $error("Mismatch at time %t", $time);
                        $display("  Input Int : %0d", trans.input_int);
                        $display("  Expected  : %f (0x%h)", b2r(trans.expected_bits), trans.expected_bits);
                        $display("  Actual    : %f (0x%h)", b2r(out_f), out_f);
                        error_count++;
                    end
                end
            end
        end
    end

    // ========================================================================
    // メインテストシーケンス
    // ========================================================================
    initial begin
        // 初期化
        rst_n = 0;
        in_i = 0;
        input_valid = 0;

        // リセット解除
        repeat(5) @(posedge clk);
        rst_n = 1;
        repeat(5) @(posedge clk);

        $display("=== Start Simulation ===");

        // --- 1. 基本的なケース ---
        $display("Test 1: Basic Small Integers");
        drive_input(0);
        drive_input(1);
        drive_input(-1);
        drive_input(100);
        drive_input(-100);
        
        // パイプラインの掃き出し待ち (数サイクル)
        repeat(5) @(posedge clk);

        // --- 2. 境界値 (Powers of 2) ---
        $display("Test 2: Power of 2 Boundaries");
        drive_input(32'd8388608);  // 2^23 (精度限界の境界)
        drive_input(32'd16777216); // 2^24
        drive_input(-32'd8388608);
        
        repeat(5) @(posedge clk);

        // --- 3. 丸めが発生するケース (Large Integers) ---
        // 2^24 + 1 は float(23bit mantissa) で表現できないため、偶数丸めされるはず
        $display("Test 3: Rounding Cases (|Int| > 2^24)");
        drive_input(16777216 + 1); // 16777217 -> 丸められて 16777216.0 になるはず
        drive_input(16777216 + 2); // 16777218 -> 表現可能 16777218.0
        drive_input(16777216 + 3); // 16777219 -> 丸められて 16777220.0 になるはず
        
        repeat(5) @(posedge clk);

        // --- 4. 最大・最小整数 ---
        $display("Test 4: Max/Min Integers");
        drive_input(2147483647);        // INT_MAX
        drive_input(-2147483648);       // INT_MIN (0x80000000) - 特殊なケース
        
        repeat(5) @(posedge clk);

        // --- 5. パイプライン連続入力テスト (Random) ---
        $display("Test 5: Pipelined Random Inputs (100 iter)");
        // Validを下げずに連続で入れる
        fork
            begin
                repeat(100) begin
                    transaction_t trans;
                    int val;
                    shortreal real_val;

                    val = $urandom(); // ランダムな32bit整数
                    
                    @(posedge clk);
                    in_i <= val;
                    input_valid <= 1'b1;

                    // 期待値保存
                    real_val = shortreal'(val);
                    trans.input_int = val;
                    trans.expected_bits = $shortrealtobits(real_val);
                    expected_q.push_back(trans);
                    
                    test_count++;
                end
                // 入力終了
                @(posedge clk);
                input_valid <= 1'b0;
            end
        join

        // 全ての結果が出るまで待つ
        wait(expected_q.size() == 0);
        repeat(10) @(posedge clk);

        // --- 結果表示 ---
        if (error_count == 0) begin
            $display("=== TEST PASSED (%0d vectors checked) ===", test_count);
        end else begin
            $display("=== TEST FAILED (%0d errors found) ===", error_count);
        end

        $finish;
    end

endmodule
`default_nettype wire