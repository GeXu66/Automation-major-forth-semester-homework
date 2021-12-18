clc;close all;
ube=[0.073	0.31	0.548	0.59	0.609	0.622	0.639	0.651	0.667];
Ib=[-0.00195	0.0003	0.00395	0.0179	0.03205	0.0474	0.0714	0.1135	0.17875];
%plot(ube,Ib,'color',[0,1.0,0],'linewidth',2);
%hold on
%scatter(ube,Ib,20,'r','filled');
ube2=[0.033	 0.309	0.588	0.67	0.684	0.705	0.708	0.712	0.73];
Ib2=[0.006	0.0001	0.00185	0.0136	0.0293	0.0427	0.06785	0.11045	0.17345];

x1=0:0.001:0.667;
x2=0:0.001:0.730;
a =  24.1;  
b =  20.57;
f1=a*b.*x1.^(b-1).*exp(-a.*x1.^b);
plot(x1,f1,'color',[0,1.0,0],'linewidth',2);
hold on 
scatter(ube,Ib,20,'r','filled');
hold on

c=57.32;
d=30.19;
f2=c*d.*x2.^(d-1).*exp(-c.*x2.^d);
plot(x2,f2,'color',[0,1.0,0],'linewidth',2)
hold on 
scatter(ube2,Ib2,20,'r','filled');
hold on