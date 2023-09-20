`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/19 16:36:48
// Design Name: 
// Module Name: lab2_p1
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


module lab2_p1(
    input x,
    input y,
    input z,
    output F
    );
    
    wire notx, noty, notz;
    wire out1, out2, out3;
    
    not nx(notx, x);
    not ny(noty, y);
    and and1(out1, notx, noty, z);
    and and2(out2, notx, y, z);
    and and3(out3, x, noty);
    or (F, out1, out2, out3);
    
endmodule
