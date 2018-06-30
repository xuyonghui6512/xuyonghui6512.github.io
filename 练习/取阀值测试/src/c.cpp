#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int agrc,char**agrv)
{
    Mat A=imread("1.jpg");
    Mat C;
    Mat B=Mat::zeros(A.rows,A.cols,A.type());
    imshow("SHOW1",B);
    A=A>129;//A图取阀值大于120那部分
    imshow("SHOW2",A);
    addWeighted(A,0.5,B,0.3,0.0,C);
    imshow("SHOW3",C);
    waitKey(0);
}
