`default_nettype none
module fdiv (
    input  wire logic        clk,
    input  wire logic        rst_n,
    input  wire logic [31:0] input_a,
    input  wire logic [31:0] input_b,
    input  wire logic        input_valid,
    output logic [31:0]      result,
    output logic             out_valid   
);
    localparam [31:0] QUIET_NAN = 32'h7FC0_0000;
    localparam [47:0] CONST_TWO = 48'h8000_0000_0000; // 2.0 in 1.23 fixed-point

    wire s_a = input_a[31];
    wire [7:0] e_a = input_a[30:23];
    wire [23:0] m_a = (|e_a) ? {1'b1, input_a[22:0]} : {1'b0, input_a[22:0]};

    wire s_b = input_b[31];
    wire [7:0] e_b = input_b[30:23];
    wire [23:0] m_b = (|e_b) ? {1'b1, input_b[22:0]} : {1'b0, input_b[22:0]};

    wire [7:0] calc_e_a = (|e_a) ? e_a : 8'd1;
    wire [7:0] calc_e_b = (|e_b) ? e_b : 8'd1;

    wire a_is_nan = (&e_a) && (input_a[22:0] != 0);
    wire b_is_nan = (&e_b) && (input_b[22:0] != 0);
    wire a_is_inf = (&e_a) && (input_a[22:0] == 0);
    wire b_is_inf = (&e_b) && (input_b[22:0] == 0);
    wire a_is_zero = input_a[30:0] == 0;
    wire b_is_zero = input_b[30:0] == 0;

    reg [47:0] lut [0:4095]; // 1.23形式の初期近似値を格納するLUT
    initial begin
        $readmemh("taylor_lut.mem", lut);
    end

    reg st1_valid;
    reg st1_sign;
    reg signed [9:0] st1_exponent;
    reg st1_nan, st1_inf, st1_zero;
    reg [23:0] st1_mantissa_a, st1_mantissa_b, st1_x0;

    reg [47:0] st1_y0_dy;

    reg st2_valid;
    reg st2_sign;
    reg signed [9:0] st2_exponent;
    reg st2_nan, st2_inf, st2_zero;
    reg [23:0] st2_mantissa;
    reg [23:0] st2_x1;


    wire [40:0] mult1_low = st1_mantissa_b * st1_x0[16:0]; 
    wire [30:0] mult1_high = st1_mantissa_b * st1_x0[23:17]; 
    wire [47:0] matissa_b_x0 = {mult1_high, 17'b0} + mult1_low; // 48bit

    wire [47:0] diff = CONST_TWO - matissa_b_x0; // 48bit
    wire [23:0] diff_24 = diff[46:23]; // 上位24ビットを切り出す

    wire [40:0] mult2_low = st1_x0 * diff_24[16:0];
    wire [30:0] mult2_high = st1_x0 * diff_24[23:17];
    wire [47:0] x1_full = {mult2_high, 17'b0} + mult2_low; // 48bit

    wire [34:0] dy_Y = st1_y0_dy[23:0] * st1_mantissa_b[10:0]; 

    wire [23:0] x1_taylor = st1_y0_dy[47:24] - dy_Y[34:23];

    wire [40:0] mult3_low = st2_mantissa * st2_x1[16:0];
    wire [30:0] mult3_high = st2_mantissa * st2_x1[23:17];
    wire [47:0] q_full = {mult3_high, 17'b0} + mult3_low; 

    wire [47:0] q_adjusted = (q_full[46:45] == 2'b00 && q_full[44]) ? (q_full + 48'h0000_0080_0000) : q_full;

    wire [25:0] temp_mantissa = q_adjusted[46:21]; 

    wire [24:0] mantissa_rounded_1 = {1'b0, temp_mantissa[25:2]} + {24'b0, temp_mantissa[1]};
    wire [24:0] mantissa_rounded_0 = {1'b0, temp_mantissa[24:1]} + {24'b0, temp_mantissa[0]};

    reg[23:0] st2_mantissa_b;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            st1_valid <= 1'b0;
            st1_sign <= 1'b0;
            st1_exponent <= 10'b0;
            st1_nan <= 1'b0;
            st1_inf <= 1'b0;
            st1_zero <= 1'b0;
            st1_mantissa_a <= 24'b0;
            st1_mantissa_b <= 24'b0;
            st1_x0 <= 24'b0;
            st1_y0_dy <= 48'b0;
        end else begin
            st1_valid <= input_valid;
            st1_sign <= s_a ^ s_b;
            st1_exponent <= {2'b0, calc_e_a} - {2'b0, calc_e_b} + 10'd127; // 初期指数の計算

            if (a_is_nan || b_is_nan || (a_is_zero && b_is_zero) || (a_is_inf && b_is_inf)) begin
                st1_nan <= 1'b1;
                st1_inf <= 1'b0;
                st1_zero <= 1'b0;
            end else if (a_is_inf || b_is_zero) begin
                st1_nan <= 1'b0;
                st1_inf <= 1'b1;
                st1_zero <= 1'b0;
            end else if (a_is_zero || b_is_inf) begin
                st1_nan <= 1'b0;
                st1_inf <= 1'b0;
                st1_zero <= 1'b1;
            end else begin
                st1_nan <= 1'b0;
                st1_inf <= 1'b0;
                st1_zero <= 1'b0;
            end

            st1_mantissa_a <= m_a;
            st1_mantissa_b <= m_b;
            st1_x0 <= lut[m_b[22:13]]; // m_bの上位8ビットをインデックスにして初期近似値を取得
            st1_y0_dy <= lut[m_b[22:11]]; // m_bの上位8ビットをインデックスにして初期近似値を取得
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            st2_valid <= 1'b0;
            st2_sign <= 1'b0;
            st2_exponent <= 10'b0;
            st2_nan <= 1'b0;
            st2_inf <= 1'b0;
            st2_zero <= 1'b0;
            st2_mantissa <= 24'b0;
            st2_x1 <= 24'b0;
        end else begin
            st2_valid <= st1_valid; // 単純にパイプラインを進める
            st2_sign <= st1_sign;
            st2_exponent <= st1_exponent; // 指数は初期段階で計算済み

            st2_nan <= st1_nan;
            st2_inf <= st1_inf;
            st2_zero <= st1_zero;

            st2_mantissa <= st1_mantissa_a; // 初期近似値を使って割り算の近似値を計算
            st2_mantissa_b <= st1_mantissa_b; // 後の段階で使用するため保持

            st2_x1 <= x1_taylor; // Taylor展開による近似値を使用
            // st2_x1 <= x1_full[46:23] + {23'b0, x1_full[22]}; 
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            result <= 32'b0;
            out_valid <= 1'b0;
        end else begin
            out_valid <= st2_valid;

            if (st2_nan) begin
                result <= QUIET_NAN; 
            end else if (st2_inf) begin
                result <= {st2_sign, 8'hFF, 23'b0}; 
            end else if (st2_zero) begin
                result <= {st2_sign, 31'b0}; 
            end else if (st2_valid) begin
                if (st2_exponent > 10'sd255 || (st2_exponent == 10'sd255 && st2_mantissa >= st2_mantissa_b)) begin
                    result <= {st2_sign, 31'b0};
                end else if (temp_mantissa[25] == 1'b1) begin 
                    if (mantissa_rounded_1[24]) begin  
                        if ((st2_exponent + 1) >= 8'hFF) result <= {st2_sign, 8'hFF, 23'b0};
                        else result <= {st2_sign, (st2_exponent[7:0] + 8'd1), mantissa_rounded_1[23:1]}; 
                    end else begin
                        if (st2_exponent <= 0) result <= {st2_sign, 31'b0};
                        else if (st2_exponent >= 8'hFF) result <= {st2_sign, 8'hFF, 23'b0}; 
                        else result <= {st2_sign, st2_exponent[7:0], mantissa_rounded_1[22:0]};
                    end
                end else begin
                    if (mantissa_rounded_0[24]) begin  
                         if (st2_exponent <= 0) result <= {st2_sign, 31'b0};
                         else if (st2_exponent >= 8'hFF) result <= {st2_sign, 8'hFF, 23'b0}; 
                         else result <= {st2_sign, st2_exponent[7:0], mantissa_rounded_0[23:1]};
                    end else begin
                        if ((st2_exponent - 1) <= 0) result <= {st2_sign, 31'b0};
                        else if ((st2_exponent - 1) >= 8'hFF) result <= {st2_sign, 8'hFF, 23'b0}; 
                        else result <= {st2_sign, (st2_exponent[7:0] - 8'd1), mantissa_rounded_0[22:0]};
                    end
                end
            end
        end
    end

endmodule