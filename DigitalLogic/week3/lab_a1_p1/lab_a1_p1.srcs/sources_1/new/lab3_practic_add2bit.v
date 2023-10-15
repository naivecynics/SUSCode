`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/11 09:21:15
// Design Name: 
// Module Name: lab3_practic_add2bit
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


module lab3_practic_add2bit(
    input [1:0] a,
    input [1:0] b,
    output [2:0] sum
    );
    assign sum[0] = a[0] ^ b[0];
    assign sum[1] = a[1] ^ b[1] ^ (a[0] & b[0]);
    assign sum[2] = (a[1] & b[1]) | (a[0] & b[0] & b[1]) | (b[0] & a[1] & a[0]);
endmodule
