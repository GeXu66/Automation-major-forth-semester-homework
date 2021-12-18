clc;close all;
uce1=[0.031 	0.086 	0.153 	0.222 	0.279 	0.680 	1.700 	2.134 	2.680 	3.559 ];
Ic1=[-0.060 	1.260 	2.480 	3.780 	5.210 	8.590 	10.210 	10.670 	11.680 	12.790 ];

uce2=[0.067 	0.083 	0.150 	0.215 	0.272 	0.530 	1.419 	1.885 	2.360 	3.239 ];
Ic2=[(0.360)	1.290 	2.560 	3.870 	5.120 	9.700 	11.520 	12.000 	12.520 	13.840];

uce22=[0.530 	1.419 	1.885 	2.360 	3.239];
Ic22=[9.700 	11.520 	12.000 	12.520 	13.840];

uce3=[0.065 	0.082 	0.147 	0.205 	0.272 	0.498 	];
Ic3=[(0.320)	1.310 	2.540 	3.940 	5.100 	10.490  ];

uce32=[0.498 	1.180 	1.660 	2.100 	3.000];
Ic32=[10.490 	13.010 	13.620 	14.010 	15.640];

x1=0:0.001:3.600;
x21=0:0.001:0.53;
x22=0.53:0.001:3.239;
x3=0:0.001:0.498;
x32=0.498:0.001:3.000;

y1=fittedmodel1(x1);
y2=fittedmodel2(x21);
y22=fittedmodel22(x22);
y3=fittedmodel3(x3);
y32=fittedmodel32(x32);

plot(x1,y1,'color',[0,1.0,0],'linewidth',2);
hold on 
scatter(uce1,Ic1,20,'r','filled');
hold on

plot(x21,y2,'color',[0,1.0,0],'linewidth',2);
hold on 
scatter(uce2,Ic2,20,'r','filled');
hold on

plot(x22,y22,'color',[0,1.0,0],'linewidth',2);
hold on 
scatter(uce22,Ic22,20,'r','filled');
hold on

plot(x3,y3,'color',[0,1.0,0],'linewidth',2);
hold on 
scatter(uce3,Ic3,20,'r','filled');
hold on

plot(x32,y32,'color',[0,1.0,0],'linewidth',2);
hold on 
scatter(uce32,Ic32,20,'r','filled');
hold on
