`default_nettype none

module top_fsqrt (
    input  wire logic clk,       // 100MHz クロック
    input  wire logic [15:0] sw, // 16個のスイッチ入力
    output logic[15:0] led             // 1個のLED出力
);

    // ==========================================
    // 1. パワーオンリセットの生成
    // リセットボタンがXDCで未定義のため、起動直後に
    // 自動でリセットを解除するシーケンスを生成します
    // ==========================================
    logic [7:0] rst_cnt = 8'b0;
    logic rst_n;
    
    always_ff @(posedge clk) begin
        if (rst_cnt != 8'hFF) begin
            rst_cnt <= rst_cnt + 8'd1;
        end
    end
    assign rst_n = (rst_cnt == 8'hFF);

    // ==========================================
    // 2. 入力データの生成（ピン数不足への対応）
    // 16bitのスイッチ入力を毎クロックシフトし、
    // 32bitの仮想的な浮動小数点入力を作成します
    // ==========================================
    logic [31:0] input_a_reg;
    logic input_valid_reg;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            input_a_reg <= 32'b0;
            input_valid_reg <= 1'b0;
        end else begin
            // スイッチの値を下位に入れてシフト
            input_a_reg <= {input_a_reg[15:0], sw};
            // スイッチのXORをとってvalid信号をトグルさせる
            input_valid_reg <= ^sw;
        end
    end

    // ==========================================
    // 3. fsqrt モジュールのインスタンス化
    // ==========================================
    logic [31:0] result;
    logic out_valid;

    fsqrt u_fsqrt (
        .clk(clk),
        .rst_n(rst_n),
        .input_a(input_a_reg),
        .input_valid(input_valid_reg),
        .result(result),
        .out_valid(out_valid)
    );

    // ==========================================
    // 4. 出力データの縮約（最適化防止）
    // 計算結果の32bitすべてを利用して1bitのLEDを
    // 光らせることで、回路の削除（Optimize out）を防ぎます
    // ==========================================
    logic led_out;
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            led_out <= 1'b0;
        end else if (out_valid) begin
            // 32bit結果のすべてのビットをXORする（縮退XOR）
            led_out <= ^result; 
        end
    end

    assign led = {led_out, 15'b000000000000000};

endmodule
