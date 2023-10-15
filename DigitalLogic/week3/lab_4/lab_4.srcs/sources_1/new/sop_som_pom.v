`timescale 1ns / 1ps
/////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/10 17:53:09
// Design Name: 
// Module Name: sop_som_pom
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


module sop_som_pom(
    input a, b, c,
    output z1, z2, z3
    );
    // a + b'c
    assign z1 = a | (~b & c);
    // m1 + m4 + m5 + m6 + m7
    assign z2 = (~a & ~b & c) | (a & b & c) | (a & ~b & ~c) | (a & ~b & c) | (a & b & ~c);
    // M0 + M2 + M3
    assign z3 = (a | b | c) & (a | ~b | c) & (a | ~b | ~c);
endmodule
