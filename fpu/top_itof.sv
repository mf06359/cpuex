`default_nettype none

module top (
    input  wire logic        clk,
    input  wire logic        rst_n,
    input  wire logic [15:0] sw,   // 16ビットのスイッチ入力
    output      logic [15:0] led   // 16ビットのLED出力
);

    logic [31:0] in_i;
    logic [31:0] out_f;
    logic        out_valid;

    // スイッチの入力(16bit)を符号拡張して32bitの整数として入力する
    // 例: sw が 16'hFFFF (-1) の場合、in_i は 32'hFFFFFFFF (-1) になる
    assign in_i = {{16{sw[15]}}, sw};

    // itofモジュールのインスタンス化
    itof u_itof (
        .clk         (clk),
        .rst_n       (rst_n),
        .in_i        (in_i),
        .input_valid (1'b1),       // 常に有効
        .out_f       (out_f),
        .out_valid   (out_valid)
    );

    // 変換結果が最適化で消されないようLEDに出力
    // out_fの指数部(8bit)と仮数部の上位7bit、そして valid 信号を表示
    assign led = {out_valid, out_f[30:16]};

endmodule

`default_nettype wire
