`timescale 1ns / 1ps

module tb_cache_random;

    // --- クロックとリセットの生成 ---
    logic clk;
    logic reset_n;

    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100MHz (10ns周期)
    end

    initial begin
        reset_n = 0;
        #20 reset_n = 1;
    end

    // --- インターフェースとDUTの接続 ---
    logic [31:0] input_data;
    logic [31:0] input_addr;
    logic readtrigger;
    logic writetrigger;
    logic req_rdy;
    logic [31:0] output_data;

    master_fifo fifo();

    cache dut (
        .fifo(fifo.master),
        .clk(clk),
        .input_data(input_data),
        .input_addr(input_addr),
        .readtrigger(readtrigger),
        .writetrigger(writetrigger),
        .reset_n(reset_n),
        .req_rdy(req_rdy),
        .output_data(output_data)
    );

    // --- 疑似メインメモリ (Mock Memory: 128bit幅) ---
    logic [127:0] mock_mem [logic [26:0]];

    // 疑似メモリ用のステートマシン
    enum logic [1:0] {MEM_IDLE, MEM_READ_DLY} mem_state = MEM_IDLE;
    logic [2:0] mem_delay;
    logic [26:0] mem_req_addr;

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            mem_state <= MEM_IDLE;
            fifo.rsp_en <= 1'b0;
            fifo.req_rdy <= 1'b1;
        end else begin
            fifo.rsp_en <= 1'b0;
            
            case (mem_state)
                MEM_IDLE: begin
                    if (fifo.req_en && fifo.req_rdy) begin
                        if (fifo.req.cmd == 1'b1) begin 
                            // READ (ラインフェッチ)
                            mem_req_addr <= fifo.req.addr;
                            mem_state <= MEM_READ_DLY;
                            mem_delay <= 3'd3;    
                            fifo.req_rdy <= 1'b0; 
                        end else begin 
                            // WRITE (ライトバック)
                            mock_mem[fifo.req.addr] <= fifo.req.data;
                        end
                    end
                end
                MEM_READ_DLY: begin
                    if (mem_delay == 0) begin
                        if (mock_mem.exists(mem_req_addr))
                            fifo.rsp.data <= mock_mem[mem_req_addr];
                        else
                            fifo.rsp.data <= 128'h0;
                        
                        fifo.rsp_en <= 1'b1;
                        mem_state <= MEM_IDLE;
                        fifo.req_rdy <= 1'b1;
                    end else begin
                        mem_delay <= mem_delay - 1;
                    end
                end
            endcase
        end
    end

    // --- ゴールデンモデル (真のメモリ状態を保持する参照用: 32bit幅) ---
    logic [31:0] golden_mem [logic [31:0]];

    // --- CPUアクセスを模倣するタスク ---
    task automatic read_cache(input logic [31:0] addr, output logic [31:0] data_out);
        @(posedge clk);
        input_addr <= addr;
        readtrigger <= 1'b1;
        
        @(posedge clk);
        readtrigger <= 1'b0;
        
        while (req_rdy === 1'b1) @(posedge clk);
        while (req_rdy === 1'b0) @(posedge clk);
        
        data_out = output_data;
    endtask

    task automatic write_cache(input logic [31:0] addr, input logic [31:0] data_in);
        @(posedge clk);
        input_addr <= addr;
        input_data <= data_in;
        writetrigger <= 1'b1;
        
        @(posedge clk);
        writetrigger <= 1'b0;
        
        while (req_rdy === 1'b1) @(posedge clk);
        while (req_rdy === 1'b0) @(posedge clk);
    endtask

    // --- ランダムテストシナリオ ---
    localparam NUM_TRANSACTIONS = 10000;
    
    // 【重要修正】アクセス範囲を 64KB に広げ、4Wayの追い出し(Eviction)を発生させる
    localparam ADDR_MASK = 32'h0000_FFFF; 
    
    int error_count = 0;
    int read_count = 0;
    int write_count = 0;

    initial begin
        logic [31:0] rand_addr;
        logic [31:0] rand_data;
        logic [31:0] read_val;
        logic [31:0] expected_val;
        logic is_write;

        input_addr = 0;
        input_data = 0;
        readtrigger = 0;
        writetrigger = 0;

        wait(reset_n == 1'b1);
        @(posedge clk);
        $display("--- RANDOM TEST START (%0d transactions) ---", NUM_TRANSACTIONS);

        for (int i = 0; i < NUM_TRANSACTIONS; i++) begin
            // 【重要修正】下位2ビットを切り捨て(~32'h3)、常にワードアライン(4の倍数)のアドレスを生成する
            rand_addr = ($urandom & ADDR_MASK) & ~32'h0000_0003; 
            rand_data = $urandom;
            is_write  = $urandom_range(0, 1); 

            if (is_write) begin
                write_count++;
                golden_mem[rand_addr] = rand_data; // 期待値を更新
                write_cache(rand_addr, rand_data);
            end else begin
                read_count++;
                read_cache(rand_addr, read_val);
                
                // ゴールデンモデルから期待値を取得
                if (golden_mem.exists(rand_addr)) expected_val = golden_mem[rand_addr];
                else expected_val = 32'h0;

                // スコアボードチェック
                if (read_val !== expected_val) begin
                    $display("[ERROR %0d] Iter %0d: Addr 0x%0h | Exp: 0x%0h, Got: 0x%0h", 
                           error_count, i, rand_addr, expected_val, read_val);
                    error_count++;
                end
            end

            // 1000回ごとに進捗を出力
            if ((i + 1) % 1000 == 0) begin
                $display("Progress: %0d / %0d transactions done...", i + 1, NUM_TRANSACTIONS);
            end
        end

        // --- 最終結果のレポート ---
        $display("========================================");
        $display("          RANDOM TEST COMPLETE          ");
        $display("========================================");
        $display("Total Reads : %0d", read_count);
        $display("Total Writes: %0d", write_count);
        $display("Total Errors: %0d", error_count);
        
        if (error_count == 0) begin
            $display(">> SUCCESS: 4-Way Set-Associative Cache is working perfectly!");
        end else begin
            $display(">> FAILED: Found data mismatches.");
        end
        $display("========================================");
        
        $finish;
    end

endmodule