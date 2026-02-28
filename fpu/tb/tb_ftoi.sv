`timescale 1ns / 1ps
`default_nettype none

module tb_ftoi;

    // 信号定義
    logic        clk;
    logic        rst_n;
    logic [31:0] in_f;
    logic        input_valid;
    wire  [31:0] out_i;
    wire         out_valid;

    // 統�?
    int error_count = 0;
    int test_count = 0;

    // DUT
    ftoi dut (
        .clk(clk),
        .rst_n(rst_n),
        .in_f(in_f),
        .input_valid(input_valid),
        .out_i(out_i),
        .out_valid(out_valid)
    );

    // クロ�?ク
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // ========================================================================
    // ヘルパ�?�関数
    // ========================================================================
    function logic [31:0] r2b(shortreal r);
        return $shortrealtobits(r);
    endfunction

    function shortreal b2r(logic [31:0] b);
        return $bitstoshortreal(b);
    endfunction

    // 【修正】期�?値計算関数 (Round to Nearest Even を厳�?に実�?)
    function int calc_expected_even(logic [31:0] float_bits);
        logic sign;
        logic [7:0] exp;
        logic [22:0] mant;
        logic [31:0] mant_ext; // Hidden bit付き
        int shift;
        logic [31:0] int_part;
        logic guard, round, sticky; // stickyは簡易判�?
        logic lsb;
        logic round_up;
        
        sign = float_bits[31];
        exp  = float_bits[30:23];
        mant = float_bits[22:0];
        
        // 特殊ケース
        if (exp == 0 && mant == 0) return 0; // Zero
        
        // �?数が小さ�?場�? (絶対値 < 1)
        if (exp < 127) begin
            // 0.5未�? -> 0
            if (exp < 126) return 0;
            // 0.5 <= |x| < 1.0 のケース (�?: 0.5 -> 0, 0.6 -> 1)
            // ここでは簡易的に0.5ジャストな�?0(Even), それ以上な�?1とする
            // 厳�?には仮数部を見て判断するが�?�FADDの挙動と合わせるな�?
            // MagicNumber法と同じロジ�?クを�?�すのが確�?
            // ここではソフトウェア�?にMagicNumber法を模倣する
            return calc_via_magic_number(float_bits);
        end
        
        // �?数が大きい場�? (整数)
        if (exp >= 150) begin // 2^23以�?
            // 小数部なし�?�単純シフト
            shift = exp - 150;
            if (shift >= 31) return sign ? -2147483648 : 2147483647; // 飽�?(簡�?)
            
            // Mantissa(23) + Hidden(1) をシフト
            mant_ext = {1'b1, mant, 8'b0}; // 左詰�?
            // Exp=150のとき�?�Weightは 2^23...2^0
            // 実際の実�?に合わせてビット操�?
            // {1, M} は 24bit.
            // 実際は (1.M) * 2^(E-127).
            // = (1.M) * 2^(E-150 + 23)
            // = ({1,M}) * 2^(E-150).
            // E>=150なら左シフト
            int_part = {9'b0, 1'b1, mant} << (exp - 150);
            return sign ? (~int_part + 1) : int_part;
        end

        // 通常ケース (1 <= |x| < 2^23): 丸めが�?�?
        // Magic Number法を模倣するのが最もハードウェアに近い
        return calc_via_magic_number(float_bits);
    endfunction

    // Magic Number法�?�挙動をビ�?トレベルで再現して期�?値を作る
    function int calc_via_magic_number(logic [31:0] f_bits);
        logic [31:0] magic;
        shortreal f_val, m_val, res_real;
        logic [31:0] res_bits;
        logic [31:0] abs_int;
        logic sign;
        
        sign = f_bits[31];
        // 入力絶対値
        f_val = b2r({1'b0, f_bits[30:0]});
        
        // Magic Number (2^23)
        m_val = b2r(32'h4B000000); 
        
        // �?�? (FPUの丸めを利用するためにSystemVerilogのfloat演算を使�?)
        // SystemVerilogの演算もIEEE754準拠なら�?�数丸めされるはずだが�??
        // 念のためビット操作で確�?
        res_real = f_val + m_val;
        res_bits = r2b(res_real);
        
        // 仮数部を取り�?��?
        abs_int = {9'b0, res_bits[22:0]};
        
        return sign ? (~abs_int + 1) : abs_int;
    endfunction

    // ========================================================================
    // キュー
    // ========================================================================
    typedef struct {
        logic [31:0] input_bits;
        shortreal    input_real;
        int          expected_int;
        string       desc;
    } transaction_t;

    transaction_t expected_q[$];

    // ========================================================================
    // 入力タスク
    // ========================================================================
    task drive_float(input shortreal val, input string description = "Random");
        transaction_t trans;
        logic [31:0] bits;
        
        bits = r2b(val);
        
        @(posedge clk);
        in_f        <= bits;
        input_valid <= 1'b1;

        trans.input_bits   = bits;
        trans.input_real   = val;
        // 【修正】カスタ�?関数で期�?値を生�?
        trans.expected_int = calc_expected_even(bits); 
        trans.desc         = description;
        
        expected_q.push_back(trans);
        test_count++;
        
        @(posedge clk);
        input_valid <= 1'b0;
        in_f        <= 'x;
    endtask

    // 手動�?定用
    task drive_with_expect(input shortreal val, input int expected, input string description);
        transaction_t trans;
        
        @(posedge clk);
        in_f        <= r2b(val);
        input_valid <= 1'b1;

        trans.input_bits   = r2b(val);
        trans.input_real   = val;
        trans.expected_int = expected;
        trans.desc         = description;
        
        expected_q.push_back(trans);
        test_count++;
        
        @(posedge clk);
        input_valid <= 1'b0;
        in_f        <= 'x;
    endtask

    // ========================================================================
    // モニター
    // ========================================================================
    initial begin
        wait(rst_n == 0);
        wait(rst_n == 1);

        forever begin
            @(posedge clk);
            #1;

            if (out_valid) begin
                if (expected_q.size() == 0) begin
                    $error("Error: Unexpected output valid!");
                    error_count++;
                end else begin
                    transaction_t trans = expected_q.pop_front();
                    
                    if (out_i !== trans.expected_int) begin
                        $error("Mismatch [%s] at time %t", trans.desc, $time);
                        $display("  Input Float : %f (0x%h)", trans.input_real, trans.input_bits);
                        $display("  Expected Int: %0d (0x%h)", trans.expected_int, trans.expected_int);
                        $display("  Actual Int  : %0d (0x%h)", out_i, out_i);
                        error_count++;
                    end
                end
            end
        end
    end

    // ========================================================================
    // シナリオ
    // ========================================================================
    initial begin
        rst_n = 0;
        in_f = 0;
        input_valid = 0;
        
        repeat(5) @(posedge clk);
        rst_n = 1;
        repeat(5) @(posedge clk);

        $display("=== Start Simulation ===");

        // Test 1: Basic
        $display("Test 1: Basic Integers");
        drive_with_expect(0.0, 0, "Zero");
        drive_with_expect(1.0, 1, "One");
        drive_with_expect(-1.0, -1, "Neg One");
        drive_with_expect(100.0, 100, "100");

        // Test 2: Rounding
        $display("Test 2: Rounding (Nearest Even)");
        drive_with_expect(0.5, 0, "0.5 -> 0");
        drive_with_expect(1.5, 2, "1.5 -> 2");
        drive_with_expect(2.5, 2, "2.5 -> 2");
        drive_with_expect(3.5, 4, "3.5 -> 4");
        // あなた�?�エラーケースの再現
        drive_with_expect(1591356.5, 1591356, "1591356.5 -> 1591356 (Even)");

        // Test 3: Large
        $display("Test 3: Large Numbers");
        drive_with_expect(8388608.0, 8388608, "2^23");
        drive_with_expect(16777216.0, 16777216, "2^24");

        // Test 4: Random
        $display("Test 4: Random Inputs (1000 iter)");
        repeat(1000) begin
            logic [31:0] rnd = $urandom();
            shortreal r;
            // �?囲制�?: intに収まる�?囲
            if (rnd[30:23] < 158 && rnd[30:23] > 0) begin
                r = b2r(rnd);
                drive_float(r, "Random");
            end
        end

        repeat(20) @(posedge clk);

        if (error_count == 0) begin
            $display("=== TEST PASSED (%0d vectors) ===", test_count);
        end else begin
            $display("=== TEST FAILED (%0d errors) ===", error_count);
        end

        $finish;
    end

endmodule
`default_nettype wire