`timescale 1ns / 1ps

module tb_fdiv;

    // --------------------------------------------------------
    // DUT (Device Under Test) Connections
    // --------------------------------------------------------
    logic        clk;
    logic        rst_n;
    logic [31:0] input_a;
    logic [31:0] input_b;
    logic        input_valid;
    logic [31:0] result;
    logic        out_valid;

    // Instantiate the DUT
    fdiv u_dut (
        .clk        (clk),
        .rst_n      (rst_n),
        .input_a    (input_a),
        .input_b    (input_b),
        .input_valid(input_valid),
        .result     (result),
        .out_valid  (out_valid)
    );

    // --------------------------------------------------------
    // Testbench Variables & Structures
    // --------------------------------------------------------
    // Transaction structure to handle pipeline latency
    typedef struct {
        logic [31:0] a;
        logic [31:0] b;
        logic [31:0] expected;
        string       desc;
    } trans_t;

    trans_t scoreboard[$]; // Queue to store expected results
    int error_count = 0;
    int test_count = 0;

    // Clock Generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // --------------------------------------------------------
    // Helper Functions
    // --------------------------------------------------------

    // Convert bits to shortreal (float)
    function shortreal bits2real(logic [31:0] val);
        return $bitstoshortreal(val);
    endfunction

    // Convert shortreal (float) to bits
    function logic [31:0] real2bits(shortreal val);
        return $shortrealtobits(val);
    endfunction

    // Calculate expected result using SystemVerilog's native float math
    function logic [31:0] calc_expected(logic [31:0] a, logic [31:0] b);
        shortreal ra, rb, rres;
        ra = bits2real(a);
        rb = bits2real(b);
        rres = ra / rb;
        return real2bits(rres);
    endfunction

    // Check if a value is NaN (Exponent all 1s, Mantissa non-zero)
    function bit is_nan(logic [31:0] val);
        return (val[30:23] == 8'hFF) && (val[22:0] != 0);
    endfunction

    // --------------------------------------------------------
    // Task: Apply Input
    // --------------------------------------------------------
    task drive_input(input logic [31:0] a, input logic [31:0] b, input string description);
        trans_t tr;
        
        // Setup transaction
        tr.a = a;
        tr.b = b;
        tr.expected = calc_expected(a, b);
        tr.desc = description;

        // Drive signals
        @(posedge clk);
        input_a <= a;
        input_b <= b;
        input_valid <= 1'b1;
        
        // Push to scoreboard
        scoreboard.push_back(tr);
    endtask

    task stop_drive();
        @(posedge clk);
        input_valid <= 1'b0;
    endtask

    // --------------------------------------------------------
    // Monitor & Checker Process
    // --------------------------------------------------------
    initial begin
        forever begin
            @(posedge clk);
            if (out_valid) begin
                trans_t tr;
                logic [31:0] exp_val;
                logic [31:0] dut_val;
                
                // Pop the oldest transaction
                if (scoreboard.size() > 0) begin
                    tr = scoreboard.pop_front();
                    exp_val = tr.expected;
                    dut_val = result;
                    test_count++;

                    // Check result (Special handling for NaN because NaN != NaN)
                    if (is_nan(exp_val)) begin
                        if (!is_nan(dut_val)) begin
                            report_error(tr, dut_val, exp_val, "NaN Mismatch");
                        end
                    end else begin
                        if (dut_val !== exp_val) begin
                            // Check for 1-bit ULP error (optional tolerance for simple dividers)
                            if ((dut_val > exp_val && dut_val - exp_val == 1) || 
                                (exp_val > dut_val && exp_val - dut_val == 1)) begin
                                // Uncomment below to ignore 1-bit errors (rounding diffs)
                                report_error(tr, dut_val, exp_val, "LSB Mismatch (Rounding?)"); 
                            end else begin
                                report_error(tr, dut_val, exp_val, "Value Mismatch");
                            end
                        end
                    end
                end else begin
                    $error("Error: Received valid output but scoreboard is empty!");
                end
            end
        end
    end

    // --------------------------------------------------------
    // Reporting Task (The specific format requested)
    // --------------------------------------------------------
    task report_error(trans_t tr, logic [31:0] got, logic [31:0] exp, string msg);
        error_count++;
        $display("\n========================================================");
        $display("ERROR [%s]: %s", msg, tr.desc);
        $display("Input A : %h (%f)", tr.a, bits2real(tr.a));
        $display("Input B : %h (%f)", tr.b, bits2real(tr.b));
        $display("--------------------------------------------------------");
        $display("Field    | Expected (IEEE)       | Got (DUT)             | Match?");
        $display("--------------------------------------------------------");
        
        // Full Hex
        $display("Full Hex | %h             | %h             | %s", 
            exp, got, (exp == got) ? "OK" : "XX");

        // Sign Bit
        $display("Sign     | %b                     | %b                     | %s", 
            exp[31], got[31], (exp[31] == got[31]) ? "OK" : "XX");

        // Exponent
        $display("Exponent | %d (0x%2h)           | %d (0x%2h)           | %s", 
            exp[30:23], exp[30:23], got[30:23], got[30:23], 
            (exp[30:23] == got[30:23]) ? "OK" : "XX diff=%0d", $signed(got[30:23]) - $signed(exp[30:23]));

        // Mantissa
        $display("Mantissa | %h              | %h              | %s", 
            exp[22:0], got[22:0], 
            (exp[22:0] == got[22:0]) ? "OK" : "XX");
            
        $display("========================================================\n");
    endtask

    // --------------------------------------------------------
    // Main Stimulus
    // --------------------------------------------------------
    initial begin
        // Initialize
        rst_n = 0;
        input_valid = 0;
        input_a = 0;
        input_b = 0;
        
        repeat(5) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);

        $display("Starting Floating Point Divider Test...");

        // 1. Simple Cases (No Rounding needed usually)
        drive_input(32'h40800000, 32'h40000000, "4.0 / 2.0 = 2.0"); 
        drive_input(32'hC0800000, 32'h40000000, "-4.0 / 2.0 = -2.0");
        drive_input(32'h3F800000, 32'h3F800000, "1.0 / 1.0 = 1.0");

        // 2. Corner Cases (Zero, Inf, NaN)
        // Zero / Normal
        drive_input(32'h00000000, 32'h40000000, "0.0 / 2.0 = 0.0");
        // Normal / Zero -> Inf
        drive_input(32'h3F800000, 32'h00000000, "1.0 / 0.0 = Inf");
        // Inf / Normal -> Inf
        drive_input(32'h7F800000, 32'h40000000, "Inf / 2.0 = Inf");
        // Zero / Zero -> NaN
        drive_input(32'h00000000, 32'h00000000, "0.0 / 0.0 = NaN");

        stop_drive();
        repeat(10) @(posedge clk); // Allow pipeline to drain

        // 3. Random Testing
        $display("Starting Random Tests...");
        repeat(50) begin
            logic [31:0] ra, rb;
            ra = $random;
            rb = $random;
            // Avoid denormals for simpler checking if design doesn't support them
            if (ra[30:23] != 0 && rb[30:23] != 0) begin
                drive_input(ra, rb, "Random Vectors");
            end
        end

        stop_drive();
        repeat(20) @(posedge clk); // Wait for last results

        $display("Test Completed.");
        $display("Total Tests: %0d", test_count);
        $display("Total Errors: %0d", error_count);
        
        $finish;
    end

endmodule