module fdiv_mantissa (
    input wire clk,
    input wire rst_n,
    input wire input_valid,
    input wire [23:0] diviend,
    input wire [23:0] divisor,
    output wire [25:0] quotient,
    output wire out_valid
);
    reg [25:0] pipe_rem [0:9];
    reg [25:0] pipe_quo [0:9];
    reg [23:0] pipe_div [0:9];
    reg [9:0]  pipe_val;

    integer k, i;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pipe_val <= 10'b0;
            for (k = 0; k <= 9; k = k + 1) begin
                pipe_rem[k] <= 26'b0;
                pipe_quo[k] <= 26'b0;
                pipe_div[k] <= 24'b0;
            end
        end else begin
            pipe_val[0] <= input_valid;
            pipe_rem[0] <= {2'b0, diviend};
            pipe_quo[0] <= 26'b0;
            pipe_div[0] <= divisor;

            pipe_val[9:1] <= pipe_val[8:0];
            for (k = 0; k < 9; k = k + 1) begin
                reg [25:0] t_rem;
                reg [25:0] t_quo;
                reg [23:0] t_div;
                reg [25:0] t_diff;
                
                t_rem = pipe_rem[k];
                t_quo = pipe_quo[k];
                t_div = pipe_div[k];
                
                for (i = 0; i < (k == 0 ? 2 : 3); i = i + 1) begin
                    t_diff = t_rem - {2'b0, t_div};
                    if (t_diff[25] == 0) begin
                        t_rem = t_diff;
                        t_quo = (t_quo << 1) | 1'b1;
                    end else begin
                        t_quo = t_quo << 1;
                    end
                    t_rem = t_rem << 1;
                end

                pipe_rem[k+1] <= t_rem;
                pipe_quo[k+1] <= t_quo;
                pipe_div[k+1] <= t_div;
            end
        end
    end

    assign quotient  = pipe_quo[9];
    assign out_valid = pipe_val[9];

endmodule