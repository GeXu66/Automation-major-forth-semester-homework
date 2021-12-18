`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/05/25 11:36:15
// Design Name: 
// Module Name: traffic_light
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


module traffic_light(
    input clk,
    input enable,
    output [5:0] outseg
    );
    reg[26:0] divclk;
    reg[3:0] counter;
    reg[5:0] light;
    always@(posedge clk)
    begin
        if(divclk<100000000-1)
            divclk<=divclk+1;
        else
        begin
            divclk<=0;
            if(enable)
            begin
                if(counter<7)
                    counter <= counter+1;     
                else
                    counter <= 0;
            end
            else
            counter<=counter;
        end
        case(counter)
        //R Y G, north_east
        4'b0000:light<=6'b100_001;
        4'b0001:light<=6'b100_001;
        4'b0010:light<=6'b100_001;
        4'b0011:light<=6'b100_010;
        4'b0100:light<=6'b001_100;
        4'b0101:light<=6'b001_100; 
        4'b0110:light<=6'b001_100;
        4'b0111:light<=6'b010_100;
        endcase
    end    
    assign outseg = light;
endmodule
