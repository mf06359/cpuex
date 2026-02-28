`default_nettype none

module itof (
    input  wire logic        clk,
    input  wire logic        rst_n,
    input  wire logic [31:0] in_i,
    input  wire logic        input_valid,
    output logic [31:0]      out_f,
    output logic             out_valid
);

    logic [31:0] s1_abs_i;
    logic        s1_sign;
    logic        s1_valid;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s1_abs_i <= 0;
            s1_sign  <= 0;
            s1_valid <= 0;
        end else begin
            s1_valid <= input_valid;
            s1_sign  <= in_i[31];
            s1_abs_i <= in_i[31] ? (~in_i + 1) : in_i;
        end
    end

    logic [4:0] s2_lzc;
    logic [31:0] s2_abs_i;
    logic        s2_sign;
    logic        s2_valid;

    function automatic [4:0] lzc32(input [31:0] v);
        if (v[31]) return 0;  if (v[30]) return 1;  if (v[29]) return 2;  if (v[28]) return 3;
        if (v[27]) return 4;  if (v[26]) return 5;  if (v[25]) return 6;  if (v[24]) return 7;
        if (v[23]) return 8;  if (v[22]) return 9;  if (v[21]) return 10; if (v[20]) return 11;
        if (v[19]) return 12; if (v[18]) return 13; if (v[17]) return 14; if (v[16]) return 15;
        if (v[15]) return 16; if (v[14]) return 17; if (v[13]) return 18; if (v[12]) return 19;
        if (v[11]) return 20; if (v[10]) return 21; if (v[9])  return 22; if (v[8])  return 23;
        if (v[7])  return 24; if (v[6])  return 25; if (v[5])  return 26; if (v[4])  return 27;
        if (v[3])  return 28; if (v[2])  return 29; if (v[1])  return 30; if (v[0])  return 31;
        return 31;
    endfunction

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s2_lzc   <= 0;
            s2_abs_i <= 0;
            s2_sign  <= 0;
            s2_valid <= 0;
        end else begin
            s2_valid <= s1_valid;
            s2_sign  <= s1_sign;
            s2_abs_i <= s1_abs_i;
            s2_lzc   <= lzc32(s1_abs_i);
        end
    end

    logic guard;
    logic round;
    logic sticky;
    logic lsb;
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            out_f     <= 0;
            out_valid <= 0;
        end else begin
            out_valid <= s2_valid;
            if (s2_abs_i == 0) begin
                out_f <= 0;
            end else begin
                logic [7:0]  exp;
                logic [31:0] shifted_mant;
                logic [22:0] frac;
                logic [31:0] sticky_mask;

                exp = 8'd127 + (8'd31 - {3'b0, s2_lzc});

                shifted_mant = s2_abs_i << s2_lzc; 
                
                guard  = shifted_mant[7];
                round  = shifted_mant[6];
                sticky = (shifted_mant[5:0] != 0);
                lsb    = shifted_mant[8];
                
                if (guard && (round || sticky || lsb)) begin
                    {exp, frac} = {exp, shifted_mant[30:8]} + 1;
                end else begin
                    frac = shifted_mant[30:8];
                end
                
                out_f <= {s2_sign, exp, frac};
            end
        end
    end

endmodule