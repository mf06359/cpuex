interface master_fifo;

    logic clk;

    logic req_en;
    logic req_rdy;

    logic rsp_en;
    logic rsp_rdy;

    typedef struct packed {
        logic cmd;
        logic [31:0] addr;
        logic [127:0] data;
    } req_t;

    typedef struct packed {
        logic [127:0] data;
    } rsp_t;

    req_t req;
    rsp_t rsp;

    modport master (
        output clk,
        output req_en,
        input req_rdy,
        output req,
        input rsp,
        input rsp_en,
        output rsp_rdy
    );

endinterface
