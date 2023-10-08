`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/01 00:04:50
// Design Name: 
// Module Name: lab_a1_p2
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


module lab_a1_p2(
    input A,
    input B,
    input C,
    input D,
    output X,
    output Y
    );
    //data flow method
    assign X = (~A ^~ D) | (~A | (B & C));
    assign Y = ~((~A) & (~A ^~ D)) & (~A | (B & C));

endmodule
