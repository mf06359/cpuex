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
    // Stage 1: Parsing, Pre-Shift, Parallel Exponent Calculation
    // ================================================================
    reg st1_valid, st1_sign, st1_nan, st1_inf, st1_zero;
    reg [24:0] st1_adjusted_a;
    reg [10:0] st1_m_b_10_0;
    reg [47:0] st1_y0_dy;
    reg [48:0] st1_bias;
    reg st1_shift_pred;

    reg [7:0] st1_exp_p1, st1_exp_0, st1_exp_m1, st1_exp_m2;
    reg st1_ovf_p1, st1_ovf_0, st1_ovf_m1, st1_ovf_m2;
    reg st1_udf_p1, st1_udf_0, st1_udf_m1, st1_udf_m2;

    // シフト予測とAの調整（Stage 1のレジスタに格納するまでのパス）
    wire shift_pred = (m_a >= m_b);
    wire [24:0] adjusted_a = shift_pred ? {1'b0, m_a} : {m_a, 1'b0};

    // ★ WNS改善: shift_pred に依存しない純粋な指数差を求め、全パターンの比較を並列実行
    wire signed [10:0] raw_exp = {3'b0, calc_e_a} - {3'b0, calc_e_b} + 11'sd127;
    
    wire signed [10:0] exp_p1 = raw_exp + 11'sd1;
    wire signed [10:0] exp_0  = raw_exp;
    wire signed [10:0] exp_m1 = raw_exp - 11'sd1;
    wire signed [10:0] exp_m2 = raw_exp - 11'sd2;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            st1_valid <= 1'b0; st1_sign <= 1'b0;
            st1_nan <= 1'b0; st1_inf <= 1'b0; st1_zero <= 1'b0;
            st1_adjusted_a <= 25'b0; st1_m_b_10_0 <= 11'b0;
            st1_y0_dy <= 48'b0; st1_bias <= 49'b0;
            st1_shift_pred <= 1'b0;
            
            st1_exp_p1 <= 8'b0; st1_exp_0 <= 8'b0; st1_exp_m1 <= 8'b0; st1_exp_m2 <= 8'b0;
            st1_ovf_p1 <= 1'b0; st1_ovf_0 <= 1'b0; st1_ovf_m1 <= 1'b0; st1_ovf_m2 <= 1'b0;
            st1_udf_p1 <= 1'b0; st1_udf_0 <= 1'b0; st1_udf_m1 <= 1'b0; st1_udf_m2 <= 1'b0;
        end else begin
            st1_valid <= input_valid;
            st1_sign <= s_a ^ s_b;

            st1_adjusted_a <= adjusted_a;
            st1_shift_pred <= shift_pred;
            st1_m_b_10_0 <= m_b[10:0];
            st1_y0_dy <= lut[m_b[22:11]];

            // ★ バグ修正: テイラー近似の負の誤差をカバーするため、バイアスを大幅に増量する
            st1_bias <= (m_b[22:0] == 23'b0) ? 49'h0 : 49'h0_0000_017F_FFFF;

            // 11bitの比較器をStage 1で完全に並列化して吸収
            st1_exp_p1 <= exp_p1[7:0]; st1_ovf_p1 <= (exp_p1 >= 11'sd255); st1_udf_p1 <= (exp_p1 <= 11'sd0);
            st1_exp_0  <= exp_0[7:0];  st1_ovf_0  <= (exp_0  >= 11'sd255); st1_udf_0  <= (exp_0  <= 11'sd0);
            st1_exp_m1 <= exp_m1[7:0]; st1_ovf_m1 <= (exp_m1 >= 11'sd255); st1_udf_m1 <= (exp_m1 <= 11'sd0);
            st1_exp_m2 <= exp_m2[7:0]; st1_ovf_m2 <= (exp_m2 >= 11'sd255); st1_udf_m2 <= (exp_m2 <= 11'sd0);

            if (a_is_nan || b_is_nan || (a_is_zero && b_is_zero) || (a_is_inf && b_is_inf)) begin
                st1_nan <= 1'b1; st1_inf <= 1'b0; st1_zero <= 1'b0;
            end else if (a_is_inf || b_is_zero) begin
                st1_nan <= 1'b0; st1_inf <= 1'b1; st1_zero <= 1'b0;
            end else if (a_is_zero || b_is_inf) begin
                st1_nan <= 1'b0; st1_inf <= 1'b0; st1_zero <= 1'b1;
            end else begin
                st1_nan <= 1'b0; st1_inf <= 1'b0; st1_zero <= 1'b0;
            end
        end
    end

    // ================================================================
    // Stage 2: Taylor Expansion (DSP P = C - A * B)
    // ================================================================
    reg st2_valid, st2_sign, st2_nan, st2_inf, st2_zero;
    reg [24:0] st2_adjusted_a;
    reg [23:0] st2_x1;
    reg [48:0] st2_bias;
    reg st2_shift_pred;

    reg [7:0] st2_exp_p1, st2_exp_0, st2_exp_m1, st2_exp_m2;
    reg st2_ovf_p1, st2_ovf_0, st2_ovf_m1, st2_ovf_m2;
    reg st2_udf_p1, st2_udf_0, st2_udf_m1, st2_udf_m2;

    wire [47:0] stage2_C = {1'b0, st1_y0_dy[47:24], 23'b0}; 
    wire [47:0] stage2_P = stage2_C - (st1_y0_dy[23:0] * st1_m_b_10_0);
    wire [23:0] x1_taylor = stage2_P[46:23];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            st2_valid <= 1'b0; st2_sign <= 1'b0; 
            st2_nan <= 1'b0; st2_inf <= 1'b0; st2_zero <= 1'b0;
            st2_adjusted_a <= 25'b0; st2_x1 <= 24'b0; st2_bias <= 49'b0;
            st2_shift_pred <= 1'b0;
            
            st2_exp_p1 <= 8'b0; st2_exp_0 <= 8'b0; st2_exp_m1 <= 8'b0; st2_exp_m2 <= 8'b0;
            st2_ovf_p1 <= 1'b0; st2_ovf_0 <= 1'b0; st2_ovf_m1 <= 1'b0; st2_ovf_m2 <= 1'b0;
            st2_udf_p1 <= 1'b0; st2_udf_0 <= 1'b0; st2_udf_m1 <= 1'b0; st2_udf_m2 <= 1'b0;
        end else begin
            st2_valid <= st1_valid;
            st2_sign <= st1_sign; 
            st2_nan <= st1_nan; st2_inf <= st1_inf; st2_zero <= st1_zero;

            st2_adjusted_a <= st1_adjusted_a;
            st2_x1 <= x1_taylor;
            st2_bias <= st1_bias;
            st2_shift_pred <= st1_shift_pred;
            
            st2_exp_p1 <= st1_exp_p1; st2_ovf_p1 <= st1_ovf_p1; st2_udf_p1 <= st1_udf_p1;
            st2_exp_0  <= st1_exp_0;  st2_ovf_0  <= st1_ovf_0;  st2_udf_0  <= st1_udf_0;
            st2_exp_m1 <= st1_exp_m1; st2_ovf_m1 <= st1_ovf_m1; st2_udf_m1 <= st1_udf_m1;
            st2_exp_m2 <= st1_exp_m2; st2_ovf_m2 <= st1_ovf_m2; st2_udf_m2 <= st1_udf_m2;
        end
    end

    // ================================================================
    // Stage 3: Final Calculation (DSP Multiply-Add + Output MUX)
    // ================================================================
    wire [48:0] q_final = (st2_adjusted_a * st2_x1) + st2_bias;

    wire carry = q_final[47]; // 丸めでちょうど 2.0 に押し上げられた時のみ 1
    wire norm  = q_final[46]; // 通常は 1。テイラー近似の負誤差で 0.999... になった時のみ 0

    // ★ バグ修正: もし 0.999... になった場合は、フラクションの抽出位置をずらして正規化を補う
    wire [22:0] final_fraction = carry ? q_final[46:24] :
                                 norm  ? q_final[45:23] :
                                         q_final[44:22];

    // 0: p1, 1: 0, 2: m1, 3: m2
    wire [1:0] sel = st2_shift_pred ? 
                        (carry ? 2'd0 : (norm ? 2'd1 : 2'd2)) :
                        (carry ? 2'd1 : (norm ? 2'd2 : 2'd3));

    // 加算器を使わず、純粋なMUXだけで指数とフラグを選択
    wire [7:0] final_exp = (sel == 2'd0) ? st2_exp_p1 :
                           (sel == 2'd1) ? st2_exp_0 :
                           (sel == 2'd2) ? st2_exp_m1 :
                                           st2_exp_m2;

    wire ovf = (sel == 2'd0) ? st2_ovf_p1 :
               (sel == 2'd1) ? st2_ovf_0 :
               (sel == 2'd2) ? st2_ovf_m1 :
                               st2_ovf_m2;

    wire udf = (sel == 2'd0) ? st2_udf_p1 :
               (sel == 2'd1) ? st2_udf_0 :
               (sel == 2'd2) ? st2_udf_m1 :
                               st2_udf_m2;

    wire out_is_nan  = st2_nan;
    wire out_is_inf  = st2_inf  || ovf;
    wire out_is_zero = st2_zero || udf;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            result <= 32'b0;
            out_valid <= 1'b0;
        end else begin
            out_valid <= st2_valid;
            
            if (st2_valid) begin
                if (out_is_nan) begin
                    result <= QUIET_NAN;
                end else if (out_is_inf) begin
                    result <= {st2_sign, 8'hFF, 23'b0};
                end else if (out_is_zero) begin
                    result <= {st2_sign, 31'b0};
                end else begin
                    result <= {st2_sign, final_exp, final_fraction};
                end
            end
        end
    end

endmodule