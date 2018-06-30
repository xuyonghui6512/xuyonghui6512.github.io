#include<iostream>
#include<opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main(int argc,char**argv)
{
	Mat srcImg1=imread("11.png",1);
	Mat srcImg2=imread("12.png",1);
	//Mat ROI1=srcImg1(Rect(0,0,200,200));
	//Mat ROI2=srcImg2(Rect(0,0,200,200));
	

	Mat grayImg;
	//cvtColor(srcImg,grayImg,CV_BGR2GRAY);
	//Mat cpgrayImg;
	//cpgrayImg=grayImg.clone();
	//equalizeHist(cpgrayImg,cpgrayImg);
	//threshold(cpgrayImg,cpgrayImg,150,255,CV_THRESH_BINARY_INV);
	bitwise_xor(srcImg1,srcImg2,grayImg);
	imshow("1",grayImg);
	
	waitKey(0);
}
