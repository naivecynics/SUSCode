`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/10 18:05:15
// Design Name: 
// Module Name: sim3
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


module sim3();
    reg x, y, z;
    wire F;
    p3 DUT(
        .x(x),
        .y(y),
        .z(z),
        .F(F)
    );
    initial begin
        {x, y, z} = 3'b000;
        repeat (7) begin
            #10 {x, y, z} = {x, y, z} + 1;
        end
    end
endmodule
