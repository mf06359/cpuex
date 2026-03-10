module sev_seg_controller (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [15:0] sw,
    output logic [7:0]  seg_an,   // ★ 8桁に変更
    output logic [7:0]  seg_dat
);
    logic [31:0] data_in;
    assign data_in = sw;

    // --- 7セグデコーダ ---
    function automatic logic [7:0] hex_to_7seg(input logic [3:0] hex);
        case (hex)
            4'h0: hex_to_7seg = 8'b11000000;
            4'h1: hex_to_7seg = 8'b11111001;
            4'h2: hex_to_7seg = 8'b10100100;
            4'h3: hex_to_7seg = 8'b10110000;
            4'h4: hex_to_7seg = 8'b10011001;
            4'h5: hex_to_7seg = 8'b10010010;
            4'h6: hex_to_7seg = 8'b10000010;
            4'h7: hex_to_7seg = 8'b11111000;
            4'h8: hex_to_7seg = 8'b10000000;
            4'h9: hex_to_7seg = 8'b10010000;
            4'hA: hex_to_7seg = 8'b10001000;
            4'hB: hex_to_7seg = 8'b10000011;
            4'hC: hex_to_7seg = 8'b11000110;
            4'hD: hex_to_7seg = 8'b10100001;
            4'hE: hex_to_7seg = 8'b10000110;
            4'hF: hex_to_7seg = 8'b10001110;
            default: hex_to_7seg = 8'b11111111;
        endcase
    endfunction

    // --- 桁切り替えカウンタ ---
    logic [24:0] counter;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            counter <= 24'b0;
        else
            counter <= counter + 24'b1;
    end

    // --- 桁ごとの制御 ---
    logic [3:0] current_hex;
    always_comb begin
        seg_an = 8'b11111111;  // 全消灯
        case (counter[18:17])
            3'd0: begin current_hex = data_in[3:0];    seg_an = 8'b11111110; end
            3'd1: begin current_hex = data_in[7:4];    seg_an = 8'b11111101; end
            3'd2: begin current_hex = data_in[11:8];   seg_an = 8'b11111011; end
            3'd3: begin current_hex = data_in[15:12];  seg_an = 8'b11110111; end
        endcase
        seg_dat = hex_to_7seg(current_hex);
    end
endmodule

