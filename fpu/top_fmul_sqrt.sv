`default_nettype none

module top_fmul_sqrt (
    input  wire logic        clk,
    input  wire logic        rst_n,
    input  wire logic [31:0] a,           // fmul用の入力
    input  wire logic [31:0] b,           // fsqrt用の入力
    input  wire logic        input_valid, // 計算開始信号
    output      logic [31:0] result,      // a * sqrt(b)
    output      logic        out_valid    // 計算完了信号
);

    logic [31:0] sqrt_res;
    logic        sqrt_out_valid;

    // --- fsqrt インスタンス化 ---
    fsqrt u_fsqrt (
        .clk(clk),
        .rst_n(rst_n),
        .input_a(b),           // 入力bの平方根を求める
        .input_valid(input_valid),
        .result(sqrt_res),
        .out_valid(sqrt_out_valid)
    );

    // --- fmul インスタンス化 ---
    fmul u_fmul (
        .clk(clk),
        .rst_n(rst_n),
        .input_a(a),           // 入力a
        .input_b(sqrt_res),    // sqrt(b)の結果を入れる
        .input_valid(sqrt_out_valid), // sqrtが終わったらmulを開始
        .result(result),
        .out_valid(out_valid)
    );

endmodule
