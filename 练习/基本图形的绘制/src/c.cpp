#include<opencv2/opencv.hpp>
using namespace cv;
#define WINDOW_EIDTH 600
void DrawEllipse(Mat img,double angle)
{
    int thickness=2;
    int linetype=8;
    ellipse(img,Point(300,300),Size(150,600/16),angle,0,360,Scalar(255,129,0),thickness,linetype);
}
void DrawFilledCircle(Mat img,Point center)
{
    int thickness=-1;
    int linetype=8;
    circle(img,center,600/32,Scalar(0,0,255),thickness,linetype);
}
int main(int argc,char**argv)
{
    Mat atomImage=Mat::zeros(600,600,CV_8UC3);
    DrawEllipse(atomImage,90);
    DrawEllipse(atomImage,0);
    DrawEllipse(atomImage,45);
    DrawEllipse(atomImage,-45);
    DrawFilledCircle(atomImage,Point(300,300));
    imshow("show",atomImage);
    waitKey(0);
}
