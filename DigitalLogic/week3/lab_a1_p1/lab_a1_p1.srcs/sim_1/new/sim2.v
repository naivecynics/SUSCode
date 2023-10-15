`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/10 17:23:06
// Design Name: 
// Module Name: sim2
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


module sim2();
    wire out_xb2yg, out_yg2xb;
    reg in_tb;

    xb2yg xb2yg_DUT(
        .xb(in_tb),
        .yg(out_xb2yg)
    );
    yg2xb yg2xb_DUT(
        .yg(in_tb),
        .xb(out_yg2xb)
    );

    initial begin
        //$monitor("%d %d %d", in_tb, out_xb2yg, out_yg2xb);
        in_tb = 4'b0000;
        repeat(15) #10 in_tb = in_tb + 1;
        #10 $finish;
    end
endmodule
