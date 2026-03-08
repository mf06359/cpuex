module cache (
    master_fifo.master fifo,
    input logic clk,
    input logic [31:0] input_data, 
    input logic [31:0] input_addr, 
    input logic readtrigger,
    input logic writetrigger,
    input logic reset_n,
    output logic req_rdy,
    output logic [31:0] output_data
);
    assign fifo.clk = clk;
    assign fifo.rsp_rdy = ((state == WAIT_READ_RSP_FOR_WRITE) || (state == WAIT_READ_RSP_FOR_READ)) && fifo.rsp_en;

    localparam DATA_WIDTH = 32;
    localparam BYTE_WIDTH = 8;
    localparam WORD_SIZE = 4;
    localparam CACHE_DEPTH = 256;
    localparam LINE_SIZE = 128;
    localparam TAG_WIDTH = 20;
    localparam INDEX_WIDTH = 8;
    localparam OFFSET_WIDTH = 4;
    localparam NUM_WAYS = 4;

    (* ram_style = "block" *) reg [LINE_SIZE-1:0] cache_memory_w0 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [LINE_SIZE-1:0] cache_memory_w1 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [LINE_SIZE-1:0] cache_memory_w2 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [LINE_SIZE-1:0] cache_memory_w3 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [TAG_WIDTH-1:0] cache_tag_w0 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [TAG_WIDTH-1:0] cache_tag_w1 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [TAG_WIDTH-1:0] cache_tag_w2 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [TAG_WIDTH-1:0] cache_tag_w3 [CACHE_DEPTH-1:0];
    
    logic [0:0] valid_bits[CACHE_DEPTH-1:0][NUM_WAYS-1:0];
    logic [0:0] dirty_bits[CACHE_DEPTH-1:0][NUM_WAYS-1:0];
    logic [2:0] plru_bits[CACHE_DEPTH-1:0];

    reg [TAG_WIDTH-1:0] tag_reg;
    reg [INDEX_WIDTH-1:0] index_reg;
    reg [OFFSET_WIDTH-1:0] offset_reg;

    logic [31:0] output_data_reg;
    assign output_data = output_data_reg;

    // ==========================================
    // 組み合わせ回路ブロック (CALC_HIT で評価される)
    // ==========================================
    logic [TAG_WIDTH-1:0] cache_tag_reg[NUM_WAYS-1:0];
    logic valid_bit_reg[NUM_WAYS-1:0];
    logic dirty_bit_reg[NUM_WAYS-1:0];
    logic [127:0] cache_data_reg[NUM_WAYS-1:0];
    logic [31:0] input_data_reg;
    logic [1:0]  oldest_way_reg;
    logic [2:0]  plru_bit_reg;
    
    // 1. Hit 判定
    wire hit0_comb = valid_bit_reg[0] && (cache_tag_reg[0] == tag_reg);
    wire hit1_comb = valid_bit_reg[1] && (cache_tag_reg[1] == tag_reg);
    wire hit2_comb = valid_bit_reg[2] && (cache_tag_reg[2] == tag_reg);
    wire hit3_comb = valid_bit_reg[3] && (cache_tag_reg[3] == tag_reg);
    wire is_hit_comb = hit0_comb | hit1_comb | hit2_comb | hit3_comb;

    // 2. Hit データ選択
    logic [127:0] hit_data_line_comb;
    always_comb begin
        case (1'b1)
            hit0_comb: hit_data_line_comb = cache_data_reg[0];
            hit1_comb: hit_data_line_comb = cache_data_reg[1];
            hit2_comb: hit_data_line_comb = cache_data_reg[2];
            hit3_comb: hit_data_line_comb = cache_data_reg[3];
            default:   hit_data_line_comb = 128'b0;
        endcase
    end

    // 3. 読み出し用 Word 抽出
    logic [31:0] hit_word_comb;
    always_comb begin
        case (offset_reg[3:2])
            2'b00: hit_word_comb = hit_data_line_comb[31:0];
            2'b01: hit_word_comb = hit_data_line_comb[63:32];
            2'b10: hit_word_comb = hit_data_line_comb[95:64];
            2'b11: hit_word_comb = hit_data_line_comb[127:96];
        endcase
    end

    // 4. 書き込み用 128bit 合成 (スプライス)
    logic [127:0] write_data_line_comb;
    always_comb begin
        write_data_line_comb = hit_data_line_comb;
        case (offset_reg[3:2])
            2'b00: write_data_line_comb[31:0]   = input_data_reg;
            2'b01: write_data_line_comb[63:32]  = input_data_reg;
            2'b10: write_data_line_comb[95:64]  = input_data_reg;
            2'b11: write_data_line_comb[127:96] = input_data_reg;
        endcase
    end

    // 5. 追い出し先 (Victim) データ選択
    logic [TAG_WIDTH-1:0] victim_tag_comb;
    logic [127:0]         victim_data_comb;
    logic                 victim_dirty_comb;
    logic                 victim_valid_comb;
    always_comb begin
        case (oldest_way_reg)
            2'd0: begin
                victim_tag_comb   = cache_tag_reg[0];
                victim_data_comb  = cache_data_reg[0];
                victim_dirty_comb = dirty_bit_reg[0];
                victim_valid_comb = valid_bit_reg[0];
            end
            2'd1: begin
                victim_tag_comb   = cache_tag_reg[1];
                victim_data_comb  = cache_data_reg[1];
                victim_dirty_comb = dirty_bit_reg[1];
                victim_valid_comb = valid_bit_reg[1];
            end
            2'd2: begin
                victim_tag_comb   = cache_tag_reg[2];
                victim_data_comb  = cache_data_reg[2];
                victim_dirty_comb = dirty_bit_reg[2];
                victim_valid_comb = valid_bit_reg[2];
            end
            2'd3: begin
                victim_tag_comb   = cache_tag_reg[3];
                victim_data_comb  = cache_data_reg[3];
                victim_dirty_comb = dirty_bit_reg[3];
                victim_valid_comb = valid_bit_reg[3];
            end
        endcase
    end

    // 6. 次の PLRU 計算
    logic [2:0] next_plru_comb;
    always_comb begin
        if (hit0_comb) next_plru_comb = {2'b11, plru_bit_reg[0]};
        else if (hit1_comb) next_plru_comb = {2'b10, plru_bit_reg[0]};
        else if (hit2_comb) next_plru_comb = {1'b0, plru_bit_reg[1], 1'b1};
        else if (hit3_comb) next_plru_comb = {1'b0, plru_bit_reg[1], 1'b0};
        else next_plru_comb = plru_bit_reg;
    end
    // ==========================================

    initial begin
        for (int i = 0; i < CACHE_DEPTH; i++) begin
            cache_memory_w0[i] = 128'b0;
            cache_memory_w1[i] = 128'b0;
            cache_memory_w2[i] = 128'b0;
            cache_memory_w3[i] = 128'b0;
            cache_tag_w0[i] = 20'b0;
            cache_tag_w1[i] = 20'b0;
            cache_tag_w2[i] = 20'b0;
            cache_tag_w3[i] = 20'b0;
        end
        for (int i = 0; i < CACHE_DEPTH; i++) begin
            for (int j = 0; j < NUM_WAYS; j++) begin
                valid_bits[i][j] = 1'b0;
                dirty_bits[i][j] = 1'b0;
                plru_bits[i][j] = 3'b000;
            end
        end
    end

    // ★ ステートに CALC_HIT を追加
    localparam IDLE = 5'b00000;
    localparam READ_MEM = 5'b00001; 
    localparam CALC_HIT = 5'b00011; // ←追加! パイプライン3段目
    localparam COMPI = 5'b00010;
    localparam WAIT_READ_LINE_FOR_READ = 5'b00100;
    localparam WAIT_READ_LINE_FOR_WRITE = 5'b00101;
    localparam WAIT_WRITE_BACK_FOR_READ = 5'b01000;
    localparam WAIT_WRITE_BACK_FOR_WRITE = 5'b01001;
    localparam WAIT_READ_RSP_FOR_WRITE = 5'b10001;
    localparam WAIT_READ_RSP_FOR_READ = 5'b10000;
    localparam WAIT_BETWEEN_REQS_FOR_READ = 5'b11000;
    localparam WAIT_BETWEEN_REQS_FOR_WRITE = 5'b11001;
    localparam DONE = 5'b11111;

    (* fsm_encoding = "one_hot", extract_enable = "no" *) reg [4:0] state = IDLE;
    logic [31:0] input_addr_reg;
    logic read_req_reg;
    logic write_req_reg;

    reg readtrigger_sync;
    reg writetrigger_sync;
    reg [31:0] input_addr_sync;
    reg [31:0] input_data_sync;

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            readtrigger_sync  <= 1'b0;
            writetrigger_sync <= 1'b0;
            input_addr_sync   <= 32'b0;
            input_data_sync   <= 32'b0;
        end else begin
            readtrigger_sync  <= readtrigger;
            writetrigger_sync <= writetrigger;
            input_addr_sync   <= input_addr;
            input_data_sync   <= input_data;
        end
    end

    // --- パイプラインレジスタ (CALC_HIT から COMPI へ渡す) ---
    logic [3:0] hit_flags_reg;
    logic is_hit_reg;
    logic [31:0] hit_word_reg;
    logic [127:0] write_data_line_reg;
    logic [TAG_WIDTH-1:0] victim_tag_reg;
    logic [127:0] victim_data_reg;
    logic victim_dirty_reg;
    logic victim_valid_reg;
    logic [2:0] next_plru_reg;

    assign req_rdy = (state == DONE) || (state == IDLE && !readtrigger_sync && !writetrigger_sync);

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            state <= IDLE;
            fifo.req_en <= 1'b0;
            output_data_reg <= 32'b0;
            read_req_reg <= 1'b0;
            write_req_reg <= 1'b0;
            oldest_way_reg <= 2'b0;

            for (int i = 0; i < NUM_WAYS; i++) begin
                plru_bits[i] <= 3'b000;
                for (int j = 0; j < NUM_WAYS; j++) begin
                    valid_bits[i][j] <= 1'b0;
                    dirty_bits[i][j] <= 1'b0;
                end
            end
        end else begin
            case (state)
                IDLE: begin
                    if (readtrigger_sync || writetrigger_sync) begin
                     
                        read_req_reg  <= readtrigger_sync;
                        write_req_reg <= writetrigger_sync;
                        
                        fifo.req_en <= 1'b0;

                        tag_reg <= input_addr_sync[31:12];
                        index_reg <= input_addr_sync[11:4];
                        offset_reg <= input_addr_sync[3:0];
                        
                        input_addr_reg <= input_addr_sync;
                        input_data_reg <= input_data_sync;
                        
                        state <= READ_MEM;
                    end
                end

                READ_MEM: begin
                    cache_tag_reg[0] <= cache_tag_w0[index_reg];
                    cache_tag_reg[1] <= cache_tag_w1[index_reg];
                    cache_tag_reg[2] <= cache_tag_w2[index_reg];
                    cache_tag_reg[3] <= cache_tag_w3[index_reg];

                    cache_data_reg[0] <= cache_memory_w0[index_reg];
                    cache_data_reg[1] <= cache_memory_w1[index_reg];
                    cache_data_reg[2] <= cache_memory_w2[index_reg];  
                    cache_data_reg[3] <= cache_memory_w3[index_reg]; 

                    dirty_bit_reg[0] <= dirty_bits[index_reg][0];
                    dirty_bit_reg[1] <= dirty_bits[index_reg][1];
                    dirty_bit_reg[2] <= dirty_bits[index_reg][2];
                    dirty_bit_reg[3] <= dirty_bits[index_reg][3];
                    
                    valid_bit_reg[0] <= valid_bits[index_reg][0];
                    valid_bit_reg[1] <= valid_bits[index_reg][1];
                    valid_bit_reg[2] <= valid_bits[index_reg][2];
                    valid_bit_reg[3] <= valid_bits[index_reg][3];

                    plru_bit_reg <= plru_bits[index_reg];

                    if (!valid_bits[index_reg][0]) oldest_way_reg <= 2'd0;
                    else if (!valid_bits[index_reg][1]) oldest_way_reg <= 2'd1;
                    else if (!valid_bits[index_reg][2]) oldest_way_reg <= 2'd2;
                    else if (!valid_bits[index_reg][3]) oldest_way_reg <= 2'd3;
                    else oldest_way_reg <= plru_bits[index_reg][2] ? 
                                          (plru_bits[index_reg][0] ? 2'd3 : 2'd2) : 
                                          (plru_bits[index_reg][1] ? 2'd1 : 2'd0);

                    state <= CALC_HIT; // 次は計算フェーズへ
                end

                // [パイプライン段2]: 組み合わせ回路の計算結果をレジスタで受け取る
                CALC_HIT: begin
                    hit_flags_reg <= {hit3_comb, hit2_comb, hit1_comb, hit0_comb};
                    is_hit_reg <= is_hit_comb;
                    hit_word_reg <= hit_word_comb;
                    write_data_line_reg <= write_data_line_comb;
                    
                    victim_tag_reg <= victim_tag_comb;
                    victim_data_reg <= victim_data_comb;
                    victim_dirty_reg <= victim_dirty_comb;
                    victim_valid_reg <= victim_valid_comb;
                    
                    next_plru_reg <= next_plru_comb;
                    
                    state <= COMPI;
                end

                // [パイプライン段3]: レジスタの値をそのままBRAMやFIFOに投げるだけ！
                COMPI: begin
                    if (is_hit_reg) begin
                        // --- HIT の処理 ---
                        if (read_req_reg) begin
                            output_data_reg <= hit_word_reg;
                        end else if (write_req_reg) begin
                            if (hit_flags_reg[0]) cache_memory_w0[index_reg] <= write_data_line_reg;
                            if (hit_flags_reg[1]) cache_memory_w1[index_reg] <= write_data_line_reg;
                            if (hit_flags_reg[2]) cache_memory_w2[index_reg] <= write_data_line_reg;
                            if (hit_flags_reg[3]) cache_memory_w3[index_reg] <= write_data_line_reg;
                            
                            if (hit_flags_reg[0]) dirty_bits[index_reg][0] <= 1'b1;
                            if (hit_flags_reg[1]) dirty_bits[index_reg][1] <= 1'b1;
                            if (hit_flags_reg[2]) dirty_bits[index_reg][2] <= 1'b1;
                            if (hit_flags_reg[3]) dirty_bits[index_reg][3] <= 1'b1;
                            
                            output_data_reg <= 32'b0;
                        end
                        plru_bits[index_reg] <= next_plru_reg;
                        state <= DONE;
                    end else begin
                        // --- MISS の処理 ---
                        if (victim_valid_reg && victim_dirty_reg) begin
                            // Write Back
                            fifo.req.cmd <= 1'b0; 
                            fifo.req.addr <= {victim_tag_reg, index_reg, 4'b0000};
                            fifo.req.data <= victim_data_reg; // レジスタ化済み！
                            fifo.req_en <= 1'b1;
                            state <= write_req_reg ? WAIT_WRITE_BACK_FOR_WRITE : WAIT_WRITE_BACK_FOR_READ;
                        end else begin
                            // Allocate (Read)
                            fifo.req.cmd <= 1'b1;
                            fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                            fifo.req.data <= 128'b0;
                            fifo.req_en <= 1'b1;
                            state <= write_req_reg ? WAIT_READ_LINE_FOR_WRITE : WAIT_READ_LINE_FOR_READ;
                        end
                    end
                end

                WAIT_WRITE_BACK_FOR_READ: begin
                    if (fifo.req_rdy) begin
                        fifo.req_en <= 1'b0;
                        state <= WAIT_BETWEEN_REQS_FOR_READ;
                    end
                end

                WAIT_BETWEEN_REQS_FOR_READ: begin 
                    fifo.req.cmd <= 1'b1; // read
                    fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                    fifo.req.data <= 128'b0;
                    fifo.req_en <= 1'b1;
                    state <= WAIT_READ_LINE_FOR_READ;
                end

                WAIT_WRITE_BACK_FOR_WRITE: begin
                    if (fifo.req_rdy) begin
                        fifo.req_en <= 1'b0;
                        state <= WAIT_BETWEEN_REQS_FOR_WRITE;
                    end
                end

                WAIT_BETWEEN_REQS_FOR_WRITE: begin 
                    fifo.req.cmd <= 1'b1; // read
                    fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                    fifo.req.data <= 128'b0;
                    fifo.req_en <= 1'b1;
                    state <= WAIT_READ_LINE_FOR_WRITE;
                end

                WAIT_READ_LINE_FOR_WRITE: begin
                    if (fifo.req_rdy) begin
                        fifo.req_en <= 1'b0;
                        state <= WAIT_READ_RSP_FOR_WRITE;
                    end
                end

                WAIT_READ_LINE_FOR_READ: begin
                    if (fifo.req_rdy) begin
                        fifo.req_en <= 1'b0;
                        state <= WAIT_READ_RSP_FOR_READ;
                    end
                end

                WAIT_READ_RSP_FOR_WRITE: begin
                    if (fifo.rsp_en) begin
                        logic [127:0] rsp_write_data;
                        rsp_write_data = fifo.rsp.data;
                        case (offset_reg[3:2])
                            2'b00: rsp_write_data[31:0]   = input_data_reg;
                            2'b01: rsp_write_data[63:32]  = input_data_reg;
                            2'b10: rsp_write_data[95:64]  = input_data_reg;
                            2'b11: rsp_write_data[127:96] = input_data_reg;
                        endcase

                        if (oldest_way_reg == 2'd0) begin
                            cache_tag_w0[index_reg] <= tag_reg;
                            cache_memory_w0[index_reg] <= rsp_write_data;
                        end else if (oldest_way_reg == 2'd1) begin
                            cache_tag_w1[index_reg] <= tag_reg;
                            cache_memory_w1[index_reg] <= rsp_write_data;
                        end else if (oldest_way_reg == 2'd2) begin
                            cache_tag_w2[index_reg] <= tag_reg;
                            cache_memory_w2[index_reg] <= rsp_write_data;
                        end else begin
                            cache_tag_w3[index_reg] <= tag_reg;
                            cache_memory_w3[index_reg] <= rsp_write_data;
                        end

                        valid_bits[index_reg][oldest_way_reg] <= 1'b1;
                        dirty_bits[index_reg][oldest_way_reg] <= 1'b1;
                        output_data_reg <= 32'b0;
                        
                        plru_bits[index_reg] <= oldest_way_reg == 0 ? {2'b11, plru_bit_reg[0]} :
                                                oldest_way_reg == 1 ? {2'b10, plru_bit_reg[0]} :
                                                oldest_way_reg == 2 ? {1'b0, plru_bit_reg[1], 1'b1} : 
                                                                      {1'b0, plru_bit_reg[1], 1'b0};
                        state <= DONE;
                    end
                end

                WAIT_READ_RSP_FOR_READ: begin
                    if (fifo.rsp_en) begin
                        if (oldest_way_reg == 2'd0) begin
                            cache_memory_w0[index_reg] <= fifo.rsp.data;
                            cache_tag_w0[index_reg] <= tag_reg;
                        end else if (oldest_way_reg == 2'd1) begin
                            cache_memory_w1[index_reg] <= fifo.rsp.data;
                            cache_tag_w1[index_reg] <= tag_reg;
                        end else if (oldest_way_reg == 2'd2) begin
                            cache_memory_w2[index_reg] <= fifo.rsp.data;
                            cache_tag_w2[index_reg] <= tag_reg;
                        end else begin
                            cache_memory_w3[index_reg] <= fifo.rsp.data;
                            cache_tag_w3[index_reg] <= tag_reg;
                        end

                        valid_bits[index_reg][oldest_way_reg] <= 1'b1;
                        dirty_bits[index_reg][oldest_way_reg] <= 1'b0;
                        
                        case (offset_reg[3:2])
                            2'b00: output_data_reg <= fifo.rsp.data[31:0];
                            2'b01: output_data_reg <= fifo.rsp.data[63:32];
                            2'b10: output_data_reg <= fifo.rsp.data[95:64];
                            2'b11: output_data_reg <= fifo.rsp.data[127:96];
                        endcase
                        
                        plru_bits[index_reg] <= oldest_way_reg == 0 ? {2'b11, plru_bit_reg[0]} :
                                                oldest_way_reg == 1 ? {2'b10, plru_bit_reg[0]} :
                                                oldest_way_reg == 2 ? {1'b0, plru_bit_reg[1], 1'b1} : 
                                                                      {1'b0, plru_bit_reg[1], 1'b0};
                        state <= DONE;
                    end
                end

                DONE: begin
                    fifo.req_en <= 1'b0;
                    state <= IDLE;
                end
            endcase
        end
    end
endmodule