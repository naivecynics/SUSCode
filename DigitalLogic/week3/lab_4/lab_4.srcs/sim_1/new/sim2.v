`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/10 17:59:23
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
    reg sa, sb, sc;
    wire sz1, sz2, sz3;
    sop_som_pom sop_som_pom_DUT(
        .a(sa),
        .b(sb),
        .c(sc),
        .z1(sz1),
        .z2(sz2),
        .z3(sz3)
    );
    initial begin
        {sa, sb, sc}
    end
endmodule
