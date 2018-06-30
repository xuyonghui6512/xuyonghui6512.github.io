%这是一个萌萌哒脚本文件~
%此脚本用来计算RGBD相机外部参数，世界坐标系固定于最大平面
%输入为TXT点云数据，输出为从摄像机坐标系到世界坐标系的RT01矩阵
%Author ： Starry 

[X,Y,Z,s] = textread('cloud.txt','%f %f %f %s');

M = [X Y Z];
%最小二乘解超定方程 x= [A B C] 平面方程 Ax + By + Cz = -1 
q = -ones(size(X));
x = M\q; 
A = x(1);
B = x(2);
C = x(3);
%世界坐标系XYZ向量 做归一化
format long;
X = [B^2 + C^2, -A*B,-A*C];
XF = sqrt(X(1)^2 + X(2)^2 + X(3)^2);
X = X/XF;
Y = [0,(A^2+B^2+C^2)*C,-(A^2+B^2+C^2)*B ];
YF = sqrt(Y(1)^2 + Y(2)^2 + Y(3)^2);
Y = Y/YF;
Z = [A,B,C];
ZF = sqrt(Z(1)^2 + Z(2)^2 +Z(3)^2);
Z = Z/ZF;
%RT01
R = [X;Y;Z]^(-1);
T = [0,-1/B,0]';
m = [R T;0 0 0 1]^(-1)
