`timescale 1ns / 1ps
`default_nettype none

module tb_fsqrt;
    logic        clk;
    logic        rst_n;
    logic [31:0] input_a;
    logic        input_valid;
    wire  [31:0] result;
    wire         out_valid;

    fsqrt dut (.*);

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

    typedef struct {
        logic [31:0] a;
        logic [31:0] expected;
    } trans_t;
    trans_t q[$];
    
    int err = 0;

    task drive(input shortreal val);
        trans_t t;
        logic [31:0] bits;
        shortreal res_real;
        
        bits = r2b(val);
        // シミュレータのsqrtで期待値生成
        if (val < 0) res_real = 0.0/0.0; // NaN
        else         res_real = $sqrt(val);
        
        @(posedge clk);
        input_a <= bits;
        input_valid <= 1;
        
        t.a = bits;
        t.expected = r2b(res_real);
        q.push_back(t);
        
        @(posedge clk);
        input_valid <= 0;
    endtask

    initial begin
        wait(rst_n == 0); wait(rst_n == 1);
        forever begin
            @(posedge clk); #1;
            if (out_valid) begin
                trans_t t = q.pop_front();
                // 1ULPの誤差許容
                logic [31:0] diff;
                if (result > t.expected) diff = result - t.expected;
                else diff = t.expected - result;
                
                // NaNの比較は特殊だが、ここでは簡易的に除外するかビット一致を見る
                // $sqrt(-1)などはシミュレータによって挙動が違うので注意
                if (diff > 1 && !(t.expected[30:23] == 255)) begin
                    $error("Mismatch: In=%f, Exp=%f, Act=%f", b2r(t.a), b2r(t.expected), b2r(result));
                    err++;
                end
            end
        end
    end

    initial begin
        rst_n = 0; input_valid=0;
        repeat(5) @(posedge clk); rst_n = 1; repeat(5) @(posedge clk);
        
        drive(4.0);
        drive(2.0);
        drive(0.0);
        drive(100.0);
        drive(0.25);
        drive(3.14);
        drive(31.5);
        drive(5635);
        drive(120398102);
        drive(3.0); // irrationals
        
        repeat(20) @(posedge clk);
        if (err==0) $display("PASS");
        $finish;
    end
endmodule