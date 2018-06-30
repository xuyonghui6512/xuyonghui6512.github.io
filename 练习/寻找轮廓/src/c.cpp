#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int agrc,char** agrv)
{
    Mat A=imread("1.jpg");
    Mat B,C;
    Scalar rgb;
    RNG g_rng(12345);//颜色定义？
    C=Mat::zeros(A.rows,A.cols,A.type());
    cvtColor(A,B,CV_BGR2GRAY);
   //GaussianBlur(A,B,Size(5,5),0,0);
   Canny(B,B,300,100,3);
   vector<vector<Point> > contours;
   findContours(B,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
   for(int i=0;i<contours.size()/2;i++)
   {
       Scalar Color=Scalar(g_rng.uniform(0,255),g_rng.uniform(0,255),g_rng.uniform(0,255));//随机颜色
         drawContours(C,contours,i,Color);
   }

   imshow("B",B);
   imshow("C",C);
   waitKey(0);
}
