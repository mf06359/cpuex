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
    assign fifo.rsp_rdy = 1'b1;

    localparam DATA_WIDTH = 32;
    localparam BYTE_WIDTH = 8;
    localparam WORD_SIZE = 4; 
    localparam CACHE_DEPTH = 128;
    localparam TAG_WIDTH = 21;
    localparam INDEX_WIDTH = 7;
    localparam OFFSET_WIDTH = 4;
    localparam NUM_WAYS = 4;

    (* ram_style = "block" *) reg [127:0] cache_memory_w0 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [127:0] cache_memory_w1 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [127:0] cache_memory_w2 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [127:0] cache_memory_w3 [CACHE_DEPTH-1:0];
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

    logic victim_is[NUM_WAYS-1:0];

    logic [31:0] output_data_reg;
    assign output_data = output_data_reg;

    initial begin
        // $readmemh("cache_memory_init.mem", cache_memory);
        for (int i = 0; i < CACHE_DEPTH; i++) begin
            cache_memory_w0[i] = 128'b0;
            cache_memory_w1[i] = 128'b0;
            cache_memory_w2[i] = 128'b0;
            cache_memory_w3[i] = 128'b0;
            cache_tag_w0[i] = 21'b0;
            cache_tag_w1[i] = 21'b0;
            cache_tag_w2[i] = 21'b0;
            cache_tag_w3[i] = 21'b0;
        end
        for (int i = 0; i < CACHE_DEPTH; i++) begin
            for (int j = 0; j < NUM_WAYS; j++) begin
                valid_bits[i][j] = 1'b0;
                dirty_bits[i][j] = 1'b0;
                plru_bits[i][j] = 3'b000;
            end
        end
    end

    logic left_prev, right_prev;
    always_ff @(posedge clk) begin
        left_prev <= readtrigger;
        right_prev <= writetrigger;
    end

    wire read_rise  = readtrigger & ~left_prev;
    wire write_rise = writetrigger & ~right_prev;

    localparam IDLE = 5'b00000;
    localparam COMPI = 5'b00010;
    localparam WAIT_READ_LINE_FOR_READ = 5'b00100;
    localparam WAIT_READ_LINE_FOR_WRITE = 5'b00101;
    localparam WAIT_WRITE_BACK_FOR_READ = 5'b01000;
    localparam WAIT_WRITE_BACK_FOR_WRITE = 5'b01001;
    localparam WAIT_READ_RSP_FOR_WRITE = 5'b10001;
    localparam WAIT_READ_RSP_FOR_READ = 5'b10000;
    localparam DONE = 5'b11111;

    logic [4:0] state = IDLE;

    logic [31:0] input_addr_reg;
    logic [31:0] input_data_reg;
    logic [TAG_WIDTH-1:0] cache_tag_reg[NUM_WAYS-1:0];
    logic [127:0] cache_data_reg[NUM_WAYS-1:0]; // 32*4 = 128bit
    logic dirty_bit_reg[NUM_WAYS-1:0];
    logic valid_bit_reg[NUM_WAYS-1:0];
    logic req_rdy_reg;

    logic read_rise_reg;
    logic write_rise_reg;
    logic [1:0] oldest_way;
    
    assign req_rdy = req_rdy_reg;

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            state <= IDLE;
            fifo.req_en <= 1'b0;
            req_rdy_reg <= 1'b1;
            output_data_reg <= 32'b0;

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
                    read_rise_reg <= read_rise;
                    write_rise_reg <= write_rise;
                    req_rdy_reg <= 1'b1;
                    if (read_rise || write_rise) begin
                        fifo.req_en <= 1'b0;
                        req_rdy_reg <= 1'b0;

                        tag_reg <= input_addr[31:11];
                        index_reg <= input_addr[10:4];
                        offset_reg <= input_addr[3:0];
                        
                        input_addr_reg <= input_addr;
                        input_data_reg <= input_data;

                        cache_tag_reg[0] <= cache_tag_w0[input_addr[10:4]];
                        cache_tag_reg[1] <= cache_tag_w1[input_addr[10:4]];
                        cache_tag_reg[2] <= cache_tag_w2[input_addr[10:4]];
                        cache_tag_reg[3] <= cache_tag_w3[input_addr[10:4]];

                        cache_data_reg[0] <= cache_memory_w0[input_addr[10:4]];
                        cache_data_reg[1] <= cache_memory_w1[input_addr[10:4]]; 
                        cache_data_reg[2] <= cache_memory_w2[input_addr[10:4]];  
                        cache_data_reg[3] <= cache_memory_w3[input_addr[10:4]]; 

                        dirty_bit_reg[0] <= dirty_bits[input_addr[10:4]][0];
                        dirty_bit_reg[1] <= dirty_bits[input_addr[10:4]][1];
                        dirty_bit_reg[2] <= dirty_bits[input_addr[10:4]][2];
                        dirty_bit_reg[3] <= dirty_bits[input_addr[10:4]][3];

                        valid_bit_reg[0] <= valid_bits[input_addr[10:4]][0];
                        valid_bit_reg[1] <= valid_bits[input_addr[10:4]][1];
                        valid_bit_reg[2] <= valid_bits[input_addr[10:4]][2];
                        valid_bit_reg[3] <= valid_bits[input_addr[10:4]][3];

                        if (!valid_bits[input_addr[10:4]][0]) begin
                            oldest_way <= 2'd0;
                        end else if (!valid_bits[input_addr[10:4]][1]) begin
                            oldest_way <= 2'd1;
                        end else if (!valid_bits[input_addr[10:4]][2]) begin
                            oldest_way <= 2'd2;
                        end else if (!valid_bits[input_addr[10:4]][3]) begin
                            oldest_way <= 2'd3;
                        end else begin
                            oldest_way <= plru_bits[input_addr[10:4]][2] ? 
                                        (plru_bits[input_addr[10:4]][0] ? 2'd3 : 2'd2) : 
                                        (plru_bits[input_addr[10:4]][1] ? 2'd1 : 2'd0);
                        end

                        state <= COMPI;
                    end
                end

                COMPI: begin
                    if (read_rise_reg) begin
                        if (valid_bit_reg[0] && (cache_tag_reg[0] == tag_reg)) begin // HIT
                            case (offset_reg[3:2])
                                2'b00: output_data_reg <= cache_data_reg[0][31:0];
                                2'b01: output_data_reg <= cache_data_reg[0][63:32];
                                2'b10: output_data_reg <= cache_data_reg[0][95:64];
                                2'b11: output_data_reg <= cache_data_reg[0][127:96];
                            endcase
                            plru_bits[index_reg] <= {2'b11, plru_bits[index_reg][0]};
                            state <= DONE;
                        end else if (valid_bit_reg[1] && (cache_tag_reg[1] == tag_reg)) begin // HIT
                            case (offset_reg[3:2])
                                2'b00: output_data_reg <= cache_data_reg[1][31:0];
                                2'b01: output_data_reg <= cache_data_reg[1][63:32];
                                2'b10: output_data_reg <= cache_data_reg[1][95:64];
                                2'b11: output_data_reg <= cache_data_reg[1][127:96];
                            endcase
                            plru_bits[index_reg] <= {2'b10, plru_bits[index_reg][0]};
                            state <= DONE;
                        end else if (valid_bit_reg[2] && (cache_tag_reg[2] == tag_reg)) begin // HIT
                            case (offset_reg[3:2])
                                2'b00: output_data_reg <= cache_data_reg[2][31:0];
                                2'b01: output_data_reg <= cache_data_reg[2][63:32];
                                2'b10: output_data_reg <= cache_data_reg[2][95:64];
                                2'b11: output_data_reg <= cache_data_reg[2][127:96];
                            endcase
                            plru_bits[index_reg] <= {1'b0, plru_bits[index_reg][1], 1'b1};
                            state <= DONE;
                        end else if (valid_bit_reg[3] && (cache_tag_reg[3] == tag_reg)) begin // HIT
                            case (offset_reg[3:2])
                                2'b00: output_data_reg <= cache_data_reg[3][31:0];
                                2'b01: output_data_reg <= cache_data_reg[3][63:32];
                                2'b10: output_data_reg <= cache_data_reg[3][95:64];
                                2'b11: output_data_reg <= cache_data_reg[3][127:96];
                            endcase
                            plru_bits[index_reg] <= {1'b0, plru_bits[index_reg][1], 1'b0};
                            state <= DONE;
                        end else begin // not implemented yet : MISS
                            if (valid_bit_reg[oldest_way] && dirty_bit_reg[oldest_way]) begin
                                // Write Back
                                fifo.req.cmd <= 1'b0; 
                                fifo.req.addr <= {cache_tag_reg[oldest_way], index_reg, 4'b0000};
                                fifo.req.data <= (oldest_way == 0) ? cache_data_reg[0] :
                                                (oldest_way == 1) ? cache_data_reg[1] :
                                                (oldest_way == 2) ? cache_data_reg[2] : cache_data_reg[3];
                                fifo.req_en <= 1'b1;
                                state <= WAIT_WRITE_BACK_FOR_READ;
                            end else begin
                                // Allocate (Read)
                                fifo.req.cmd <= 1'b1; 
                                fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                fifo.req.data <= 128'b0;
                                fifo.req_en <= 1'b1;
                                state <= WAIT_READ_LINE_FOR_READ;
                            end
                        end

                    end else if (write_rise_reg) begin
                        if (valid_bit_reg[0] && (cache_tag_reg[0] == tag_reg)) begin // HIT
                            case (offset_reg[3:2])
                                2'b00: cache_memory_w0[index_reg] <= {cache_data_reg[0][127:32], input_data_reg};
                                2'b01: cache_memory_w0[index_reg] <= {cache_data_reg[0][127:64], input_data_reg, cache_data_reg[0][31:0]};
                                2'b10: cache_memory_w0[index_reg] <= {cache_data_reg[0][127:96], input_data_reg, cache_data_reg[0][63:0]};
                                2'b11: cache_memory_w0[index_reg] <= {input_data_reg, cache_data_reg[0][95:0]};
                            endcase
                            
                            dirty_bits[index_reg][0] <= 1'b1;
                            output_data_reg <= 32'b0;
                            plru_bits[index_reg] <= {2'b11, plru_bits[index_reg][0]};
                            state <= DONE;
                        end else if (valid_bit_reg[1] && (cache_tag_reg[1] == tag_reg)) begin // HIT
                            case (offset_reg[3:2])
                                2'b00: cache_memory_w1[index_reg] <= {cache_data_reg[1][127:32], input_data_reg};
                                2'b01: cache_memory_w1[index_reg] <= {cache_data_reg[1][127:64], input_data_reg, cache_data_reg[1][31:0]};
                                2'b10: cache_memory_w1[index_reg] <= {cache_data_reg[1][127:96], input_data_reg, cache_data_reg[1][63:0]};
                                2'b11: cache_memory_w1[index_reg] <= {input_data_reg, cache_data_reg[1][95:0]};
                            endcase
                            
                            dirty_bits[index_reg][1] <= 1'b1;
                            output_data_reg <= 32'b0;
                            plru_bits[index_reg] <= {2'b10, plru_bits[index_reg][0]};
                            state <= DONE;
                        end else if (valid_bit_reg[2] && (cache_tag_reg[2] == tag_reg)) begin // HIT
                            case (offset_reg[3:2])
                                2'b00: cache_memory_w2[index_reg] <= {cache_data_reg[2][127:32], input_data_reg};
                                2'b01: cache_memory_w2[index_reg] <= {cache_data_reg[2][127:64], input_data_reg, cache_data_reg[2][31:0]};
                                2'b10: cache_memory_w2[index_reg] <= {cache_data_reg[2][127:96], input_data_reg, cache_data_reg[2][63:0]};
                                2'b11: cache_memory_w2[index_reg] <= {input_data_reg, cache_data_reg[2][95:0]};
                            endcase

                            dirty_bits[index_reg][2] <= 1'b1;
                            output_data_reg <= 32'b0;
                            plru_bits[index_reg] <= {1'b0, plru_bits[index_reg][1], 1'b1};  
                            state <= DONE;
                        end else if (valid_bit_reg[3] && (cache_tag_reg[3] == tag_reg)) begin // HIT
                            case (offset_reg[3:2])
                                2'b00: cache_memory_w3[index_reg] <= {cache_data_reg[3][127:32], input_data_reg};
                                2'b01: cache_memory_w3[index_reg] <= {cache_data_reg[3][127:64], input_data_reg, cache_data_reg[3][31:0]};
                                2'b10: cache_memory_w3[index_reg] <= {cache_data_reg[3][127:96], input_data_reg, cache_data_reg[3][63:0]};
                                2'b11: cache_memory_w3[index_reg] <= {input_data_reg, cache_data_reg[3][95:0]};
                            endcase
                            
                            dirty_bits[index_reg][3] <= 1'b1;
                            output_data_reg <= 32'b0;
                            plru_bits[index_reg] <= {1'b0, plru_bits[index_reg][1],1'b0};  
                            state <= DONE;
                        end else begin // not implemented yet : MISS
                            if (valid_bit_reg[oldest_way] && dirty_bit_reg[oldest_way]) begin
                                // Write Back
                                fifo.req.cmd <= 1'b0;
                                fifo.req.addr <= {cache_tag_reg[oldest_way], index_reg, 4'b0000};
                                fifo.req.data <= (oldest_way == 0) ? cache_data_reg[0] :
                                                (oldest_way == 1) ? cache_data_reg[1] :
                                                (oldest_way == 2) ? cache_data_reg[2] : cache_data_reg[3];
                                fifo.req_en <= 1'b1;
                                state <= WAIT_WRITE_BACK_FOR_WRITE;
                            end else begin
                                // Allocate (Read)
                                fifo.req.cmd <= 1'b1;
                                fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                fifo.req.data <= 128'b0;
                                fifo.req_en <= 1'b1;
                                state <= WAIT_READ_LINE_FOR_WRITE;
                            end
                        end
                    end
                end

                WAIT_WRITE_BACK_FOR_READ: begin
                    if (fifo.req_rdy) begin
                        fifo.req.cmd <= 1'b1; // read
                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                        fifo.req.data <= 128'b0;
                        fifo.req_en <= 1'b1;
                        state <= WAIT_READ_LINE_FOR_READ;
                    end
                end

                WAIT_WRITE_BACK_FOR_WRITE: begin
                    if (fifo.req_rdy) begin
                        fifo.req.cmd <= 1'b1; // read
                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                        fifo.req.data <= 128'b0;
                        fifo.req_en <= 1'b1;
                        state <= WAIT_READ_LINE_FOR_WRITE;
                    end
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
                        if (oldest_way == 0) begin
                            cache_tag_w0[index_reg] <= tag_reg;
                            case (offset_reg[3:2])
                                2'b00: cache_memory_w0[index_reg] <= {fifo.rsp.data[127:32], input_data_reg};
                                2'b01: cache_memory_w0[index_reg] <= {fifo.rsp.data[127:64], input_data_reg, fifo.rsp.data[31:0]};
                                2'b10: cache_memory_w0[index_reg] <= {fifo.rsp.data[127:96], input_data_reg, fifo.rsp.data[63:0]};
                                2'b11: cache_memory_w0[index_reg] <= {input_data_reg, fifo.rsp.data[95:0]};
                            endcase
                        end else if (oldest_way == 1) begin
                            cache_tag_w1[index_reg] <= tag_reg;
                            case (offset_reg[3:2])
                                2'b00: cache_memory_w1[index_reg] <= {fifo.rsp.data[127:32], input_data_reg};
                                2'b01: cache_memory_w1[index_reg] <= {fifo.rsp.data[127:64], input_data_reg, fifo.rsp.data[31:0]};
                                2'b10: cache_memory_w1[index_reg] <= {fifo.rsp.data[127:96], input_data_reg, fifo.rsp.data[63:0]};
                                2'b11: cache_memory_w1[index_reg] <= {input_data_reg, fifo.rsp.data[95:0]};
                            endcase
                        end else if (oldest_way == 2) begin
                            cache_tag_w2[index_reg] <= tag_reg;
                            case (offset_reg[3:2])
                                2'b00: cache_memory_w2[index_reg] <= {fifo.rsp.data[127:32], input_data_reg};
                                2'b01: cache_memory_w2[index_reg] <= {fifo.rsp.data[127:64], input_data_reg, fifo.rsp.data[31:0]};
                                2'b10: cache_memory_w2[index_reg] <= {fifo.rsp.data[127:96], input_data_reg, fifo.rsp.data[63:0]};
                                2'b11: cache_memory_w2[index_reg] <= {input_data_reg, fifo.rsp.data[95:0]};
                            endcase
                        end else begin
                            cache_tag_w3[index_reg] <= tag_reg;
                            case (offset_reg[3:2])
                                2'b00: cache_memory_w3[index_reg] <= {fifo.rsp.data[127:32], input_data_reg};
                                2'b01: cache_memory_w3[index_reg] <= {fifo.rsp.data[127:64], input_data_reg, fifo.rsp.data[31:0]};
                                2'b10: cache_memory_w3[index_reg] <= {fifo.rsp.data[127:96], input_data_reg, fifo.rsp.data[63:0]};
                                2'b11: cache_memory_w3[index_reg] <= {input_data_reg, fifo.rsp.data[95:0]};
                            endcase
                        end
                        valid_bits[index_reg][oldest_way] <= 1'b1;
                        dirty_bits[index_reg][oldest_way] <= 1'b1;
                        output_data_reg <= 32'b0;
                        plru_bits[index_reg] <= oldest_way == 0 ? {2'b11, plru_bits[index_reg][0]} :
                                                 oldest_way == 1 ? {2'b10, plru_bits[index_reg][0]} :
                                                 oldest_way == 2 ? {1'b0, plru_bits[index_reg][1], 1'b1} : 
                                                 {1'b0, plru_bits[index_reg][1], 1'b0};
                        state <= DONE;
                    end
                end

                WAIT_READ_RSP_FOR_READ: begin
                    if (fifo.rsp_en) begin
                        if (oldest_way == 0) begin
                            cache_memory_w0[index_reg] <= fifo.rsp.data;
                            cache_tag_w0[index_reg] <= tag_reg;
                        end else if (oldest_way == 1) begin
                            cache_memory_w1[index_reg] <= fifo.rsp.data;
                            cache_tag_w1[index_reg] <= tag_reg;
                        end else if (oldest_way == 2) begin
                            cache_memory_w2[index_reg] <= fifo.rsp.data;
                            cache_tag_w2[index_reg] <= tag_reg;
                        end else begin
                            cache_memory_w3[index_reg] <= fifo.rsp.data;
                            cache_tag_w3[index_reg] <= tag_reg;
                        end
                        valid_bits[index_reg][oldest_way] <= 1'b1;
                        dirty_bits[index_reg][oldest_way] <= 1'b0;
                        case (offset_reg[3:2])
                            2'b00: output_data_reg <= fifo.rsp.data[31:0];
                            2'b01: output_data_reg <= fifo.rsp.data[63:32];
                            2'b10: output_data_reg <= fifo.rsp.data[95:64];
                            2'b11: output_data_reg <= fifo.rsp.data[127:96];
                        endcase
                        plru_bits[index_reg] <= oldest_way == 0 ? {2'b11, plru_bits[index_reg][0]} :
                                                 oldest_way == 1 ? {2'b10, plru_bits[index_reg][0]} :
                                                 oldest_way == 2 ? {1'b0, plru_bits[index_reg][1], 1'b1} : 
                                                 {1'b0, plru_bits[index_reg][1], 1'b0};
                        state <= DONE;
                    end
                end

                DONE: begin
                    fifo.req_en <= 1'b0;
                    req_rdy_reg <= 1'b1;
                    state <= IDLE;
                end
            endcase
        end
    end
endmodule