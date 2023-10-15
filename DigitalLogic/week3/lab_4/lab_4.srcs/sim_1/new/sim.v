`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/10 17:03:07
// Design Name: 
// Module Name: sim
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module sim();
    reg [3:0] a;
    reg [3:0] b;
    wire [7:0] sum;
    reg signed [3:0] a_s;
    reg signed [3:0] b_s;
    wire signed [7:0] sum_s;

    SignedAdder DUT(
        .a(a),
        .b(b),
        .sum(sum),
        .a_s(a_s),
        .b_s(b_s),
        .sum_s(sum_s)
    );
    
    initial begin
        a = 0;
        b = 0;
        a_s = 0;
        b_s = 0;
    end

    always begin
        #10
        a = a + 1;
        b = b + 1;
        a_s = a_s + 1;
        b_s = b_s + 1;
    end
endmodule
