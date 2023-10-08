`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/30 22:51:45
// Design Name: 
// Module Name: lab_a1_p1
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


module lab_a1_p1(
    input A,
    input B,
    input C,
    input D,
    output X,
    output Y
    );

    wire A_not, nand_out, or_out, and_out, xnor_out;
    not not_A (A_not, A);
    nand nand_1 (nand_out, A_not, xnor_out);
    or or_1 (or_out, A_not, and_out);
    and and_1 (and_out, B, C);
    xnor xnor_1 (xnor_out, A_not, D);
    or or_2 (X, or_out, xnor_out);
    and and_2 (Y, nand_out, or_out);
    
endmodule
