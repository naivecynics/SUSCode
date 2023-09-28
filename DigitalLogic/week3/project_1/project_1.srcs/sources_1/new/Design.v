`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/26 17:07:45
// Design Name: 
// Module Name: Design
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


module Design(
    input x,
    input y,
    input z,
    output o1,
    output o2,
    output o3
    );

    assign o1 = x&y&z| x&y&~z;
    assign o2 = x&y&(z | ~z);
    assign o3 = x&y;
    
endmodule
