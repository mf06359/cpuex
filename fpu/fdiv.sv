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

    reg [47:0] lut [0:4095]; 
    initial begin
        $readmemh("taylor_lut.mem", lut);
    end

    // ================================================================
    // Stage 1 registers
    // ================================================================
    reg st1_valid, st1_sign, st1_nan, st1_inf, st1_zero, st1_b_is_power2;
    reg signed [10:0] st1_exponent;
    reg [23:0] st1_mantissa_a, st1_mantissa_b;
    reg [47:0] st1_y0_dy;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            st1_valid <= 1'b0;
            st1_sign <= 1'b0; st1_exponent <= 11'b0;
            st1_nan <= 1'b0; st1_inf <= 1'b0; st1_zero <= 1'b0;
            st1_b_is_power2 <= 1'b0;
            st1_mantissa_a <= 24'b0; st1_mantissa_b <= 24'b0;
            st1_y0_dy <= 48'b0;
        end else begin
            st1_valid <= input_valid;
            st1_sign <= s_a ^ s_b;
            // 指数は符号拡張して計算
            st1_exponent <= {3'b0, calc_e_a} - {3'b0, calc_e_b} + 11'd127;
            
            // Bが2のべき乗かどうかの判定フラグ
            st1_b_is_power2 <= (m_b[22:0] == 23'b0);

            if (a_is_nan || b_is_nan || (a_is_zero && b_is_zero) || (a_is_inf && b_is_inf)) begin
                st1_nan <= 1'b1; st1_inf <= 1'b0; st1_zero <= 1'b0;
            end else if (a_is_inf || b_is_zero) begin
                st1_nan <= 1'b0; st1_inf <= 1'b1; st1_zero <= 1'b0;
            end else if (a_is_zero || b_is_inf) begin
                st1_nan <= 1'b0; st1_inf <= 1'b0; st1_zero <= 1'b1;
            end else begin
                st1_nan <= 1'b0; st1_inf <= 1'b0; st1_zero <= 1'b0;
            end

            st1_mantissa_a <= m_a;
            st1_mantissa_b <= m_b;
            st1_y0_dy <= lut[m_b[22:11]];
        end
    end

    // ================================================================
    // Stage 2 registers
    // ================================================================
    reg st2_valid, st2_sign, st2_nan, st2_inf, st2_zero, st2_b_is_power2;
    reg signed [10:0] st2_exp_minus1, st2_exp_zero, st2_exp_plus1;
    reg [23:0] st2_mantissa, st2_x1;

    wire [47:0] stage2_C = {1'b0, st1_y0_dy[47:24], 23'b0}; 
    wire [47:0] stage2_P = stage2_C - (st1_y0_dy[23:0] * st1_mantissa_b[10:0]);
    wire [23:0] x1_taylor = stage2_P[46:23];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            st2_valid <= 1'b0;
            st2_sign <= 1'b0; 
            st2_nan <= 1'b0; st2_inf <= 1'b0; st2_zero <= 1'b0;
            st2_b_is_power2 <= 1'b0;
            st2_mantissa <= 24'b0; st2_x1 <= 24'b0;
            st2_exp_minus1 <= 11'b0;
            st2_exp_zero   <= 11'b0;
            st2_exp_plus1  <= 11'b0;
        end else begin
            st2_valid <= st1_valid;
            st2_sign <= st1_sign; 
            st2_nan <= st1_nan; st2_inf <= st1_inf; st2_zero <= st1_zero;
            st2_b_is_power2 <= st1_b_is_power2;
            st2_mantissa <= st1_mantissa_a;
            st2_x1 <= x1_taylor;
            
            // ★WNS改善：Stage 3の加算器を消すため、指数変動の全パターンを事前計算
            st2_exp_minus1 <= st1_exponent - 11'sd1;
            st2_exp_zero   <= st1_exponent;
            st2_exp_plus1  <= st1_exponent + 11'sd1;
        end
    end

    // ================================================================
    // Stage 3: Final Calculation (極限まで平坦化)
    // ================================================================
    // Bが2のべき乗の場合は誤差ゼロなのでバイアス無し。それ以外はテイラーの誤差補正
    wire [47:0] bias = st2_b_is_power2 ? 48'h0 : 48'h0000_007F_FFFF;

    // DSPブロック内で乗算と加算を同時に完了
    wire [47:0] q_final = (st2_mantissa * st2_x1) + bias;

    // 乗算結果の繰り上がりとシフト量
    wire exp_carry  = q_final[47]; // ★これがバグの原因だった 0x8000_0000_0000 への繰り上がり
    wire norm_shift = q_final[46];
    
    // 状態判定 (0: -1 shift,  1: no shift,  2: +1 shift (carry))
    wire [1:0] shift_sel = exp_carry ? 2'd2 : (norm_shift ? 2'd1 : 2'd0);
    
    // MUXによるフラクション抽出（加算・減算回路なし）
    wire [22:0] final_fraction = (shift_sel == 2'd2) ? q_final[46:24] :
                                 (shift_sel == 2'd1) ? q_final[45:23] : 
                                                       q_final[44:22];

    // MUXによる指数抽出（加算回路なし）
    wire signed [10:0] final_exp = (shift_sel == 2'd2) ? st2_exp_plus1 :
                                   (shift_sel == 2'd1) ? st2_exp_zero :
                                                         st2_exp_minus1;

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
                // 最終例外判定
                if (final_exp >= 11'sd255) begin
                    result <= {st2_sign, 8'hFF, 23'b0};
                end else if (final_exp <= 11'sd0) begin
                    result <= {st2_sign, 31'b0};
                end else begin
                    result <= {st2_sign, final_exp[7:0], final_fraction};
                end
            end
        end
    end

endmodule