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


    wire and_BC,nand_out,A_not,or_out,xnor_out;
    not not_A(A_not, A);
    and and_1(and_BC, B, C);
    and and_2(Y, nand_out, xnor_out);
    or or_1(or_out, and_BC, A_not);
    or or_2(X, nand_out, or_out);
    nand nand_1(nand_out, A_not, xnor_out);
    xnor xnor_1(xnor_out, D, A_not);
    
endmodule
