module top (
    // DDR2
    output wire [12:0] ddr2_addr,
    output wire [2:0] ddr2_ba,
    output wire ddr2_cas_n,
    output wire [0:0] ddr2_ck_n,
    output wire [0:0] ddr2_ck_p,
    output wire [0:0] ddr2_cke,
    output wire ddr2_ras_n,
    output wire ddr2_we_n,
    inout  wire [15:0] ddr2_dq,
    inout  wire [1:0] ddr2_dqs_n,
    inout  wire [1:0] ddr2_dqs_p,
    output wire [0:0] ddr2_cs_n,
    output wire [1:0] ddr2_dm,
    output wire [0:0] ddr2_odt,
    // others
    input logic clk,
    input logic reset_n,

    output logic [31:0] output_monitor 
);

    logic [31:0] input_data;
    logic [31:0] input_addr;
    logic [31:0] output_data;    

    logic readtrigger;
    logic writetrigger;
    logic req_rdy;
    
    logic cpu_clk; 

    assign cpu_clk = clk; 

    /*
     * ここにコアを追加する形で利用するとよいと思う
     */


    assign output_monitor = output_data;

    cachecontroller cachecontroller_inst (
        .ddr2_addr(ddr2_addr),
        .ddr2_ba(ddr2_ba),
        .ddr2_cas_n(ddr2_cas_n),
        .ddr2_ck_n(ddr2_ck_n),
        .ddr2_ck_p(ddr2_ck_p),
        .ddr2_cke(ddr2_cke),
        .ddr2_ras_n(ddr2_ras_n),
        .ddr2_we_n(ddr2_we_n),
        .ddr2_dq(ddr2_dq),
        .ddr2_dqs_n(ddr2_dqs_n),
        .ddr2_dqs_p(ddr2_dqs_p),
        .ddr2_cs_n(ddr2_cs_n),
        .ddr2_dm(ddr2_dm),
        .ddr2_odt(ddr2_odt),
        
        .clk(clk),
        .reset_n(reset_n),
        
        .writetrigger(writetrigger),
        .readtrigger(readtrigger),
        .input_addr(input_addr),
        .input_data(input_data),
        .req_rdy(req_rdy),
        .output_data(output_data),
        .cpu_clk_out(cpu_clk) 
    );

endmodule