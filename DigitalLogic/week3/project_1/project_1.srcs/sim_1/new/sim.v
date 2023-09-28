`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/26 17:26:57
// Design Name: 
// Module Name: sim
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


module sim(

    );

    reg simx,simy;
    wire simq1,simq2,simq3;
    Design DUT(
        .x(simx),
        .y(simy),
        .z(1'b1),
        .o1(simq1),
        .o2(simq2),
        .o3(simq3)
        );
    initial begin 
        simx = 1'b0;
        simy = 1'b0;
        #10;
        simx = 1'b1;
        simy = 1'b0;
        #10;
        simx = 1'b0;
        simy = 1'b1;
        #10;
        simx = 1'b1;
        simy = 1'b1;
        #10;
        $finish;
    end
endmodule
