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
    input [3:0] yg,
    output [3:0] xb
    );
    generate
        for (genvar i=0; i<3; i=i+1) begin: loop
            xnor xnor_1 (xb[i], yg[i], xb[i+1]);
        end 
        and and_1 (xb[3], yg[3], 1'b1);
        //yb[3] = xb[3];
    endgenerate
endmodule
