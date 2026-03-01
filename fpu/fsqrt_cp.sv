`default_nettype none

module fsqrt (
    input wire logic clk,
    input wire logic rst_n,
    input wire logic [31:0] input_a,
    input wire logic input_valid,
    output logic [31:0] result,
    output logic out_valid
);

// ==========================================
// 1. メモリの読み込み
// ==========================================
(* ram_style = "block" *) reg [23:0] lut [0:1023];
(* ram_style = "block" *) reg [23:0] lut_sq [0:1023];

initial begin
  $readmemh("fsqrt_table.hex", lut);
  $readmemh("fsqrt_sq_table.hex", lut_sq);
end

// ==========================================
// 2. 制御信号（ここだけ非同期リセットをかける）
// ==========================================
logic [2:0] valid_reg;
logic [2:0] is_zero_reg;
logic [2:0] is_abnormal_reg;

logic [7:0] e_in;
logic [22:0] m_in;
assign e_in = input_a[30:23];
assign m_in = input_a[22:0];

always_ff @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    valid_reg <= 3'b000;
    is_abnormal_reg <= 3'b000;
    is_zero_reg <= 3'b000;
  end else begin
    valid_reg <= {valid_reg[1:0], input_valid};
    is_abnormal_reg <= {is_abnormal_reg[1:0], (e_in == 8'hFF)};
    is_zero_reg <= {is_zero_reg[1:0], (e_in == 8'b0 && m_in == 23'b0)}; 
  end
end

assign out_valid = valid_reg[2];

// ==========================================
// 3. データパス Stage 1 (リセットを排除し、高速化)
// ==========================================
logic s_1;
logic [7:0] e_1;
logic [22:0] m_1;
assign {s_1, e_1, m_1} = input_a; 

logic [23:0] x_0, x0_x0;
logic [9:0] lut_addr;
assign lut_addr = {e_1[0], m_1[22:14]};

logic [7:0] exp_out;
logic sign_out;
logic [23:0] a_fixed;

// 💡 変更点：negedge rst_n を削除
always_ff @(posedge clk) begin
  x_0 <= lut[lut_addr];
  x0_x0 <= lut_sq[lut_addr];
  
  exp_out <= ($signed({1'b0, e_1}) - 9'sd127 >>> 1) + 8'd127;
  sign_out <= s_1;
  
  if (e_1[0]) a_fixed <= {2'b01, m_1[22:1]};
  else        a_fixed <= {1'b1, m_1};
end

// ==========================================
// 4. データパス Stage 2 (DSP48内部レジスタへの吸収)
// ==========================================
// 💡 変更点：VivadoにDSPブロックの使用を強制する属性を付与
(* use_dsp = "yes" *) logic [47:0] a_x0_x0;
(* use_dsp = "yes" *) logic [47:0] double_x1_tmp;
(* use_dsp = "yes" *) logic [23:0] a_x0;

always_comb begin
  a_x0_x0 = 48'(a_fixed) * x0_x0;
  double_x1_tmp = 48'hC00000_000000 - a_x0_x0;
  a_x0 = (48'(a_fixed) * x_0) >> 24;
end

logic [23:0] double_x1;
logic [23:0] a_x0_reg;
logic [7:0] exp_reg, exp_reg_plus, exp_reg_minus;
logic sign_reg;

// 💡 変更点：ここもネガティブエッジリセットを削除
always_ff @(posedge clk) begin
  double_x1 <= double_x1_tmp[47:24];
  a_x0_reg <= a_x0;
  exp_reg <= exp_out;
  exp_reg_plus <= exp_out + 8'd1;
  exp_reg_minus <= exp_out - 8'd1;
  sign_reg <= sign_out;
end

// ==========================================
// 5. データパス Stage 3
// ==========================================
(* use_dsp = "yes" *) logic [47:0] mul_reg;
logic [24:0] result_inner;
logic [7:0] exp_final;
logic [22:0] mant_final;

always_comb begin
  mul_reg = 48'(a_x0_reg) * double_x1 + 48'h000000_200000;
  result_inner = mul_reg[46:22];

  if (result_inner[24]) begin
    exp_final = exp_reg_plus;
    mant_final = result_inner[23:1];
  end else if (result_inner[23]) begin
    exp_final = exp_reg;
    mant_final = result_inner[22:0];
  end else begin
    exp_final = exp_reg_minus;
    mant_final = {result_inner[21:0], 1'b0};
  end       
end

// 最終出力だけはシステム要件に合わせてリセットを残す
always_ff @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    result <= 32'b0;
  end else begin
    if (is_zero_reg[1]) begin
      result <= {sign_reg, 8'b0, 23'b0};
    end else if (is_abnormal_reg[1]) begin
      result <= {sign_reg, 8'hFF, 23'b0};
    end else begin
      result <= {sign_reg, exp_final, mant_final};
    end
  end
end

endmodule
