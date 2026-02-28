`default_nettype none

module ftoi (
    input  wire logic        clk,
    input  wire logic        rst_n,
    input  wire logic [31:0] in_f,
    input  wire logic        input_valid,
    output logic [31:0]      out_i,
    output logic             out_valid
);

    localparam logic [31:0] MAGIC_NUM_POS = 32'h4B000000;
    localparam logic [31:0] MAGIC_NUM_NEG = 32'hCB000000;

    logic [31:0] s1_fadd_a, s1_fadd_b;
    logic        s1_use_fadd;
    logic [31:0] s1_direct_val;
    logic [7:0]  s1_exp;
    logic        s1_sign;
    
    logic        s1_valid_reg;
    logic        s1_use_fadd_reg;
    logic [31:0] s1_direct_val_reg;
    logic        s1_sign_reg;
    logic [31:0] r_fadd_a, r_fadd_b;

    always_comb begin
        s1_sign = in_f[31];
        s1_exp  = in_f[30:23];
        
        if (s1_exp < 150) begin
            s1_use_fadd   = 1'b1;
            s1_fadd_a     = in_f;
            s1_fadd_b     = s1_sign ? MAGIC_NUM_NEG : MAGIC_NUM_POS;
            s1_direct_val = 32'b0;
        end else begin
            s1_use_fadd   = 1'b0;
            s1_fadd_a     = 32'b0;
            s1_fadd_b     = 32'b0;
            s1_direct_val = in_f;
        end
    end

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            r_fadd_a        <= 32'b0;
            r_fadd_b        <= 32'b0;
            s1_direct_val_reg <= 32'b0;
            s1_use_fadd_reg <= 1'b0;
            s1_sign_reg     <= 1'b0;
            s1_valid_reg    <= 1'b0;
        end else begin
            r_fadd_a        <= s1_fadd_a;
            r_fadd_b        <= s1_fadd_b;
            s1_direct_val_reg <= s1_direct_val;
            s1_use_fadd_reg <= s1_use_fadd;
            s1_sign_reg     <= s1_sign;
            s1_valid_reg    <= input_valid;
        end
    end

    logic [31:0] res_fadd;
    logic        valid_fadd;

    fadd u_fadd (
        .clk        (clk),
        .rst_n      (rst_n),
        .input_a    (r_fadd_a),
        .input_b    (r_fadd_b),
        .input_valid(s1_valid_reg & s1_use_fadd_reg),
        .result     (res_fadd),
        .out_valid  (valid_fadd)
    );

    logic [31:0] s2_large_int;
    logic        s2_large_valid;
    logic        s2_large_sign;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s2_large_int   <= 32'b0;
            s2_large_valid <= 1'b0;
            s2_large_sign  <= 1'b0;
        end else begin
            if (!s1_use_fadd_reg) begin
                logic [7:0]  exp;
                logic [22:0] mant;
                logic [31:0] shifted;
                logic [7:0]  shift_amt;

                exp  = s1_direct_val_reg[30:23];
                mant = s1_direct_val_reg[22:0];
                shift_amt = exp - 150; 
                
                if (shift_amt >= 31) shifted = {1'b1, mant} << shift_amt;
                else                 shifted = {1'b1, mant} << shift_amt;
                
                s2_large_int <= shifted;
            end else begin
                s2_large_int <= 32'b0;
            end
            s2_large_valid <= s1_valid_reg & (!s1_use_fadd_reg);
            s2_large_sign  <= s1_sign_reg;
        end
    end

    logic [31:0] s3_large_int;
    logic        s3_large_valid;
    logic        s3_large_sign;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s3_large_int   <= 32'b0;
            s3_large_valid <= 1'b0;
            s3_large_sign  <= 1'b0;
        end else begin
            s3_large_int   <= s2_large_int;
            s3_large_valid <= s2_large_valid;
            s3_large_sign  <= s2_large_sign;
        end
    end

    logic [31:0] s4_large_int;
    logic        s4_large_valid;
    logic        s4_large_sign;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s4_large_int   <= 32'b0;
            s4_large_valid <= 1'b0;
            s4_large_sign  <= 1'b0;
        end else begin
            s4_large_int   <= s3_large_int;
            s4_large_valid <= s3_large_valid;
            s4_large_sign  <= s3_large_sign;
        end
    end

    logic [2:0] sign_delay_chain;
    always_ff @(posedge clk) begin
        if (!rst_n) sign_delay_chain <= '0;
        else        sign_delay_chain <= {sign_delay_chain[1:0], s1_sign_reg};
    end
    
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            out_i     <= 32'b0;
            out_valid <= 1'b0;
        end else begin
            out_valid <= valid_fadd | s4_large_valid;

            if (valid_fadd) begin
                
                logic [31:0] abs_val;
                abs_val = {9'b0, res_fadd[22:0]}; 
                
                if (sign_delay_chain[2]) begin
                    out_i <= (~abs_val + 1);
                end else begin
                    out_i <= abs_val;
                end

            end else if (s4_large_valid) begin
                if (s4_large_sign) begin
                    out_i <= (~s4_large_int + 1);
                end else begin
                    out_i <= s4_large_int;
                end
            end else begin
                out_i <= 32'b0;
            end
        end
    end

endmodule
`default_nettype wire