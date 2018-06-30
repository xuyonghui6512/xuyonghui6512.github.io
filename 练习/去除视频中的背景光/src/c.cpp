#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
Mat calculateLightPattern(Mat img);
Mat quguang(Mat img,Mat pattern);
Mat quguangchufa(Mat img,Mat pattern);
int main(int agrc,char**agrv)
{
	VideoCapture cap(0);
	Mat frame;
	while(1)
{
	cap>>frame;
	medianBlur(frame,frame,3);
	Mat pattern;
	Mat result1,result2;
	Mat img_thr;	
	pattern=calculateLightPattern(frame);
	result1=quguang(frame,pattern);
	result2=quguangchufa(frame,pattern);
	//medianBlur(result2,result2,5);
	//imshow("result",result2);
	//imshow("result1",result1);
	imshow("frame",frame);
	threshold(result1,img_thr,15,255,THRESH_BINARY); //阀值来处理
	//imshow("img_",img_thr);
	int c=waitKey(30);
	if(c==27) break;
}
cap.release();
return 0;
	
}


