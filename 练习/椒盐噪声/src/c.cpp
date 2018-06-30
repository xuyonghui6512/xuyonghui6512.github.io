#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
void salt(Mat&,int);
int main(int argc,char**argv)
{
Mat srcImage=imread("1.jpg");
Mat grayImage;
cvtColor(srcImage,grayImage,CV_RGB2GRAY);
imshow("origin",srcImage);
Mat gray1dstImage,dstImage;
gray1dstImage=grayImage.clone();
dstImage=srcImage.clone();
salt(gray1dstImage,2300);
salt(dstImage,2200);
imshow("1",gray1dstImage);
imshow("2",dstImage);
waitKey(0);
return 0;
}
void salt(Mat&dst,int Saltnum)
{
int x,y;
for(int i=0;i<Saltnum;i++)
{
x=rand()%dst.cols;
y=rand()%dst.rows;
	if(dst.channels()==1)
{
dst.at<uchar>(y,x)=0;
}
if(dst.channels()==3)
{
dst.at<Vec3b>(y,x)[0]=0;
dst.at<Vec3b>(y, x)[1] = 255;
dst.at<Vec3b>(y, x)[2] = 0; 
}
}
}
