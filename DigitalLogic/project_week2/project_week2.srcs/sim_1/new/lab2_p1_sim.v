`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/19 19:42:26
// Design Name: 
// Module Name: lab2_p1_sim
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


module lab2_p1_sim(

    );

    

    reg a_th, b_th, c_th;
    wire f_th;

    lab2_p1 u1(a_th, b_th, c_th, f_th);

    initial begin
        {a_th, b_th, c_th} = 3'b000;
        #80 $finish;
    end

    always begin
        #10 {a_th, b_th, c_th} = {a_th, b_th, c_th} + 1;
    end

endmodule
