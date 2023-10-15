`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/10 16:58:07
// Design Name: 
// Module Name: SignedAdder
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


module SignedAdder(
    input [3:0] a,
    input [3:0] b, 
    output [7:0] sum,
    input signed [3:0] a_s,
    input signed [3:0] b_s,
    output signed [7:0] sum_s
    );

    assign sum = a + b;
    assign sum_s = a_s + b_s;
    
endmodule
