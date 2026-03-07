`default_nettype none

module top (
    input  wire logic        clk,
    input  wire logic        rst_n,
    input  wire logic [15:0] sw,   // 16ビットのスイッチ入力
    output      logic [15:0] led   // 16ビットのLED出力
);

    logic [31:0] input_a;
    logic [31:0] input_b;
    logic [31:0] result;
    logic        out_valid;

    // スイッチの値を元に、擬似的に2つの異なる浮動小数点数を作成する
    // input_a: スイッチの値をそのまま上位16bitに配置
    assign input_a = {sw, 16'h0000};
    
    // input_b: スイッチの値を反転させて少し異なる値にする（最適化防止）
    // 例として、符号を反転させたり指数部をずらしたりする
    assign input_b = {~sw[15], sw[14:0], 16'h1000};

    // faddモジュールのインスタンス化
    fadd u_fadd (
        .clk         (clk),
        .rst_n       (rst_n),
        .input_a     (input_a),
        .input_b     (input_b),
        .input_valid (1'b1),       // 常に有効
        .result      (result),
        .out_valid   (out_valid)
    );

    // 加算結果をLEDに接続（最適化による回路削除を防止）
    // 指数部(8bit)と仮数部の上位7bit、そして valid 信号を表示
    assign led = {out_valid, result[30:16]};

endmodule

`default_nettype wire`default_nettype none

module top (
    input  wire logic        clk,
    input  wire logic        rst_n,
    input  wire logic [15:0] sw,   // 16ビットのスイッチ入力
    output      logic [15:0] led   // 16ビットのLED出力
);

    logic [31:0] input_a;
    logic [31:0] input_b;
    logic [31:0] result;
    logic        out_valid;

    // スイッチの値を元に、擬似的に2つの異なる浮動小数点数を作成する
    // input_a: スイッチの値をそのまま上位16bitに配置
    assign input_a = {sw, 16'h0000};
    
    // input_b: スイッチの値を反転させて少し異なる値にする（最適化防止）
    // 例として、符号を反転させたり指数部をずらしたりする
    assign input_b = {~sw[15], sw[14:0], 16'h1000};

    // faddモジュールのインスタンス化
    fadd u_fadd (
        .clk         (clk),
        .rst_n       (rst_n),
        .input_a     (input_a),
        .input_b     (input_b),
        .input_valid (1'b1),       // 常に有効
        .result      (result),
        .out_valid   (out_valid)
    );

    // 加算結果をLEDに接続（最適化による回路削除を防止）
    // 指数部(8bit)と仮数部の上位7bit、そして valid 信号を表示
    assign led = {out_valid, result[30:16]};

endmodule

`default_nettype wire
