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

    localparam CACHE_DEPTH = 256;
    localparam TAG_WIDTH = 20; 
    localparam INDEX_WIDTH = 8;
    localparam OFFSET_WIDTH = 2;
    localparam NUM_WAYS = 4;

    (* ram_style = "block" *) reg [127:0] cache_memory_w0 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [127:0] cache_memory_w1 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [127:0] cache_memory_w2 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [127:0] cache_memory_w3 [CACHE_DEPTH-1:0];
    
    (* ram_style = "block" *) reg [TAG_WIDTH-1:0] cache_tag_w0 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [TAG_WIDTH-1:0] cache_tag_w1 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [TAG_WIDTH-1:0] cache_tag_w2 [CACHE_DEPTH-1:0];
    (* ram_style = "block" *) reg [TAG_WIDTH-1:0] cache_tag_w3 [CACHE_DEPTH-1:0];
    
    logic valid_bits [CACHE_DEPTH-1:0][NUM_WAYS-1:0];
    logic dirty_bits [CACHE_DEPTH-1:0][NUM_WAYS-1:0];
    logic [2:0] plru_bits [CACHE_DEPTH-1:0];

    initial begin
        for (int i = 0; i < CACHE_DEPTH; i++) begin
            for (int j = 0; j < NUM_WAYS; j++) begin
                valid_bits[i][j] = 1'b0;
                dirty_bits[i][j] = 1'b0;
            end
            plru_bits[i] = 3'b000;
        end
    end

    localparam IDLE = 5'd0;
    localparam COMP = 5'd3;  
    localparam WAIT_READ_LINE_FOR_READ = 5'd4;
    localparam WAIT_READ_LINE_FOR_WRITE = 5'd5;
    localparam WAIT_WRITE_BACK_FOR_READ = 5'd6;
    localparam WAIT_WRITE_BACK_FOR_WRITE = 5'd7;
    localparam WAIT_READ_RSP_FOR_WRITE = 5'd8;
    localparam WAIT_READ_RSP_FOR_READ = 5'd9;
    localparam WAIT_BETWEEN_REQS_FOR_READ = 5'd10;
    localparam WAIT_BETWEEN_REQS_FOR_WRITE = 5'd11;
    localparam DONE = 5'd12;

    (* fsm_encoding = "one_hot" *) logic [4:0] state = IDLE;

    logic [31:0] output_data_reg;
    assign output_data = output_data_reg;
    assign req_rdy = (state == DONE) || (state == IDLE && !readtrigger && !writetrigger);

    logic [31:0] input_addr_reg;
    logic [31:0] input_data_reg;
    logic read_req_reg;
    logic write_req_reg;

    wire [INDEX_WIDTH-1:0] current_index = input_addr[11:4]; 
    wire [INDEX_WIDTH-1:0] index_reg  = input_addr_reg[11:4]; 
    wire [TAG_WIDTH-1:0]   tag_reg    = input_addr_reg[31:12];
    wire [1:0]             offset_reg = input_addr_reg[3:2];

    logic [TAG_WIDTH-1:0] cache_tag_reg [NUM_WAYS-1:0];
    logic [127:0]         cache_data_reg [NUM_WAYS-1:0];
    logic                 valid_bit_reg [NUM_WAYS-1:0];
    logic                 dirty_bit_reg [NUM_WAYS-1:0];
    logic [2:0]           plru_bit_reg;

    always_ff @(posedge clk) begin
        cache_tag_reg[0]  <= cache_tag_w0[current_index];
        cache_tag_reg[1]  <= cache_tag_w1[current_index];
        cache_tag_reg[2]  <= cache_tag_w2[current_index];
        cache_tag_reg[3]  <= cache_tag_w3[current_index];

        cache_data_reg[0] <= cache_memory_w0[current_index];
        cache_data_reg[1] <= cache_memory_w1[current_index];
        cache_data_reg[2] <= cache_memory_w2[current_index];
        cache_data_reg[3] <= cache_memory_w3[current_index];

        valid_bit_reg[0]  <= valid_bits[current_index][0];
        valid_bit_reg[1]  <= valid_bits[current_index][1];
        valid_bit_reg[2]  <= valid_bits[current_index][2];
        valid_bit_reg[3]  <= valid_bits[current_index][3];

        dirty_bit_reg[0]  <= dirty_bits[current_index][0];
        dirty_bit_reg[1]  <= dirty_bits[current_index][1];
        dirty_bit_reg[2]  <= dirty_bits[current_index][2];
        dirty_bit_reg[3]  <= dirty_bits[current_index][3];

        plru_bit_reg      <= plru_bits[current_index];
    end

    wire hit0_comb = valid_bit_reg[0] && (cache_tag_reg[0] == tag_reg);
    wire hit1_comb = valid_bit_reg[1] && (cache_tag_reg[1] == tag_reg);
    wire hit2_comb = valid_bit_reg[2] && (cache_tag_reg[2] == tag_reg);
    wire hit3_comb = valid_bit_reg[3] && (cache_tag_reg[3] == tag_reg);
    wire is_hit_comb = hit0_comb | hit1_comb | hit2_comb | hit3_comb;

    logic [31:0] word_w0, word_w1, word_w2, word_w3;
    always_comb begin
        case (offset_reg)
            2'b00: begin 
                word_w0 = cache_data_reg[0][31:0];   
                word_w1 = cache_data_reg[1][31:0];   
                word_w2 = cache_data_reg[2][31:0];   
                word_w3 = cache_data_reg[3][31:0]; 
            end
            2'b01: begin 
                word_w0 = cache_data_reg[0][63:32];
                word_w1 = cache_data_reg[1][63:32];  
                word_w2 = cache_data_reg[2][63:32];  
                word_w3 = cache_data_reg[3][63:32];  
            end
            2'b10: begin 
                word_w0 = cache_data_reg[0][95:64];  
                word_w1 = cache_data_reg[1][95:64];  
                word_w2 = cache_data_reg[2][95:64];  
                word_w3 = cache_data_reg[3][95:64];  
                end
            2'b11: begin 
                word_w0 = cache_data_reg[0][127:96]; 
                word_w1 = cache_data_reg[1][127:96]; 
                word_w2 = cache_data_reg[2][127:96]; 
                word_w3 = cache_data_reg[3][127:96]; 
            end
        endcase
    end
    
    wire [31:0] hit_word_comb = ({32{hit0_comb}} & word_w0) | 
                                ({32{hit1_comb}} & word_w1) | 
                                ({32{hit2_comb}} & word_w2) | 
                                ({32{hit3_comb}} & word_w3);

    logic [127:0] mod_w0, mod_w1, mod_w2, mod_w3;
    always_comb begin
        mod_w0 = cache_data_reg[0];
        mod_w1 = cache_data_reg[1];
        mod_w2 = cache_data_reg[2];
        mod_w3 = cache_data_reg[3];
        case (offset_reg)
            2'b00: begin 
                mod_w0[31:0]   = input_data_reg;
                mod_w1[31:0]   = input_data_reg;
                mod_w2[31:0]   = input_data_reg;
                mod_w3[31:0]   = input_data_reg;
            end
            2'b01: begin 
                mod_w0[63:32]  = input_data_reg;
                mod_w1[63:32]  = input_data_reg;
                mod_w2[63:32]  = input_data_reg;
                mod_w3[63:32]  = input_data_reg;
            end
            2'b10: begin 
                mod_w0[95:64]  = input_data_reg;
                mod_w1[95:64]  = input_data_reg;
                mod_w2[95:64]  = input_data_reg;
                mod_w3[95:64]  = input_data_reg;
            end
            2'b11: begin 
                mod_w0[127:96] = input_data_reg; 
                mod_w1[127:96] = input_data_reg; 
                mod_w2[127:96] = input_data_reg; 
                mod_w3[127:96] = input_data_reg; 
            end
        endcase
    end

    logic [1:0] victim_way_comb;
    always_comb begin
        if      (!valid_bit_reg[0]) victim_way_comb = 2'd0;
        else if (!valid_bit_reg[1]) victim_way_comb = 2'd1;
        else if (!valid_bit_reg[2]) victim_way_comb = 2'd2;
        else if (!valid_bit_reg[3]) victim_way_comb = 2'd3;
        else                        victim_way_comb = plru_bit_reg[2] ? (plru_bit_reg[1] ? 2'd3 : 2'd2) : (plru_bit_reg[0] ? 2'd1 : 2'd0);
    end

    logic [2:0] next_plru_comb;
    always_comb begin
        if      (hit0_comb) next_plru_comb = {2'b11, plru_bit_reg[0]};
        else if (hit1_comb) next_plru_comb = {2'b10, plru_bit_reg[0]};
        else if (hit2_comb) next_plru_comb = {1'b0, plru_bit_reg[1], 1'b1};
        else if (hit3_comb) next_plru_comb = {1'b0, plru_bit_reg[1], 1'b0};
        else                next_plru_comb = plru_bit_reg;
    end
    
    logic [2:0] next_plru_on_miss_comb;
    always_comb begin
        case (victim_way_comb)
            2'd0: next_plru_on_miss_comb = {2'b11, plru_bit_reg[0]};
            2'd1: next_plru_on_miss_comb = {2'b10, plru_bit_reg[0]};
            2'd2: next_plru_on_miss_comb = {1'b0, plru_bit_reg[1], 1'b1};
            2'd3: next_plru_on_miss_comb = {1'b0, plru_bit_reg[1], 1'b0};
        endcase
    end

    logic [1:0] victim_way_reg_saved;
    logic [2:0] next_plru_on_miss_reg; 

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            state <= IDLE;
            fifo.req_en <= 1'b0;
            output_data_reg <= 32'b0;
            read_req_reg <= 1'b0;
            write_req_reg <= 1'b0;
        end else begin
            case (state)
                IDLE: begin
                    if (readtrigger || writetrigger) begin
                        read_req_reg  <= readtrigger;
                        write_req_reg <= writetrigger;
                        input_addr_reg <= input_addr;
                        input_data_reg <= input_data;
                        fifo.req_en   <= 1'b0;
                        state <= COMP;
                    end
                end

                COMP: begin
                    if (is_hit_comb) begin
                        if (read_req_reg) begin
                            output_data_reg <= hit_word_comb;
                        end else if (write_req_reg) begin
                            if (hit0_comb) cache_memory_w0[index_reg] <= mod_w0;
                            if (hit1_comb) cache_memory_w1[index_reg] <= mod_w1;
                            if (hit2_comb) cache_memory_w2[index_reg] <= mod_w2;
                            if (hit3_comb) cache_memory_w3[index_reg] <= mod_w3;
                            
                            if (hit0_comb) dirty_bits[index_reg][0] <= 1'b1;
                            if (hit1_comb) dirty_bits[index_reg][1] <= 1'b1;
                            if (hit2_comb) dirty_bits[index_reg][2] <= 1'b1;
                            if (hit3_comb) dirty_bits[index_reg][3] <= 1'b1;
                            
                            output_data_reg <= 32'b0;
                        end
                        plru_bits[index_reg] <= next_plru_comb;
                        state <= DONE; 
                    end else begin
                        victim_way_reg_saved <= victim_way_comb;
                        next_plru_on_miss_reg <= next_plru_on_miss_comb;

                        if (valid_bit_reg[victim_way_comb] && dirty_bit_reg[victim_way_comb]) begin
                            fifo.req.cmd <= 1'b0; 
                            fifo.req.addr <= {cache_tag_reg[victim_way_comb], index_reg, 4'b0000};
                            fifo.req.data <= cache_data_reg[victim_way_comb];
                            fifo.req_en <= 1'b1;
                            state <= write_req_reg ? WAIT_WRITE_BACK_FOR_WRITE : WAIT_WRITE_BACK_FOR_READ;
                        end else begin
                            fifo.req.cmd <= 1'b1;
                            fifo.req.addr <= {input_addr_reg[31:4], 4'b0000};
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
                    fifo.req.cmd <= 1'b1;
                    fifo.req.addr <= {input_addr_reg[31:4], 4'b0000};
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
                    fifo.req.cmd <= 1'b1;
                    fifo.req.addr <= {input_addr_reg[31:4], 4'b0000};
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
                        logic [127:0] write_back_data;
                        write_back_data = fifo.rsp.data;
                        case (offset_reg)
                            2'b00: write_back_data[31:0]   = input_data_reg;
                            2'b01: write_back_data[63:32]  = input_data_reg;
                            2'b10: write_back_data[95:64]  = input_data_reg;
                            2'b11: write_back_data[127:96] = input_data_reg;
                        endcase

                        if (victim_way_reg_saved == 2'd0) begin
                            cache_memory_w0[index_reg] <= write_back_data;
                            cache_tag_w0[index_reg] <= tag_reg; 
                        end
                        if (victim_way_reg_saved == 2'd1) begin
                            cache_memory_w1[index_reg] <= write_back_data;
                            cache_tag_w1[index_reg] <= tag_reg; 
                        end
                        if (victim_way_reg_saved == 2'd2) begin
                            cache_memory_w2[index_reg] <= write_back_data;
                            cache_tag_w2[index_reg] <= tag_reg; 
                        end
                        if (victim_way_reg_saved == 2'd3) begin
                            cache_memory_w3[index_reg] <= write_back_data;
                            cache_tag_w3[index_reg] <= tag_reg; 
                        end
                        
                        valid_bits[index_reg][victim_way_reg_saved] <= 1'b1;
                        dirty_bits[index_reg][victim_way_reg_saved] <= 1'b1;
                        plru_bits[index_reg] <= next_plru_on_miss_reg;
                        
                        output_data_reg <= 32'b0;
                        state <= DONE;
                    end
                end

                WAIT_READ_RSP_FOR_READ: begin
                    if (fifo.rsp_en) begin
                        if (victim_way_reg_saved == 2'd0) begin
                            cache_memory_w0[index_reg] <= fifo.rsp.data;
                            cache_tag_w0[index_reg] <= tag_reg; 
                        end
                        if (victim_way_reg_saved == 2'd1) begin
                            cache_memory_w1[index_reg] <= fifo.rsp.data;
                            cache_tag_w1[index_reg] <= tag_reg; 
                        end
                        if (victim_way_reg_saved == 2'd2) begin
                            cache_memory_w2[index_reg] <= fifo.rsp.data;
                            cache_tag_w2[index_reg] <= tag_reg; 
                        end
                        if (victim_way_reg_saved == 2'd3) begin
                            cache_memory_w3[index_reg] <= fifo.rsp.data;
                            cache_tag_w3[index_reg] <= tag_reg; 
                        end
                        
                        valid_bits[index_reg][victim_way_reg_saved] <= 1'b1;
                        dirty_bits[index_reg][victim_way_reg_saved] <= 1'b0;
                        plru_bits[index_reg] <= next_plru_on_miss_reg;

                        case (offset_reg)
                            2'b00: output_data_reg <= fifo.rsp.data[31:0];
                            2'b01: output_data_reg <= fifo.rsp.data[63:32];
                            2'b10: output_data_reg <= fifo.rsp.data[95:64];
                            2'b11: output_data_reg <= fifo.rsp.data[127:96];
                        endcase
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