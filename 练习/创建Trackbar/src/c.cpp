#include<opencv2/opencv.hpp>
using namespace cv;
#define Window  "显示图像"
//全局变量声明
const int g_nMaxAlphaValue=100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;
Mat g_srcImage,g_srcImage1,g_srcImage2,g_gray;
void on_Trackbar(int ,void*)
{
//求出当前alpha值相对于最大值的比例
g_dAlphaValue=(double)g_nAlphaValueSlider/g_nMaxAlphaValue;
g_dBetaValue=(1-g_dAlphaValue);
addWeighted(g_srcImage1,g_dAlphaValue,g_gray,g_dBetaValue,0.0,g_srcImage);
imshow(Window,g_srcImage);
}
int main(int agrc,char**agrv)
{
g_srcImage1=imread("1.jpg");
g_srcImage2=imread("5.jpg");
cvtColor(g_srcImage2,g_gray,CV_BGR2HSV);
if(!g_srcImage1.data)
{
return -1;}
if(!g_srcImage2.data)
{
return -1;

}


g_nAlphaValueSlider=70;  //初始值
namedWindow(Window,1);
char TrackbarName[50];
sprintf(TrackbarName,"透明值%d",g_nMaxAlphaValue);
createTrackbar(TrackbarName,Window,&g_nAlphaValueSlider,g_nMaxAlphaValue,on_Trackbar);
on_Trackbar(g_nAlphaValueSlider,0);
waitKey(0);
return 0;
}
