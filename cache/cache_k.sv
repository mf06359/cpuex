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
    localparam CACHE_DEPTH = 256;
    localparam TAG_WIDTH = 22;
    localparam INDEX_WIDTH = 8;
    localparam OFFSET_WIDTH = 2;

    reg [32*(1 << OFFSET_WIDTH)-1:0] cache_memory [CACHE_DEPTH-1:0]; 
    reg [TAG_WIDTH-1:0] cache_tag [CACHE_DEPTH-1:0];
    
    logic valid_bits [CACHE_DEPTH-1:0];
    logic dirty_bits [CACHE_DEPTH-1:0];

    reg [TAG_WIDTH-1:0] tag_reg;
    reg [INDEX_WIDTH-1:0] index_reg;
    reg [OFFSET_WIDTH-1:0] offset_reg;


    logic [31:0] output_data_reg;
    assign output_data = output_data_reg;

    initial begin
        // $readmemh("cache_memory_init.mem", cache_memory);
        for (int i = 0; i < CACHE_DEPTH; i++) begin
             valid_bits[i] = 1'b0;
             dirty_bits[i] = 1'b0;
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
    localparam COMP = 5'b00010;
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
    logic [TAG_WIDTH-1:0] cache_tag_reg;
    logic [127:0] cache_data_reg; // 32*4 = 128bit
    logic dirty_bit_reg;
    logic valid_bit_reg;
    logic req_rdy_reg;

    logic read_rise_reg;
    logic write_rise_reg;
    
    assign req_rdy = req_rdy_reg;

    always_ff @(posedge clk) begin
        if (!reset_n) begin
            state <= IDLE;
            fifo.req_en <= 1'b0;
            req_rdy_reg <= 1'b1;
            output_data_reg <= 32'b0;
        end else begin
            case (state)
                IDLE: begin
                    read_rise_reg <= read_rise;
                    write_rise_reg <= write_rise;
                    req_rdy_reg <= 1'b1;
                    if (read_rise || write_rise) begin
                        fifo.req_en <= 1'b0;
                        req_rdy_reg <= 1'b0;

                        tag_reg <= input_addr[31:10];
                        index_reg <= input_addr[9:2];
                        offset_reg <= input_addr[1:0];
                        
                        input_addr_reg <= input_addr;
                        input_data_reg <= input_data;
                        cache_tag_reg <= cache_tag[input_addr[9:2]];
                        cache_data_reg <= cache_memory[input_addr[9:2]];
                        
                        dirty_bit_reg <= dirty_bits[input_addr[9:2]];
                        valid_bit_reg <= valid_bits[input_addr[9:2]];
                        state <= COMP;
                    end
                end

                COMP: begin
                    if (read_rise_reg) begin
                        if (valid_bit_reg && (cache_tag_reg == tag_reg)) begin // HIT
                            case (offset_reg)
                                2'b00: output_data_reg <= cache_data_reg[31:0];
                                2'b01: output_data_reg <= cache_data_reg[63:32];
                                2'b10: output_data_reg <= cache_data_reg[95:64];
                                2'b11: output_data_reg <= cache_data_reg[127:96];
                            endcase
                            state <= DONE;
                        end else begin // MISS
                            if (valid_bit_reg && dirty_bit_reg) begin
                                // Write Back
                                fifo.req.cmd <= 1'b0; 
                                fifo.req.addr <= {cache_tag_reg, index_reg, 2'b00};
                                fifo.req.data <= cache_data_reg;
                                fifo.req_en <= 1'b1;
                                state <= WAIT_WRITE_BACK_FOR_READ;
                            end else begin
                                // Allocate (Read)
                                fifo.req.cmd <= 1'b1; 
                                fifo.req.addr <= {tag_reg, index_reg, 2'b00};
                                fifo.req.data <= 128'b0;
                                fifo.req_en <= 1'b1;
                                state <= WAIT_READ_LINE_FOR_READ;
                            end
                        end
                    end else if (write_rise_reg) begin
                         if (valid_bit_reg && (cache_tag_reg == tag_reg)) begin // HIT
                            case (offset_reg)
                                2'b00: cache_memory[index_reg] <= {cache_data_reg[127:32], input_data_reg};
                                2'b01: cache_memory[index_reg] <= {cache_data_reg[127:64], input_data_reg, cache_data_reg[31:0]};
                                2'b10: cache_memory[index_reg] <= {cache_data_reg[127:96], input_data_reg, cache_data_reg[63:0]};
                                2'b11: cache_memory[index_reg] <= {input_data_reg, cache_data_reg[95:0]};
                            endcase
                            
                            dirty_bits[index_reg] <= 1'b1;
                            output_data_reg <= 32'b0;
                            state <= DONE;
                        end else begin // MISS
                            if (valid_bit_reg && dirty_bit_reg) begin
                                // Write Back
                                fifo.req.cmd <= 1'b0;
                                fifo.req.addr <= {cache_tag_reg, index_reg, 2'b00};
                                fifo.req.data <= cache_data_reg;
                                fifo.req_en <= 1'b1;
                                state <= WAIT_WRITE_BACK_FOR_WRITE;
                            end else begin
                                // Allocate (Read)
                                fifo.req.cmd <= 1'b1;
                                fifo.req.addr <= {tag_reg, index_reg, 2'b00};
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
                        fifo.req.addr <= {tag_reg, index_reg, 2'b00};
                        fifo.req.data <= 128'b0;
                        fifo.req_en <= 1'b1;
                        state <= WAIT_READ_LINE_FOR_READ;
                    end
                end

                WAIT_WRITE_BACK_FOR_WRITE: begin
                    if (fifo.req_rdy) begin
                        fifo.req.cmd <= 1'b1; // read
                        fifo.req.addr <= {tag_reg, index_reg, 2'b00};
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
                        cache_tag[index_reg] <= tag_reg;
                        valid_bits[index_reg] <= 1'b1;
                        case (offset_reg)
                            2'b00: cache_memory[index_reg] <= {fifo.rsp.data[127:32], input_data_reg};
                            2'b01: cache_memory[index_reg] <= {fifo.rsp.data[127:64], input_data_reg, fifo.rsp.data[31:0]};
                            2'b10: cache_memory[index_reg] <= {fifo.rsp.data[127:96], input_data_reg, fifo.rsp.data[63:0]};
                            2'b11: cache_memory[index_reg] <= {input_data_reg, fifo.rsp.data[95:0]};
                        endcase
                        dirty_bits[index_reg] <= 1'b1;
                        output_data_reg <= 32'b0;
                        state <= DONE;
                    end
                end

                WAIT_READ_RSP_FOR_READ: begin
                    if (fifo.rsp_en) begin
                        cache_memory[index_reg] <= fifo.rsp.data;
                        cache_tag[index_reg] <= tag_reg;
                        valid_bits[index_reg] <= 1'b1;
                        dirty_bits[index_reg] <= 1'b0;
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
                    req_rdy_reg <= 1'b1;
                    state <= IDLE;
                end
            endcase
        end
    end
endmodule