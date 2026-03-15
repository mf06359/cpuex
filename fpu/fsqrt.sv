`default_nettype none

module fsqrt (
    input wire logic clk,
    input wire logic rst_n,
    input wire logic [31:0] input_a,
    input wire logic input_valid,
    output logic [31:0] result,
    output logic out_valid
);

(* ram_style = "block" *) reg [47:0] lut [0:1023];

initial begin
  $readmemh("fsqrt_concat_table.mem", lut);
end

/* verilator lint_off UNUSEDSIGNAL */
logic [23:0] delta_24;
logic [2:0] is_zero_reg;
logic [2:0] is_pos_inf_reg; // 追加: +Inf専用の判定
logic [2:0] is_nan_neg_reg; // 変更: NaNおよび負の数用
logic [47:0] P_out;
logic [23:0] double_x1;
logic [7:0] exp_reg_plus;
logic [2:0] valid_reg;
/* verilator lint_on UNUSEDSIGNAL */

logic in_is_zero;
logic in_is_pos_inf;
logic in_is_nan_or_neg;

logic is_zero_final;
logic is_pos_inf_final;
logic is_nan_neg_final;

assign is_zero_final    = is_zero_reg[1];
assign is_pos_inf_final = is_pos_inf_reg[1];
assign is_nan_neg_final = is_nan_neg_reg[1];

// +Inf と NaN/負の数 を明確に分離する
assign in_is_zero       = (input_a[30:0] == 31'b0);
assign in_is_pos_inf    = (input_a == 32'h7F800000); 
assign in_is_nan_or_neg = (input_a[31] && input_a[30:0] != 31'b0) || 
                          ((&input_a[30:23]) && input_a[22:0] != 23'b0);

always_ff @(posedge clk) begin // or negedge rst_n
  if (!rst_n) begin
    valid_reg      <= 3'b000;
    is_zero_reg    <= 3'b000;
    is_pos_inf_reg <= 3'b000;
    is_nan_neg_reg <= 3'b000;
  end else begin
    valid_reg      <= {valid_reg[1:0], input_valid};
    is_zero_reg    <= {is_zero_reg[1:0], in_is_zero}; 
    is_pos_inf_reg <= {is_pos_inf_reg[1:0], in_is_pos_inf};
    is_nan_neg_reg <= {is_nan_neg_reg[1:0], in_is_nan_or_neg}; 
  end
end
logic s_1;
logic [7:0] e_1;
logic [22:0] m_1;

logic [7:0] exp_out;
logic sign_out;

logic [23:0] a_fixed;
logic [23:0] x_0;
logic [23:0] x0_x0;
logic [9:0] lut_addr;
assign lut_addr = {e_1[0], m_1[22:14]};
assign {s_1, e_1, m_1} = input_a; 

logic signed [8:0] e_wo_bias;
assign e_wo_bias = $signed({1'b0, e_1}) - 9'sd127;

always_ff @(posedge clk) begin
  x_0 <= lut[lut_addr][47:24];
  x0_x0 <= lut[lut_addr][23:0];
end

always_ff @(posedge clk) begin//or negedge rst_n
  if (!rst_n) begin
    exp_out <= 8'b0;
    sign_out <= 1'b0;
    a_fixed <= 24'b0;
  end else begin
    exp_out <= 8'((e_wo_bias >>> 1) + 8'd127);
    sign_out <= s_1;
    if (e_1[0]) begin
      a_fixed <= {2'b01, m_1[22:1]};
    end else begin
      a_fixed <= {1'b1, m_1};
    end
  end
end

logic [23:0] a_x0_x0;
logic [23:0] a_x0;

always_comb begin
  a_x0_x0 = 24'((48'(a_fixed) * x0_x0) >> 24);
  a_x0 = 24'((48'(a_fixed) * x_0) >> 24);
end

logic [23:0] a_x0_reg;
logic signed [17:0] delta_reg; 
logic [7:0] exp_reg;
logic [7:0] exp_reg_minus;
logic sign_reg;

assign delta_24 = 24'h400000 - a_x0_x0;

always_ff @(posedge clk) begin //or negedge rst_n
  if (!rst_n) begin
    delta_reg <= 18'sb0;
    a_x0_reg <= 24'b0;
    exp_reg <= 8'b0;
    exp_reg_plus <= 8'b0;
    exp_reg_minus <= 8'b0;
    sign_reg <= 1'b0;
  end else begin
    delta_reg <= delta_24[17:0]; 

    a_x0_reg <= a_x0;
    exp_reg <= exp_out;
    exp_reg_plus <= exp_out + 8'd1;
    exp_reg_minus <= exp_out - 8'd1;
    sign_reg <= sign_out;
  end
end

logic signed [24:0] a_x0_signed;
logic signed [42:0] delta_mult;
logic [23:0] result_inner;
logic [7:0] exp_final;
logic [22:0] mant_final;

always_comb begin
  a_x0_signed = {1'b0, a_x0_reg};
  delta_mult = a_x0_signed * delta_reg;
  P_out = {1'b0, a_x0_reg, 1'b0, 1'b1, 21'b0} + 48'($signed(delta_mult));
  result_inner = P_out[45:22];

  if (result_inner[23]) begin
    exp_final = exp_reg;
    mant_final = result_inner[22:0];
  end else begin
    exp_final = exp_reg_minus;
    mant_final = {result_inner[21:0], 1'b0};
  end       
end

// ===== 最終出力ブロック =====
// // ===== 最終出力ブロック =====
always_ff @(posedge clk) begin //or negedge rst_n
  if (!rst_n) begin
    result <= 32'b0;
    out_valid <= 1'b0;
  end else begin
    out_valid <= valid_reg[1];

    if (is_nan_neg_final) begin
      result <= 32'h7FC00000; // 負の数や NaN は Quiet NaN
    end else if (is_pos_inf_final) begin
      result <= 32'h7F800000; // +Inf の場合は +Inf をそのまま返す
    end else if (is_zero_final) begin
      result <= {sign_reg, 31'b0}; // 0 の場合は符号を維持 (+0 / -0)
    end else begin
      result <= {1'b0, exp_final, mant_final}; // 通常の計算結果
    end
  end
end
endmodule
