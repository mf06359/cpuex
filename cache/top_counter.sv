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

    // ボード上の16個のLEDに出力
    output logic [15:0] led
);

    logic [31:0] input_data;
    logic [31:0] input_addr;
    logic [31:0] output_data;    

    logic readtrigger;
    logic writetrigger;
    logic req_rdy;
    
    logic cpu_clk; 
    assign cpu_clk = clk;

    // =========================================================
    // 自動テストシーケンサー (Miss & Hit 連続測定)
    // =========================================================
    typedef enum logic [2:0] {
        INIT,
        REQ_MISS,   // 1回目のアクセス（必ずミスする）
        WAIT_MISS,
        REQ_HIT,    // 2回目のアクセス（必ずヒットする）
        WAIT_HIT,
        DONE
    } state_t;
    state_t test_state = INIT;

    logic [26:0] init_wait_timer;
    logic [31:0] current_counter;
    
    logic [11:0] miss_cycles; // ミスペナルティ保持用（下位12ビット）
    logic [3:0]  hit_cycles;  // ヒットペナルティ保持用（上位4ビット）

    always_ff @(posedge cpu_clk) begin
        if (!reset_n) begin
            test_state <= INIT;
            init_wait_timer <= '0;
            readtrigger <= 1'b0;
            writetrigger <= 1'b0;
            input_addr <= 32'h0;
            current_counter <= '0;
            miss_cycles <= '0;
            hit_cycles <= '0;
        end else begin
            case (test_state)
                INIT: begin
                    // DDR2メモリ初期化待ち (約0.5秒)
                    if (init_wait_timer == 27'd50_000_000) begin
                        test_state <= REQ_MISS;
                    end else begin
                        init_wait_timer <= init_wait_timer + 1;
                    end
                end
                
                // -------------------------------------
                // 1. キャッシュミスの測定
                // -------------------------------------
                REQ_MISS: begin
                    if (req_rdy) begin
                        input_addr <= 32'h0000_1000; // 測定用アドレス
                        readtrigger <= 1'b1;
                        current_counter <= 0;
                        test_state <= WAIT_MISS;
                    end
                end
                
                WAIT_MISS: begin
                    readtrigger <= 1'b0; // トリガーを1サイクルで落とす
                    
                    // 待機中（req_rdy=0）はカウントアップ
                    if (!req_rdy || readtrigger) begin
                        current_counter <= current_counter + 1;
                    end 
                    // データ到着（req_rdy=1）で結果を保存し、次のテストへ
                    else if (req_rdy && !readtrigger) begin
                        miss_cycles <= current_counter[11:0];
                        test_state <= REQ_HIT;
                    end
                end

                // -------------------------------------
                // 2. キャッシュヒットの測定
                // -------------------------------------
                REQ_HIT: begin
                    if (req_rdy) begin
                        input_addr <= 32'h0000_1000; // 全く同じアドレスに再アクセス
                        readtrigger <= 1'b1;
                        current_counter <= 0;
                        test_state <= WAIT_HIT;
                    end
                end
                
                WAIT_HIT: begin
                    readtrigger <= 1'b0;
                    
                    if (!req_rdy || readtrigger) begin
                        current_counter <= current_counter + 1;
                    end 
                    else if (req_rdy && !readtrigger) begin
                        hit_cycles <= current_counter[3:0];
                        test_state <= DONE;
                    end
                end
                
                DONE: begin
                    // 何もしない（LEDの数値を保持）
                end
            endcase
        end
    end

    // 測定結果の結合
    // 上位4ビット(15:12) = ヒットにかかったサイクル数
    // 下位12ビット(11:0) = ミスにかかったサイクル数
    assign led = {hit_cycles, miss_cycles};

    // =========================================================
    // キャッシュコントローラのインスタンス化
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
        .cpu_clk_out() 
    );

endmodule
