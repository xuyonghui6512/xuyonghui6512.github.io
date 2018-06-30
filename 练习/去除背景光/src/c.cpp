#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
Mat calculateLightPattern(Mat img)
{
	Mat pattern;
	blur(img,pattern,Size(img.cols/3,img.rows/3));//将原图大核模糊可近似作为光图近似值
	return pattern;
}
Mat quguang(Mat img,Mat pattern)
{
	Mat result;
	result=pattern-img;
	return result;
}
Mat quguangchufa(Mat img,Mat pattern)
{
	Mat result;
	result=pattern-img;
	return result;	
}
int main(int agrc,char**agrv)
{
	Mat srcImage=imread("1.jpg");
	Mat pattern;
	Mat result1,result2;
	imshow("orgin",srcImage);
	pattern=calculateLightPattern(srcImage);
	result1=quguang(srcImage,pattern);
	result2=quguangchufa(srcImage,pattern);
	imshow("chafen",result1);
	imshow("chufa",result2);
	imshow("pattern",pattern);
	waitKey(0);

	
}

