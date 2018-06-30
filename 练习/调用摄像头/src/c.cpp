#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc,char**argv)
{
    VideoCapture capture(0);//从摄像头读入视频
                        //若要读取视频只需将0改成视频地址
    if(!capture.isOpened())//判断是否读入视频
    {
    cout<<"NO!"<<endl;
    return -1;
    }
    while(1)
    {
        Mat frame;//用于存放每一帧图像
        capture>>frame;//获取摄像头或者视频给的当前帧
        imshow("camera",frame);
        int c=waitKey(30);//延时30毫
        if(c==27)break;
    }
    capture.release();//释放摄像机或者视频
    return 0;
}
