`default_nettype none

module top (
    input  wire logic        clk,
    input  wire logic        rst_n,
    input  wire logic [15:0] sw,
    output      logic [15:0] led
);

    // �?部レジスタ
    logic [31:0] reg_a, reg_b;
    logic [31:0] fmul_result;
    logic        fmul_out_valid;
    logic        fmul_input_valid;

    // スイ�?チ�?�力�?�割り当て用 (�?: sw[15]�?1なら上位�??0なら下位を保�?)
    // 実機での操作を想定した簡易的な入力インターフェース
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            reg_a <= 32'b0;
            reg_b <= 32'b0;
            fmul_input_valid <= 1'b0;
        end else begin
            // 特定�?�スイ�?チ操作でレジスタに値を保持する�?
            if (sw[15]) reg_a <= {sw[14:0], 17'b0}; // 簡易的な入�?
            if (sw[14]) reg_b <= {sw[14:0], 17'b0};
            fmul_input_valid <= 1'b1;
        end
    end

    // --- fmul インスタンス�? ---
    // 入力が非正規化数?��指数部0?���?�場合�?��??部で0として処�?されま�? 
    fmul u_fmul (
        .clk        (clk),
        .rst_n      (rst_n),
        .input_a    (reg_a),
        .input_b    (reg_b),
        .input_valid(fmul_input_valid),
        .result     (fmul_result),
        .out_valid  (fmul_out_valid)
    );

    // --- 出力選�? ---
    // LEDには計算結果の�?部を表示?���?: �?数部と符号ビットを中�?に見る?�?
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            led <= 16'b0;
        end else begin
            // 結果の[31:16]ビット（符号、指数、仮数の�?部?��をLEDに表示
            led <= fmul_result[31:16];
        end
    end

endmodule

`default_nettype wire
