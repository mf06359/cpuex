`timescale 1ns / 1ps
`default_nettype none

module tb_fmul;
    logic        clk;
    logic        rst_n;
    logic [31:0] input_a, input_b;
    logic        input_valid;
    wire  [31:0] result;
    wire         out_valid;

    fmul dut (.*);

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    function logic [31:0] r2b(shortreal r);
        return $shortrealtobits(r);
    endfunction
    function shortreal b2r(logic [31:0] b);
        return $bitstoshortreal(b);
    endfunction

    // 期待値キュー
    typedef struct {
        logic [31:0] a, b;
        logic [31:0] expected;
    } trans_t;
    trans_t q[$];
    int err = 0;

    // 入力タスク (丸め誤差を考慮してビット経由で期待値生成)
    task drive(input shortreal fa, input shortreal fb);
        trans_t t;
        shortreal res_real, a_32, b_32;
        
        // 32bit精度の入力を作る
        t.a = r2b(fa);
        t.b = r2b(fb);
        a_32 = b2r(t.a);
        b_32 = b2r(t.b);
        
        res_real = a_32 * b_32;
        t.expected = r2b(res_real);
        
        @(posedge clk);
        input_a <= t.a;
        input_b <= t.b;
        input_valid <= 1;
        q.push_back(t);
        
        @(posedge clk);
        input_valid <= 0;
    endtask

    // モニター
    initial begin
        wait(rst_n == 0); wait(rst_n == 1);
        forever begin
            @(posedge clk); #1;
            if (out_valid) begin
                trans_t t = q.pop_front();
                logic [31:0] diff;
                
                if (result > t.expected) diff = result - t.expected;
                else                     diff = t.expected - result;
                
                // 1ULPの誤差許容 (丸め等の微妙な差異)
                if (diff > 1) begin
                    $error("Mismatch: %f * %f = %f (Exp: %f)", 
                           b2r(t.a), b2r(t.b), b2r(result), b2r(t.expected));
                    err++;
                end
            end
        end
    end

    initial begin
        rst_n = 0; input_valid = 0;
        repeat(5) @(posedge clk); rst_n = 1; repeat(5) @(posedge clk);
        
        // Basic
        drive(2.0, 3.0);   // 6.0
        drive(1.5, 1.5);   // 2.25
        drive(-2.0, 4.0);  // -8.0
        drive(0.0, 5.0);   // 0.0
        
        // Overflow / Large
        drive(1.0e30, 1.0e8); // 1.0e38 (Limit)
        
        // Rounding
        drive(1.0, 1.0 + 1.0e-7); // 精度限界付近
        
        // Random
        repeat(100) begin
            shortreal r1, r2;
            logic [31:0] b1, b2;
            b1 = $urandom(); b2 = $urandom();
            // 指数部を適度な範囲に制限 (NaN/Inf回避)
            b1[30:23] = (b1[30:23] % 200) + 20;
            b2[30:23] = (b2[30:23] % 200) + 20;
            drive(b2r(b1), b2r(b2));
        end
        
        repeat(10) @(posedge clk);
        if (err==0) $display("PASS");
        $finish;
    end
endmodule