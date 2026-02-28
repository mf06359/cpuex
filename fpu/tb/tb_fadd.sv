`timescale 1ns / 1ps
`default_nettype none

module tb_fadd;

    // ========================================================================
    // 1. 信号とDUT定義
    // ========================================================================
    logic        clk;
    logic        rst_n;
    logic [31:0] input_a;
    logic [31:0] input_b;
    wire  [31:0] result;

    // パイプラインレイテンシ定義 (fadd.svは3段パイプライン)
    localparam int LATENCY = 3;

    // DUT (Device Under Test) のインスタンス化
    fadd dut (
        .clk(clk),
        .rst_n(rst_n),
        .input_a(input_a),
        .input_b(input_b),
        .result(result)
    );

    // クロック生成 (100MHz = 10ns)
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // ========================================================================
    // 2. 検証用ヘルパー関数と変数
    // ========================================================================
    
    // SystemVerilogのreal型とbit列の変換
    function logic [31:0] r2b(shortreal r);
        return $shortrealtobits(r);
    endfunction

    function shortreal b2r(logic [31:0] b);
        return $bitstoshortreal(b);
    endfunction

    // 期待値管理用構造体
    typedef struct {
        logic [31:0] a;
        logic [31:0] b;
        logic [31:0] expected;
    } transaction_t;

    transaction_t expected_queue[$]; // FIFOキュー
    int error_count = 0;
    int test_count = 0;

    // ========================================================================
    // 3. テスト入力タスク
    // ========================================================================
    task drive_input(input shortreal a_val, input shortreal b_val);
        logic [31:0] a_bits, b_bits;
        shortreal exp_val;
        transaction_t trans;

        a_bits = r2b(a_val);
        b_bits = r2b(b_val);
        
        // SystemVerilogのシミュレーション演算を「正解」とする
        exp_val = a_val + b_val; 

        // 入力をドライブ
        input_a <= a_bits;
        input_b <= b_bits;

        // 期待値をキューにプッシュ
        trans.a = a_bits;
        trans.b = b_bits;
        trans.expected = r2b(exp_val);
        expected_queue.push_back(trans);

        test_count++;
        @(posedge clk); // 1クロック進める
    endtask

    // ========================================================================
    // 4. モニタープロセス (出力チェック)
    // ========================================================================
    initial begin
        // リセット中は待機
        wait(rst_n == 0);
        wait(rst_n == 1);

        forever begin
            @(posedge clk);
            #1; // 出力が安定するのを少し待つ

            // 【修正】パイプライン段数(LATENCY=3)と同じだけデータが入ったらチェック開始
            // 以前は > LATENCY だったため、1サイクル遅れてチェックしていました
            if (expected_queue.size() >= LATENCY) begin
                transaction_t trans;
                logic [31:0] diff; // 差分計算用(符号なし整数として扱う)
                
                trans = expected_queue.pop_front(); // 最も古いデータを取り出す

                // 結果比較
                if (result !== trans.expected) begin
                    // ビット列を整数とみなして差分の絶対値を計算 ($abs回避策)
                    if (result > trans.expected) begin
                        diff = result - trans.expected;
                    end else begin
                        diff = trans.expected - result;
                    end

                    // 1ビット(1ULP)の誤差までは許容する (丸め誤差対策)
                    if (diff > 1) begin 
                        $error("Mismatch at Time %t", $time);
                        $display("  Input A : %f (0x%h)", b2r(trans.a), trans.a);
                        $display("  Input B : %f (0x%h)", b2r(trans.b), trans.b);
                        $display("  Expected: %f (0x%h)", b2r(trans.expected), trans.expected);
                        $display("  Actual  : %f (0x%h)", b2r(result), result);
                        $display("  Diff    : %0d ULP", diff);
                        error_count++;
                    end
                end
            end
        end
    end

    // ========================================================================
    // 5. メインテストシナリオ
    // ========================================================================
    initial begin
        // --- 初期化 ---
        rst_n = 0;
        input_a = 0;
        input_b = 0;
        
        repeat(10) @(posedge clk); // リセット期間
        rst_n = 1;
        repeat(2) @(posedge clk);  // 動作開始待ち
        
        $display("=== Start Simulation ===");

        // --- Test 1: 基本的な演算 ---
        $display("Test 1: Basic Operations");
        drive_input(1.0, 2.0);      // 1.0 + 2.0 = 3.0
        drive_input(1.5, 0.5);      // 1.5 + 0.5 = 2.0
        drive_input(100.0, -50.0);  // 100 - 50 = 50
        drive_input(-1.0, -1.0);    // -1 + -1 = -2
        
        // --- Test 2: ゼロに関するケース ---
        $display("Test 2: Zero Cases");
        drive_input(0.0, 0.0);
        drive_input(123.456, 0.0);
        drive_input(0.0, -987.654);

        // --- Test 3: 桁合わせと丸め ---
        $display("Test 3: Alignment & Rounding");
        drive_input(1.0, 1.0e-7); 
        drive_input(16777216.0, 1.0); // 2^24 + 1 (精度限界付近)
        
        // --- Test 4: 桁落ち (Cancellation) ---
        $display("Test 4: Cancellation");
        drive_input(1.000001, -1.0); 

        // --- Test 5: ランダムパターン (1000回) ---
        $display("Test 5: Random Pattern (1000 iterations)");
        repeat(1000) begin
            logic [31:0] rnd_a, rnd_b;
            shortreal r_a, r_b;
            
            rnd_a = $urandom();
            rnd_b = $urandom();
            
            // 指数部を適度な範囲(20~219)に制限
            rnd_a[30:23] = (rnd_a[30:23] % 200) + 20; 
            rnd_b[30:23] = (rnd_b[30:23] % 200) + 20;

            r_a = b2r(rnd_a);
            r_b = b2r(rnd_b);
            
            drive_input(r_a, r_b);
        end

        // --- パイプラインの掃き出し ---
        // 最後に投入したデータの結果が出るまでクロックを進めるため、ダミーデータを投入
        repeat(LATENCY + 2) drive_input(0.0, 0.0);

        // 少し待機してから終了
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