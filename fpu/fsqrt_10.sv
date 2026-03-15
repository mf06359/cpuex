`default_nettype none

module fsqrt (
    input wire logic clk,
    input wire logic rst_n,
    input wire logic [31:0] input_a,
    input wire logic input_valid,
    output logic [31:0] result,
    output logic out_valid
);
    localparam int STAGES = 10;
    localparam int LOOPS_PER_STAGE [0:9] = '{4, 3, 4, 3, 3, 2, 2, 2, 2, 2};
    
    logic [53:0] pipe_rem   [0:STAGES-1];
    logic [27:0] pipe_root  [0:STAGES-1];
    logic [7:0]  pipe_exp   [0:STAGES-1];
    logic        pipe_sign  [0:STAGES-1];
    logic        pipe_valid [0:STAGES-1];
    logic        pipe_zero  [0:STAGES-1];
    logic        pipe_nan   [0:STAGES-1];
    logic        pipe_neg   [0:STAGES-1];

    
    logic [53:0] next_rem   [0:STAGES-1];
    logic [27:0] next_root  [0:STAGES-1];
    
    always_comb begin
        
        int s, j;
        int k_curr;     
        int loop_count; 

        logic [53:0] cur_rem;
        logic [27:0] cur_root;
        logic [53:0] term;
        logic [54:0] diff;

        
        logic [31:0] in_data;
        logic [7:0] in_exp;
        logic [22:0] in_mant;
        logic [53:0] mant_shifted;
        
        in_data = input_a;
        in_exp  = in_data[30:23];
        in_mant = in_data[22:0];

        
        if (in_exp[0] == 1'b0) begin
            mant_shifted = {1'b1, in_mant, 30'b0};
        end else begin
            mant_shifted = {2'b0, 1'b1, in_mant, 29'b0};
        end

        
        k_curr = 0;

        
        for (s = 0; s < STAGES; s++) begin
            
            
            if (s == 0) begin
                cur_rem  = mant_shifted;
                cur_root = '0;
            end else begin
                cur_rem  = pipe_rem[s-1];
                cur_root = pipe_root[s-1];
            end

            
            loop_count = LOOPS_PER_STAGE[s];

            for (j = 0; j < loop_count; j++) begin
                
                
                
                term = ({26'b0, cur_root} << 2 | 1) << ((26 - k_curr) * 2);
                diff = {1'b0, cur_rem} - {1'b0, term};

                if (diff[54] == 1'b0) begin
                    cur_rem  = diff[53:0];
                    cur_root = (cur_root << 1) | 1;
                end else begin
                    cur_root = (cur_root << 1);
                end
                
                
                k_curr++; 
            end

            
            next_rem[s]  = cur_rem;
            next_root[s] = cur_root;
        end
    end

    
    
    
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int i = 0; i < STAGES; i++) begin
                pipe_valid[i] <= '0;
                pipe_rem[i]   <= '0;
                pipe_root[i]  <= '0;
                pipe_exp[i]   <= '0;
                pipe_sign[i]  <= '0;
                pipe_zero[i]  <= '0;
                pipe_nan[i]   <= '0;
                pipe_neg[i]   <= '0;
            end
        end else begin
            
            pipe_rem[0]   <= next_rem[0];
            pipe_root[0]  <= next_root[0];
            pipe_exp[0]   <= (input_a[30:23] + 127) >> 1; 
            pipe_sign[0]  <= input_a[31];
            pipe_valid[0] <= input_valid;
            pipe_zero[0]  <= (input_a[30:0] == 0);
            pipe_nan[0]   <= (&input_a[30:23]);
            pipe_neg[0]   <= input_a[31] && (input_a[30:0] != 0);

            
            for (int i = 1; i < STAGES; i++) begin
                pipe_rem[i]   <= next_rem[i];
                pipe_root[i]  <= next_root[i];
                
                pipe_exp[i]   <= pipe_exp[i-1];
                pipe_sign[i]  <= pipe_sign[i-1];
                pipe_valid[i] <= pipe_valid[i-1];
                pipe_zero[i]  <= pipe_zero[i-1];
                pipe_nan[i]   <= pipe_nan[i-1];
                pipe_neg[i]   <= pipe_neg[i-1];
            end
        end
    end

    
    
    
    logic [31:0] final_result_comb;

    always_comb begin
        logic guard_bit, round_bit, sticky_bit, lsb_bit, round_up;
        logic [22:0] frac_final;
        logic [27:0] root_last;
        logic [53:0] rem_last;

        
        root_last = pipe_root[STAGES-1];
        rem_last  = pipe_rem[STAGES-1];

        
        guard_bit  = root_last[2];
        round_bit  = root_last[1];
        sticky_bit = root_last[0] | (rem_last != 0);
        lsb_bit    = root_last[3];

        round_up = guard_bit & (round_bit | sticky_bit | lsb_bit);

        if (round_up) begin
            frac_final = root_last[25:3] + 1;
        end else begin
            frac_final = root_last[25:3];
        end

        
        if (pipe_nan[STAGES-1] || pipe_neg[STAGES-1]) begin
            final_result_comb = 32'h7FC00000; 
        end else if (pipe_zero[STAGES-1]) begin
            final_result_comb = {pipe_sign[STAGES-1], 31'h00000000}; 
        end else begin
            final_result_comb = {1'b0, pipe_exp[STAGES-1], frac_final};
        end
    end

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            result <= '0;
            out_valid <= '0;
        end else begin
            result <= final_result_comb;
            out_valid <= pipe_valid[STAGES-1];
        end
    end

endmodule
`default_nettype wire