`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/05/25 11:10:04
// Design Name: 
// Module Name: comb_test
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


module comb_test(
    input a,
    input b,
    input c,
    input d,
    input sel,
    output out,
    output out_inv
);
wire in_0,in_1;
nand module1(in_0,a,b);
and module2(in_1,c,d);
assign out=sel?in_0:in_1;
assign out_inv=~out;
endmodule
