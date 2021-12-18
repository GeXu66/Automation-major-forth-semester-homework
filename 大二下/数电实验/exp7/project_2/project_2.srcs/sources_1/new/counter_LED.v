`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/05/25 11:17:53
// Design Name: 
// Module Name: counter_LED
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


module counter_LED(
    input clk,
    input enable,
    output [3:0] out
    );
    reg[26:0] divclk;
    reg[3:0] reg4;
    always@(posedge clk)
        begin
            if (divclk< 100000000-1)
            divclk<=divclk+1;
            else
                begin
                divclk<=0;
                if (enable)
                    begin
                        if (reg4<9)
                            reg4<=reg4+1;
                        else
                            reg4<=0;
                    end
                else
                    reg4<=reg4;
                end
        end
    assign out = reg4;
endmodule
