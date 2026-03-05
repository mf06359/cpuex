module top (
    // DDR2
    output wire [12:0] ddr2_addr,
    output wire [2:0] ddr2_ba,
    output wire ddr2_cas_n,
    output wire [0:0] ddr2_ck_n,
    output wire [0:0] ddr2_ck_p,
    output wire [0:0] ddr2_cke,
    output wire ddr2_ras_n,
    output wire ddr2_we_n,
    inout  wire [15:0] ddr2_dq,
    inout  wire [1:0] ddr2_dqs_n,
    inout  wire [1:0] ddr2_dqs_p,
    output wire [0:0] ddr2_cs_n,
    output wire [1:0] ddr2_dm,
    output wire [0:0] ddr2_odt,
    
    // others
    input logic clk,
    input logic reset_n,

    output logic [15:0] led
);

    logic [31:0] input_data;
    logic [31:0] input_addr;
    logic [31:0] output_data;    

    (* mark_debug = "true" *) logic readtrigger;
    (* mark_debug = "true" *) logic writetrigger;
    (* mark_debug = "true" *) logic req_rdy;
    
    logic cpu_clk; 
    assign cpu_clk = clk;

    /*
     * ここにコアを追加する形で利用するとよいと思う
     */

    // =========================================================
    // キャッシュ ミスペナルティ測定用 ハードウェアカウンタ
    // =========================================================
    (* mark_debug = "true" *) logic [31:0] miss_penalty_counter;
    (* mark_debug = "true" *) logic [31:0] last_miss_penalty;
    (* mark_debug = "true" *) logic counting;

    always_ff @(posedge cpu_clk) begin
        if (!reset_n) begin
            miss_penalty_counter <= 32'd0;
            last_miss_penalty <= 32'd0;
            counting <= 1'b0;
        end else begin
            // リクエスト開始時、req_rdyが0（待機状態）ならカウントダウン開始
            if ((readtrigger || writetrigger) && !req_rdy) begin
                counting <= 1'b1;
                miss_penalty_counter <= 32'd1; // 1サイクル目
            end 
            // 待機中は毎クロック カウントアップ
            else if (counting && !req_rdy) begin
                miss_penalty_counter <= miss_penalty_counter + 32'd1;
            end 
            // データが返ってきた(req_rdyが1になった)ら結果を保存して停止
            else if (counting && req_rdy) begin
                counting <= 1'b0;
                last_miss_penalty <= miss_penalty_counter;
            end
        end
    end

    // 実機のLEDに直結して表示させたい場合は、moduleのポートに led を追加して以下のコメントアウトを外します
    assign led = last_miss_penalty[15:0];
    // =========================================================

    cachecontroller cachecontroller_inst (
        .ddr2_addr(ddr2_addr),
        .ddr2_ba(ddr2_ba),
        .ddr2_cas_n(ddr2_cas_n),
        .ddr2_ck_n(ddr2_ck_n),
        .ddr2_ck_p(ddr2_ck_p),
        .ddr2_cke(ddr2_cke),
        .ddr2_ras_n(ddr2_ras_n),
        .ddr2_we_n(ddr2_we_n),
        .ddr2_dq(ddr2_dq),
        .ddr2_dqs_n(ddr2_dqs_n),
        .ddr2_dqs_p(ddr2_dqs_p),
        .ddr2_cs_n(ddr2_cs_n),
        .ddr2_dm(ddr2_dm),
        .ddr2_odt(ddr2_odt),
        
        .clk(clk),
        .reset_n(reset_n),
        
        .writetrigger(writetrigger),
        .readtrigger(readtrigger),
        .input_addr(input_addr),
        .input_data(input_data),
        .req_rdy(req_rdy),
        .output_data(output_data),
        .cpu_clk_out() // top.sv内でcpu_clk = clkとしているため未接続でOK
    );

endmodule
