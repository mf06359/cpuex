module cache (
    master_fifo.master fifo,
    input logic clk,
    input logic [31:0] input_data, 
    input logic [31:0] input_addr, 
    input logic readtrigger,
    input logic writetrigger,
    input logic reset_n,
    output logic req_rdy,
    output logic [31:0] output_data
);
このコードは、キャッシュメモリの実装を示しています。
仕様としては、
読む時、input_addrにアクセスして、output_dataにデータを出力する。input_dataは特に意味を持たない
書く時、input_addrにアクセスして、input_dataのデータを書き込む。output_dataは特に意味を持たない
readtriggerとwritetriggerは、どちらも同時に1になることはない。どちらかが1のときにアクセスする。このビットが立つ時間は1クロックサイクルである。
req_rdyが1のとき、アクセス可能である。また、アクセス可能な時は常にreq_rdyが1である。
readtriggerやwritetriggerが1になった次のクロックでreq_rdyが0になる。

req_rdyが0のときは、アクセスできない。req_rdyが0のときにreadtriggerやwritetriggerが1になっても、アクセスは開始されない。