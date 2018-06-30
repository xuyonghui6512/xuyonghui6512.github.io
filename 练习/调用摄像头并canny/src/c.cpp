#include<stdio.h>
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc,char**argv)
{
    VideoCapture capture(0);//从摄像头读入视频
    if(!capture.isOpened())//判断是否读入视频
    {
    cout<<"NO!"<<endl;
    return -1;
    }
    while(1)
    {
        Mat frame;//用于存放每一帧图像
        capture>>frame;//读取当前帧
        Mat grayImage,edge;

        cvtColor(frame,grayImage,CV_RGB2GRAY);
        blur(grayImage,edge,Size(3,3));
        Canny(edge,edge,3,9,3);

        imshow("camera",edge);
        int c=waitKey(30);//延时30毫秒
        if(c==27)break;
    }
    return 0;
}
