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
	Mat img32,pattern32;
	img.convertTo(img32,CV_32F);
	pattern.convertTo(pattern32,CV_32F);
	Mat result;
	result=1-(img32/pattern32);
	result=result*255;
        result.convertTo(result,CV_8U);
	return result;	
}
