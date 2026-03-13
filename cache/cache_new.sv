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
    assign fifo.rsp_rdy = ((state == WAIT_READ_RSP_FOR_WRITE) || (state == WAIT_READ_RSP_FOR_READ))
                        && fifo.rsp_en;

    localparam DATA_WIDTH = 32;
    localparam CACHE_DEPTH = 1024;
    localparam TAG_WIDTH = 18;
    localparam INDEX_WIDTH = 10;
    localparam OFFSET_WIDTH = 2;

    (* ram_style = "block" *)reg [32*(1 << OFFSET_WIDTH)-1:0] cache_memory_w0 [CACHE_DEPTH];
    (* ram_style = "block" *)reg [32*(1 << OFFSET_WIDTH)-1:0] cache_memory_w1 [CACHE_DEPTH];
    (* ram_style = "block" *)reg [32*(1 << OFFSET_WIDTH)-1:0] cache_memory_w2 [CACHE_DEPTH];
    (* ram_style = "block" *)reg [32*(1 << OFFSET_WIDTH)-1:0] cache_memory_w3 [CACHE_DEPTH];
    (* ram_style = "block" *)reg [TAG_WIDTH-1:0] cache_tag_w0 [CACHE_DEPTH];
    (* ram_style = "block" *)reg [TAG_WIDTH-1:0] cache_tag_w1 [CACHE_DEPTH];
    (* ram_style = "block" *)reg [TAG_WIDTH-1:0] cache_tag_w2 [CACHE_DEPTH];
    (* ram_style = "block" *)reg [TAG_WIDTH-1:0] cache_tag_w3 [CACHE_DEPTH];

    logic valid_bits_w0 [CACHE_DEPTH];
    logic valid_bits_w1 [CACHE_DEPTH];
    logic valid_bits_w2 [CACHE_DEPTH];
    logic valid_bits_w3 [CACHE_DEPTH];
    logic dirty_bits_w0 [CACHE_DEPTH];
    logic dirty_bits_w1 [CACHE_DEPTH];
    logic dirty_bits_w2 [CACHE_DEPTH];
    logic dirty_bits_w3 [CACHE_DEPTH];

    reg [TAG_WIDTH-1:0] tag_reg;
    reg [INDEX_WIDTH-1:0] index_reg;
    reg [OFFSET_WIDTH-1:0] offset_reg;

    logic [31:0] output_data_reg;
    assign output_data = output_data_reg;

    initial begin
        for (int i = 0; i < CACHE_DEPTH; i++) begin
             valid_bits_w0[i] = 1'b0;
             valid_bits_w1[i] = 1'b0;
             valid_bits_w2[i] = 1'b0;
             valid_bits_w3[i] = 1'b0;
             dirty_bits_w0[i] = 1'b0;
             dirty_bits_w1[i] = 1'b0;
             dirty_bits_w2[i] = 1'b0;
             dirty_bits_w3[i] = 1'b0;
             plru_tree[i] = 3'b000;
        end
    end

    localparam logic [4:0] IDLE = 5'b00000;
    localparam logic [4:0] COMP = 5'b00010;
    localparam logic [4:0] WAIT_READ_LINE_FOR_READ = 5'b00100;
    localparam logic [4:0] WAIT_READ_LINE_FOR_WRITE = 5'b00101;
    localparam logic [4:0] WAIT_WRITE_BACK_FOR_READ = 5'b01000;
    localparam logic [4:0] WAIT_WRITE_BACK_FOR_WRITE = 5'b01001;
    localparam logic [4:0] WAIT_READ_RSP_FOR_WRITE = 5'b10001;
    localparam logic [4:0] WAIT_READ_RSP_FOR_READ = 5'b10000;
    localparam logic [4:0] WAIT_BETWEEN_REQS_FOR_READ = 5'b11000;
    localparam logic [4:0] WAIT_BETWEEN_REQS_FOR_WRITE = 5'b11001;
    localparam logic [4:0] DONE = 5'b11111;

    logic [4:0] state = IDLE;

    logic [31:0] input_addr_reg;
    logic [31:0] input_data_reg;
    logic [TAG_WIDTH-1:0] cache_tag_reg_w0;
    logic [TAG_WIDTH-1:0] cache_tag_reg_w1;
    logic [TAG_WIDTH-1:0] cache_tag_reg_w2;
    logic [TAG_WIDTH-1:0] cache_tag_reg_w3;
    logic [127:0] cache_data_reg_w0;
    logic [127:0] cache_data_reg_w1;
    logic [127:0] cache_data_reg_w2;
    logic [127:0] cache_data_reg_w3;
    logic dirty_bit_reg_w0;
    logic dirty_bit_reg_w1;
    logic dirty_bit_reg_w2;
    logic dirty_bit_reg_w3;
    logic valid_bit_reg_w0;
    logic valid_bit_reg_w1;
    logic valid_bit_reg_w2;
    logic valid_bit_reg_w3;

    logic read_req_reg;
    logic write_req_reg;
    assign req_rdy = (state == DONE) || (state == IDLE && !readtrigger && !writetrigger);


    logic [1:0] replace_way_reg;
    logic [2:0] plru_tree [CACHE_DEPTH];
    logic [1:0] victim;
    assign victim = (plru_tree[index_reg][0] == 1'b0) ?
                        (plru_tree[index_reg][1] == 1'b0 ? 2'b00 : 2'b01)
                            : (plru_tree[index_reg][2] == 1'b0 ? 2'b10 : 2'b11);

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

                        fifo.req_en <= 1'b0;

                        tag_reg <= input_addr[31:14];
                        index_reg <= input_addr[13:4];
                        offset_reg <= input_addr[3:2];
                        input_addr_reg <= input_addr;
                        input_data_reg <= input_data;

                        cache_tag_reg_w0 <= cache_tag_w0[input_addr[13:4]];
                        cache_tag_reg_w1 <= cache_tag_w1[input_addr[13:4]];
                        cache_tag_reg_w2 <= cache_tag_w2[input_addr[13:4]];
                        cache_tag_reg_w3 <= cache_tag_w3[input_addr[13:4]];
                        cache_data_reg_w0 <= cache_memory_w0[input_addr[13:4]];
                        cache_data_reg_w1 <= cache_memory_w1[input_addr[13:4]];
                        cache_data_reg_w2 <= cache_memory_w2[input_addr[13:4]];
                        cache_data_reg_w3 <= cache_memory_w3[input_addr[13:4]];
                        dirty_bit_reg_w0 <= dirty_bits_w0[input_addr[13:4]];
                        dirty_bit_reg_w1 <= dirty_bits_w1[input_addr[13:4]];
                        dirty_bit_reg_w2 <= dirty_bits_w2[input_addr[13:4]];
                        dirty_bit_reg_w3 <= dirty_bits_w3[input_addr[13:4]];
                        valid_bit_reg_w0 <= valid_bits_w0[input_addr[13:4]];
                        valid_bit_reg_w1 <= valid_bits_w1[input_addr[13:4]];
                        valid_bit_reg_w2 <= valid_bits_w2[input_addr[13:4]];
                        valid_bit_reg_w3 <= valid_bits_w3[input_addr[13:4]];
                        state <= COMP;
                    end
                end

                COMP: begin
                    if (read_req_reg) begin
                        if (valid_bit_reg_w0 && (cache_tag_reg_w0 == tag_reg)) begin // HIT
                            case (offset_reg)
                                2'b00: output_data_reg <= cache_data_reg_w0[31:0];
                                2'b01: output_data_reg <= cache_data_reg_w0[63:32];
                                2'b10: output_data_reg <= cache_data_reg_w0[95:64];
                                2'b11: output_data_reg <= cache_data_reg_w0[127:96];
                                default: output_data_reg <= 32'b0;
                            endcase
                            plru_tree[index_reg][0] <= 1'b1;
                            plru_tree[index_reg][1] <= 1'b1;
                            state <= DONE;
                        end else if (valid_bit_reg_w1 && (cache_tag_reg_w1 == tag_reg)) begin
                            // HIT
                            case (offset_reg)
                                2'b00: output_data_reg <= cache_data_reg_w1[31:0];
                                2'b01: output_data_reg <= cache_data_reg_w1[63:32];
                                2'b10: output_data_reg <= cache_data_reg_w1[95:64];
                                2'b11: output_data_reg <= cache_data_reg_w1[127:96];
                                default: output_data_reg <= 32'b0;
                            endcase
                            plru_tree[index_reg][0] <= 1'b1;
                            plru_tree[index_reg][1] <= 1'b0;
                            state <= DONE;
                        end else if (valid_bit_reg_w2 && (cache_tag_reg_w2 == tag_reg)) begin
                            // HIT
                            case (offset_reg)
                                2'b00: output_data_reg <= cache_data_reg_w2[31:0];
                                2'b01: output_data_reg <= cache_data_reg_w2[63:32];
                                2'b10: output_data_reg <= cache_data_reg_w2[95:64];
                                2'b11: output_data_reg <= cache_data_reg_w2[127:96];
                                default: output_data_reg <= 32'b0;
                            endcase
                            plru_tree[index_reg][0] <= 1'b0;
                            plru_tree[index_reg][2] <= 1'b1;
                            state <= DONE;
                        end else if (valid_bit_reg_w3 && (cache_tag_reg_w3 == tag_reg)) begin
                            //HIT
                            case (offset_reg)
                                2'b00: output_data_reg <= cache_data_reg_w3[31:0];
                                2'b01: output_data_reg <= cache_data_reg_w3[63:32];
                                2'b10: output_data_reg <= cache_data_reg_w3[95:64];
                                2'b11: output_data_reg <= cache_data_reg_w3[127:96];
                                default: output_data_reg <= 32'b0;
                            endcase
                            plru_tree[index_reg][0] <= 1'b0;
                            plru_tree[index_reg][2] <= 1'b0;
                            state <= DONE;
                        end else begin // MISS
                            replace_way_reg <= victim;

                            case (victim)
                                2'b00: begin
                                    if (valid_bit_reg_w0 && dirty_bit_reg_w0) begin
                                        // Write Back
                                        fifo.req.cmd  <= 1'b0;
                                        fifo.req.addr <= {cache_tag_reg_w0, index_reg, 4'b0000};
                                        fifo.req.data <= cache_data_reg_w0;
                                        fifo.req_en   <= 1'b1;
                                        state <= WAIT_WRITE_BACK_FOR_READ;
                                    end else begin
                                        // Allocate (Read)
                                        fifo.req.cmd  <= 1'b1;
                                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                        fifo.req.data <= 128'b0;
                                        fifo.req_en   <= 1'b1;
                                        state <= WAIT_READ_LINE_FOR_READ;
                                    end
                                    plru_tree[index_reg][0] <= 1'b1;
                                    plru_tree[index_reg][1] <= 1'b1;
                                end
                                2'b01: begin
                                    if (valid_bit_reg_w1 && dirty_bit_reg_w1) begin
                                        // Write Back
                                        fifo.req.cmd  <= 1'b0;
                                        fifo.req.addr <= {cache_tag_reg_w1, index_reg, 4'b0000};
                                        fifo.req.data <= cache_data_reg_w1;
                                        fifo.req_en   <= 1'b1;
                                        state <= WAIT_WRITE_BACK_FOR_READ;
                                    end else begin
                                        // Allocate (Read)
                                        fifo.req.cmd  <= 1'b1;
                                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                        fifo.req.data <= 128'b0;
                                        fifo.req_en   <= 1'b1;
                                        state <= WAIT_READ_LINE_FOR_READ;
                                    end
                                    plru_tree[index_reg][0] <= 1'b1;
                                    plru_tree[index_reg][1] <= 1'b0;
                                end
                                2'b10: begin
                                    if (valid_bit_reg_w2 && dirty_bit_reg_w2) begin
                                        // Write Back
                                        fifo.req.cmd  <= 1'b0;
                                        fifo.req.addr <= {cache_tag_reg_w2, index_reg, 4'b0000};
                                        fifo.req.data <= cache_data_reg_w2;
                                        fifo.req_en   <= 1'b1;
                                        state <= WAIT_WRITE_BACK_FOR_READ;
                                    end else begin
                                        // Allocate (Read)
                                        fifo.req.cmd  <= 1'b1;
                                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                        fifo.req.data <= 128'b0;
                                        fifo.req_en   <= 1'b1;
                                        state <= WAIT_READ_LINE_FOR_READ;
                                    end
                                    plru_tree[index_reg][0] <= 1'b0;
                                    plru_tree[index_reg][2] <= 1'b1;
                                end
                                2'b11: begin
                                    if (valid_bit_reg_w3 && dirty_bit_reg_w3) begin
                                        // Write Back
                                        fifo.req.cmd  <= 1'b0;
                                        fifo.req.addr <= {cache_tag_reg_w3, index_reg, 4'b0000};
                                        fifo.req.data <= cache_data_reg_w3;
                                        fifo.req_en   <= 1'b1;
                                        state <= WAIT_WRITE_BACK_FOR_READ;
                                    end else begin
                                        // Allocate (Read)
                                        fifo.req.cmd  <= 1'b1;
                                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                        fifo.req.data <= 128'b0;
                                        fifo.req_en   <= 1'b1;
                                        state <= WAIT_READ_LINE_FOR_READ;
                                    end
                                    plru_tree[index_reg][0] <= 1'b0;
                                    plru_tree[index_reg][2] <= 1'b0;
                                end
                                default: begin
                                    fifo.req.cmd  <= 1'b1;
                                    fifo.req.addr <= 32'b0;
                                    fifo.req.data <= 128'b0;
                                    fifo.req_en   <= 1'b1;
                                end
                            endcase
                        end
                    end else if (write_req_reg) begin
                        if (valid_bit_reg_w0 && (cache_tag_reg_w0 == tag_reg)) begin // HIT
                            case (offset_reg)
                                2'b00: cache_memory_w0[index_reg] <= {cache_data_reg_w0[127:32], input_data_reg};
                                2'b01: cache_memory_w0[index_reg] <= {cache_data_reg_w0[127:64], input_data_reg, cache_data_reg_w0[31:0]};
                                2'b10: cache_memory_w0[index_reg] <= {cache_data_reg_w0[127:96], input_data_reg, cache_data_reg_w0[63:0]};
                                2'b11: cache_memory_w0[index_reg] <= {input_data_reg, cache_data_reg_w0[95:0]};
                                default: ;
                            endcase
                            plru_tree[index_reg][0] <= 1'b1;
                            plru_tree[index_reg][1] <= 1'b1;
                            dirty_bits_w0[index_reg] <= 1'b1;
                            output_data_reg <= 32'b0;
                            state <= DONE;
                        end else if (valid_bit_reg_w1 && (cache_tag_reg_w1 == tag_reg)) begin
                            case (offset_reg)
                                2'b00: cache_memory_w1[index_reg] <= {cache_data_reg_w1[127:32], input_data_reg};
                                2'b01: cache_memory_w1[index_reg] <= {cache_data_reg_w1[127:64], input_data_reg, cache_data_reg_w1[31:0]};
                                2'b10: cache_memory_w1[index_reg] <= {cache_data_reg_w1[127:96], input_data_reg, cache_data_reg_w1[63:0]};
                                2'b11: cache_memory_w1[index_reg] <= {input_data_reg, cache_data_reg_w1[95:0]};
                                default: ;
                            endcase
                            plru_tree[index_reg][0] <= 1'b1;
                            plru_tree[index_reg][1] <= 1'b0;
                            dirty_bits_w1[index_reg] <= 1'b1;
                            output_data_reg <= 32'b0;
                            state <= DONE;
                        end else if (valid_bit_reg_w2 && (cache_tag_reg_w2 == tag_reg)) begin
                            case (offset_reg)
                                2'b00: cache_memory_w2[index_reg] <= {cache_data_reg_w2[127:32], input_data_reg};
                                2'b01: cache_memory_w2[index_reg] <= {cache_data_reg_w2[127:64], input_data_reg, cache_data_reg_w2[31:0]};
                                2'b10: cache_memory_w2[index_reg] <= {cache_data_reg_w2[127:96], input_data_reg, cache_data_reg_w2[63:0]};
                                2'b11: cache_memory_w2[index_reg] <= {input_data_reg, cache_data_reg_w2[95:0]};
                                default: ;
                            endcase
                            plru_tree[index_reg][0] <= 1'b0;
                            plru_tree[index_reg][2] <= 1'b1;
                            dirty_bits_w2[index_reg] <= 1'b1;
                            output_data_reg <= 32'b0;
                            state <= DONE;
                        end else if (valid_bit_reg_w3 && (cache_tag_reg_w3 == tag_reg)) begin
                            case (offset_reg)
                                2'b00: cache_memory_w3[index_reg] <= {cache_data_reg_w3[127:32], input_data_reg};
                                2'b01: cache_memory_w3[index_reg] <= {cache_data_reg_w3[127:64], input_data_reg, cache_data_reg_w3[31:0]};
                                2'b10: cache_memory_w3[index_reg] <= {cache_data_reg_w3[127:96], input_data_reg, cache_data_reg_w3[63:0]};
                                2'b11: cache_memory_w3[index_reg] <= {input_data_reg, cache_data_reg_w3[95:0]};
                                default: ;
                            endcase
                            plru_tree[index_reg][0] <= 1'b0;
                            plru_tree[index_reg][2] <= 1'b0;
                            dirty_bits_w3[index_reg] <= 1'b1; // ★コピペバグ修正済み
                            output_data_reg <= 32'b0;
                            state <= DONE;
                        end else begin // MISS
                            replace_way_reg <= victim;
                            case (victim)
                                2'b00: begin
                                    if (valid_bit_reg_w0 && dirty_bit_reg_w0) begin
                                        fifo.req.cmd <= 1'b0;
                                        fifo.req.addr <= {cache_tag_reg_w0, index_reg, 4'b0000};
                                        fifo.req.data <= cache_data_reg_w0;
                                        fifo.req_en <= 1'b1;
                                        state <= WAIT_WRITE_BACK_FOR_WRITE;
                                    end else begin
                                        fifo.req.cmd <= 1'b1;
                                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                        fifo.req.data <= 128'b0;
                                        fifo.req_en <= 1'b1;
                                        state <= WAIT_READ_LINE_FOR_WRITE;
                                    end
                                end
                                2'b01: begin
                                    if (valid_bit_reg_w1 && dirty_bit_reg_w1) begin
                                        fifo.req.cmd <= 1'b0;
                                        fifo.req.addr <= {cache_tag_reg_w1, index_reg, 4'b0000};
                                        fifo.req.data <= cache_data_reg_w1;
                                        fifo.req_en <= 1'b1;
                                        state <= WAIT_WRITE_BACK_FOR_WRITE;
                                    end else begin
                                        fifo.req.cmd <= 1'b1;
                                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                        fifo.req.data <= 128'b0;
                                        fifo.req_en <= 1'b1;
                                        state <= WAIT_READ_LINE_FOR_WRITE;
                                    end
                                end
                                2'b10: begin
                                    if (valid_bit_reg_w2 && dirty_bit_reg_w2) begin
                                        fifo.req.cmd <= 1'b0;
                                        fifo.req.addr <= {cache_tag_reg_w2, index_reg, 4'b0000};
                                        fifo.req.data <= cache_data_reg_w2;
                                        fifo.req_en <= 1'b1;
                                        state <= WAIT_WRITE_BACK_FOR_WRITE;
                                    end else begin
                                        fifo.req.cmd <= 1'b1;
                                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                        fifo.req.data <= 128'b0;
                                        fifo.req_en <= 1'b1;
                                        state <= WAIT_READ_LINE_FOR_WRITE;
                                    end
                                end
                                2'b11: begin
                                    if (valid_bit_reg_w3 && dirty_bit_reg_w3) begin
                                        fifo.req.cmd <= 1'b0;
                                        fifo.req.addr <= {cache_tag_reg_w3, index_reg, 4'b0000};
                                        fifo.req.data <= cache_data_reg_w3;
                                        fifo.req_en <= 1'b1;
                                        state <= WAIT_WRITE_BACK_FOR_WRITE;
                                    end else begin
                                        fifo.req.cmd <= 1'b1;
                                        fifo.req.addr <= {tag_reg, index_reg, 4'b0000};
                                        fifo.req.data <= 128'b0;
                                        fifo.req_en <= 1'b1;
                                        state <= WAIT_READ_LINE_FOR_WRITE;
                                    end
                                end
                            endcase
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
                        case (replace_way_reg)
                            2'b00: begin
                                cache_tag_w0[index_reg] <= tag_reg;
                                valid_bits_w0[index_reg] <= 1'b1;
                                case (offset_reg)
                                    2'b00: cache_memory_w0[index_reg] <= {fifo.rsp.data[127:32], input_data_reg};
                                    2'b01: cache_memory_w0[index_reg] <= {fifo.rsp.data[127:64], input_data_reg, fifo.rsp.data[31:0]};
                                    2'b10: cache_memory_w0[index_reg] <= {fifo.rsp.data[127:96], input_data_reg, fifo.rsp.data[63:0]};
                                    2'b11: cache_memory_w0[index_reg] <= {input_data_reg, fifo.rsp.data[95:0]};
                                    default: cache_memory_w0[index_reg] <= 128'b0;
                                endcase
                                dirty_bits_w0[index_reg] <= 1'b1;
                                plru_tree[index_reg][0] <= 1'b1; // ★PLRU更新
                                plru_tree[index_reg][1] <= 1'b1; // ★PLRU更新
                                output_data_reg <= 32'b0;
                                state <= DONE;
                            end
                            2'b01: begin
                                cache_tag_w1[index_reg] <= tag_reg;
                                valid_bits_w1[index_reg] <= 1'b1;
                                case (offset_reg)
                                    2'b00: cache_memory_w1[index_reg] <= {fifo.rsp.data[127:32], input_data_reg};
                                    2'b01: cache_memory_w1[index_reg] <= {fifo.rsp.data[127:64], input_data_reg, fifo.rsp.data[31:0]};
                                    2'b10: cache_memory_w1[index_reg] <= {fifo.rsp.data[127:96], input_data_reg, fifo.rsp.data[63:0]};
                                    2'b11: cache_memory_w1[index_reg] <= {input_data_reg, fifo.rsp.data[95:0]};
                                    default: cache_memory_w1[index_reg] <= 128'b0;
                                endcase
                                dirty_bits_w1[index_reg] <= 1'b1;
                                plru_tree[index_reg][0] <= 1'b1; // ★PLRU更新
                                plru_tree[index_reg][1] <= 1'b0; // ★PLRU更新
                                output_data_reg <= 32'b0;
                                state <= DONE;
                            end
                            2'b10: begin
                                cache_tag_w2[index_reg] <= tag_reg;
                                valid_bits_w2[index_reg] <= 1'b1;
                                case (offset_reg)
                                    2'b00: cache_memory_w2[index_reg] <= {fifo.rsp.data[127:32], input_data_reg};
                                    2'b01: cache_memory_w2[index_reg] <= {fifo.rsp.data[127:64], input_data_reg, fifo.rsp.data[31:0]};
                                    2'b10: cache_memory_w2[index_reg] <= {fifo.rsp.data[127:96], input_data_reg, fifo.rsp.data[63:0]};
                                    2'b11: cache_memory_w2[index_reg] <= {input_data_reg, fifo.rsp.data[95:0]};
                                    default: cache_memory_w2[index_reg] <= 128'b0;
                                endcase
                                dirty_bits_w2[index_reg] <= 1'b1;
                                plru_tree[index_reg][0] <= 1'b0; // ★PLRU更新
                                plru_tree[index_reg][2] <= 1'b1; // ★PLRU更新
                                output_data_reg <= 32'b0;
                                state <= DONE;
                            end
                            2'b11: begin
                                cache_tag_w3[index_reg] <= tag_reg;
                                valid_bits_w3[index_reg] <= 1'b1;
                                case (offset_reg)
                                    2'b00: cache_memory_w3[index_reg] <= {fifo.rsp.data[127:32], input_data_reg};
                                    2'b01: cache_memory_w3[index_reg] <= {fifo.rsp.data[127:64], input_data_reg, fifo.rsp.data[31:0]};
                                    2'b10: cache_memory_w3[index_reg] <= {fifo.rsp.data[127:96], input_data_reg, fifo.rsp.data[63:0]};
                                    2'b11: cache_memory_w3[index_reg] <= {input_data_reg, fifo.rsp.data[95:0]};
                                    default: cache_memory_w3[index_reg] <= 128'b0;
                                endcase
                                dirty_bits_w3[index_reg] <= 1'b1;
                                plru_tree[index_reg][0] <= 1'b0; // ★PLRU更新
                                plru_tree[index_reg][2] <= 1'b0; // ★PLRU更新
                                output_data_reg <= 32'b0;
                                state <= DONE;
                            end
                        endcase
                    end
                end

                WAIT_READ_RSP_FOR_READ: begin
                    if (fifo.rsp_en) begin
                        case (replace_way_reg)
                            2'b00: begin
                                cache_memory_w0[index_reg] <= fifo.rsp.data;
                                cache_tag_w0[index_reg] <= tag_reg;
                                valid_bits_w0[index_reg] <= 1'b1;
                                dirty_bits_w0[index_reg] <= 1'b0;
                                plru_tree[index_reg][0] <= 1'b1; // ★PLRU更新
                                plru_tree[index_reg][1] <= 1'b1; // ★PLRU更新
                            end
                            2'b01: begin
                                cache_memory_w1[index_reg] <= fifo.rsp.data;
                                cache_tag_w1[index_reg] <= tag_reg;
                                valid_bits_w1[index_reg] <= 1'b1;
                                dirty_bits_w1[index_reg] <= 1'b0;
                                plru_tree[index_reg][0] <= 1'b1; // ★PLRU更新
                                plru_tree[index_reg][1] <= 1'b0; // ★PLRU更新
                            end
                            2'b10: begin
                                cache_memory_w2[index_reg] <= fifo.rsp.data;
                                cache_tag_w2[index_reg] <= tag_reg;
                                valid_bits_w2[index_reg] <= 1'b1;
                                dirty_bits_w2[index_reg] <= 1'b0;
                                plru_tree[index_reg][0] <= 1'b0; // ★PLRU更新
                                plru_tree[index_reg][2] <= 1'b1; // ★PLRU更新
                            end
                            2'b11: begin
                                cache_memory_w3[index_reg] <= fifo.rsp.data;
                                cache_tag_w3[index_reg] <= tag_reg;
                                valid_bits_w3[index_reg] <= 1'b1;
                                dirty_bits_w3[index_reg] <= 1'b0;
                                plru_tree[index_reg][0] <= 1'b0; // ★PLRU更新
                                plru_tree[index_reg][2] <= 1'b0; // ★PLRU更新
                            end
                        endcase

                        case (offset_reg)
                            2'b00: output_data_reg <= fifo.rsp.data[31:0];
                            2'b01: output_data_reg <= fifo.rsp.data[63:32];
                            2'b10: output_data_reg <= fifo.rsp.data[95:64];
                            2'b11: output_data_reg <= fifo.rsp.data[127:96];
                            default: output_data_reg <= 32'b0;
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
