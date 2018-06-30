#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;


#define WINDOW_NAME1 "yuantu"
#define WINDOW_NAME2 "xiaoguotu"


Mat g_srcImage; Mat g_templateImage; Mat g_resultImage;
int g_nMatchMethod;
double minValue; double maxValue; Point minLocation; Point maxLocation;
Point matchLocation;





int main(  )
{
    g_templateImage = imread( "2.jpg", 1 );
    resize(g_templateImage,g_templateImage,Size(),0.5,0.5);
    VideoCapture capture(0);//从摄像头读入视频
    if(!capture.isOpened())//判断是否读入视频
    {
    cout<<"NO!"<<endl;
    return -1;
    }
    while(1)
    {
        Mat frame;//用于存放每一帧图像
        capture>>g_srcImage;//读取当前帧
        Mat srcImage;
        g_srcImage.copyTo( srcImage );

        int resultImage_cols =  g_srcImage.cols - g_templateImage.cols + 1;
        int resultImage_rows = g_srcImage.rows - g_templateImage.rows + 1;
        g_resultImage.create( resultImage_cols, resultImage_rows, CV_32FC1 );
        matchTemplate( g_srcImage, g_templateImage, g_resultImage, g_nMatchMethod );
        normalize( g_resultImage, g_resultImage, 0, 1, NORM_MINMAX, -1, Mat() );


        double minValue; double maxValue; Point minLocation; Point maxLocation;
        Point matchLocation;
        minMaxLoc( g_resultImage, &minValue, &maxValue, &minLocation, &maxLocation, Mat() );


        if( g_nMatchMethod  == TM_SQDIFF || g_nMatchMethod == TM_SQDIFF_NORMED )
        {matchLocation = minLocation; }
        else
        { matchLocation = maxLocation; }


        rectangle( srcImage, matchLocation, Point( matchLocation.x + g_templateImage.cols , matchLocation.y + g_templateImage.rows ), Scalar(0,0,255), 2, 8, 0 );
       // rectangle( g_resultImage, matchLocation, Point( matchLocation.x + g_templateImage.cols , matchLocation.y + g_templateImage.rows ), Scalar(0,0,255), 2, 8, 0 );
       Mat ImageRoi= srcImage(Rect(matchLocation.x,matchLocation.y,matchLocation.x + g_templateImage.cols-matchLocation.x,matchLocation.y + g_templateImage.rows-matchLocation.y));

       //resize(C,C,Size(matchLocation.x + g_templateImage.cols-matchLocation.x-1,matchLocation.y + g_templateImage.rows-matchLocation.y-1));
       //resize(C,C,Size(),0.1,0.1);
        //g_templateImage .copyTo(srcImage(ImageRoi));
        imshow( WINDOW_NAME1, srcImage );
        imshow("2",ImageRoi);



        waitKey(30);//延时30毫秒
    }

    return 0;





}



