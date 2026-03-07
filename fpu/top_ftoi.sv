`default_nettype none

module top (
    input  wire logic        clk,
    input  wire logic        rst_n,
    input  wire logic [15:0] sw,   // 追加: 16ビットのスイッチ入力
    output      logic [15:0] led   // 追加: 16ビットのLED出力
);

    logic [31:0] in_f;
    logic [31:0] out_i;
    logic        out_valid;

    // スイッチの入力を浮動小数点数（32bit）の上位16bitに接続。下位16bitは0埋め。
    // （これにより、swの操作で符号ビットや指数部を擬似的に変化させられます）
    assign in_f = {sw, 16'h0000};

    // ftoiモジュールのインスタンス化
    ftoi u_ftoi (
        .clk         (clk),
        .rst_n       (rst_n),
        .in_f        (in_f),
        .input_valid (1'b1),       // 常に有効としておく
        .out_i       (out_i),
        .out_valid   (out_valid)
    );

    // 変換結果が最適化で消されないようLEDに出力
    // LED[14:0] に整数変換結果の下位15bitを、LED[15] に out_valid を接続
    assign led = {out_valid, out_i[14:0]};

endmodule

`default_nettype wire
