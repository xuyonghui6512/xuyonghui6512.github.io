#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc,char**argv)
{
	Mat srcImage=imread("1.png");
	Mat Image=imread("2.jpg");
	
	Mat B=Image.mul(srcImage);
	Mat A=B.t();	
	imshow("A",A);
	imshow("B",B);
	
	waitKey(0);
}

