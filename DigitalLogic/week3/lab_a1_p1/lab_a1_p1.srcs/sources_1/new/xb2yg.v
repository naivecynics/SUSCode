`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/08 14:18:19
// Design Name: 
// Module Name: xb2yg
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


module xb2yg(
    input [3:0] xb,
    output [3:0] yg
    );

    and and_0 (yg[3], xb[3], xb[3]);
    xor xor_1 (yg[2], xb[2], xb[3]);
    xor xor_2 (yg[1], xb[1], xb[2]);
    xor xor_3 (yg[0], xb[0], xb[1]);

endmodule
