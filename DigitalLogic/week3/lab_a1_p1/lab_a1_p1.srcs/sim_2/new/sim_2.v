`timescale 1ns / 1ps

module sim2();
    wire [3:0] out_xb2yg;
    wire [3:0] out_yg2xb;
    reg [3:0] in_tb;

    xb2yg xb2yg_DUT(
        .xb(in_tb),
        .yg(out_xb2yg)
    );
    yg2xb yg2xb_DUT(
        .yg(in_tb),
        .xb(out_yg2xb)
    );

    initial begin
        $monitor("%d %d %d", in_tb, out_xb2yg, out_yg2xb);
        in_tb = 4'b0000;
        repeat(15) #10 in_tb = in_tb + 1;
        #10 $finish;
    end
endmodule