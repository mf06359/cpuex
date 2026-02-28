## CacheControllerの使い方

`top.sv`を見たらある程度分かるかもしれないけど一応説明。

```
cachecontroller cache(
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
    input logic        reset_n,

    input logic        writetrigger,  // Write
    input logic        readtrigger, // Read
    input logic [31:0] input_addr,
    input logic [31:0] input_data,
    output logic       req_rdy,
    output logic [31:0] output_data,
    output logic        cpu_clk_out
);
```

|ポート|意味|使い方|
|-----|-----|-----|
|ddr2_XXX|DDR2利用のためのポート|無視してよい|
|clk|クロック入力|FPGAクロックをつなげる|
|reset_n|リセット信号|つなぐ|
|writetrigger|書きたいですという信号|req_rdyが立っているときに1クロック立てればよい|
|readtrigger|読みたいですという信号|req_rdyが立っているときに1クロック立てればよい|
|input_addr|このアドレスに読みたい(書きたい)ですと知らせる|渡せばよい|
|input_data|このデータを書きたいですと知らせる(読みたいときは何でもよい)|渡せばよい|
|req_rdy|今キャッシュは要求を受け付けられますよという信号|これが1の時にtriggerを立てることで読み書きができる|
|output_data|読んだデータ|読んだときにここにデータが出力される|
|cpu_clk_out|中のクロックウィザードで生成されたCPU用のクロック|CPUにつなげる|