module fmul_sqrt (
    input  logic [31:0] a,    // fmulの入力1
    input  logic [31:0] b,    // fsqrtの入力
    output logic [31:0] y     // 最終結果: a * sqrt(b)
);

    logic [31:0] sqrt_out;

    // fsqrtのインスタンス化
    fsqrt u_fsqrt (
        .x(b),
        .y(sqrt_out)
    );

    // fmulのインスタンス化
    fmul u_fmul (
        .src1(a),
        .src2(sqrt_out),
        .y(y)
    );

endmodule
