clc;close all;
f=[50 100 1000 10000 100000 200000 500000];
lgf=log10(f);
Au=[0.968 0.964 0.964 0.970 0.958 0.841 0.474];

x=1.6:0.01:6;
y=fittedmodel(x);

plot(x,y,'color',[0.3020 0.7451 0.9333],'linewidth',2);
hold on;
scatter(lgf,Au,20,[1.0000 0.4118 0.1608],'filled');