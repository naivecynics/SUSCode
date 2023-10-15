`timescale 1ns / 1ps

module sim_3();
    reg [1:0] a_tb;
    reg [1:0] b_tb;
    wire [2:0]sum_tb;
    lab3_practic_add2bit lab3_practic_add2bit_0(
        .a(a_tb),
        .b(b_tb),
        .sum(sum_tb)
        );
    initial begin
        $monitor ("%d %d %d", a_tb, b_tb, sum_tb);
        {a_tb, b_tb} =4'b0000;
        repeat(15) #10 {a_tb, b_tb} = {a_tb, b_tb} + 1;
        #10 $finish;
    end
endmodule