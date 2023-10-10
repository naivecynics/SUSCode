`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/08 14:46:10
// Design Name: 
// Module Name: yg2xb
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


module yg2xb(
    input [3:0] xb,
    output [3:0] yg
    );
    genvar i;
    generate
        for (genvar i=0; i<3; i=i+1) begin: loop
            yg[i] = yg[i] ^ xb[i+1];
        end 
        yg[3] = xb[3] ^ 1'b1;
    endgenerate
endmodule
