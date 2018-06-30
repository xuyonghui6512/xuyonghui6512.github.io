#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
void showHistoCallback(int ,void*);
void equaliseCallback(int ,void*);
void lomoCallback(int,void*);
void cartoonCallback(int ,void*);
 Mat srcImage=imread("1.jpg");
int main(int argc,char** argv)
{

    namedWindow("Input");
    createButton("Show histogram",showHistoCallback,NULL,QT_PUSH_BUTTON,0);
   createButton("Equalize histogram",equaliseCallback,NULL,QT_PUSH_BUTTON,0);
    createButton("Lomography effect",lomoCallback,NULL,QT_PUSH_BUTTON,0);
    createButton("Cartonize sffect",cartoonCallback,NULL,QT_PUSH_BUTTON,0);
    imshow("Input",srcImage);
    waitKey(0);
    return 0;
}

void showHistoCallback(int state,void* userData)
{
    vector<Mat> bgr;//将图像分割成3通道
    split(srcImage,bgr);
    //设置（R,G,B）范围，最后一个值不包含
    int numbins=256;
    float range[]={0,256};
    const float* histRange={range};
    Mat b_hist,g_hist,r_hist;
    calcHist(&bgr[0],1,0,Mat(),b_hist,1,&numbins,&histRange);
    calcHist(&bgr[1],1,0,Mat(),g_hist,1,&numbins,&histRange);
    calcHist(&bgr[2],1,0,Mat(),r_hist,1,&numbins,&histRange);
    //绘制直方图
    int width=512;
    int height=300;
    Mat histImage(height,width,CV_8UC3,Scalar(20,20,20));
    //从零到图像高度的归一化
    normalize(b_hist,b_hist,0,height,NORM_MINMAX);
    normalize(g_hist,g_hist,0,height,NORM_MINMAX);
    normalize(r_hist,r_hist,0,height,NORM_MINMAX);
    int binStep=cvRound((float)width/(float)numbins);
    for(int i=1;i<numbins;i++)
    {
        line(histImage,Point(binStep*(i-1),height-cvRound(b_hist.at<float>(i-1))),
             Point(binStep*(i),height-cvRound(b_hist.at<float>(i))),
             Scalar(255,0,0));
        line(histImage,Point(binStep*(i-1),height-cvRound(g_hist.at<float>(i-1))),
             Point(binStep*(i),height-cvRound(g_hist.at<float>(i))),
             Scalar(0,255,0));
        line(histImage,Point(binStep*(i-1),height-cvRound(r_hist.at<float>(i-1))),
             Point(binStep*(i),height-cvRound(r_hist.at<float>(i))),
             Scalar(0,0,255));


    }
    imshow("Histogram",histImage);
    waitKey(0);
}
void equaliseCallback(int state,void*userData)
{
    Mat result;
    Mat ycrcb;
    cvtColor(srcImage,ycrcb,COLOR_BGR2YCrCb);
    vector<Mat> channels;
    split(ycrcb,channels);
    equalizeHist(channels[0],channels[0]);
    merge(channels,ycrcb);
    cvtColor(ycrcb,result,COLOR_YCrCb2BGR);
    namedWindow("Equalized");
    imshow("Equalized",result);
    waitKey(0);
}
void lomoCallback(int stage,void* userData)
{
    Mat result;
    const double exponential_e=exp(1.0);
    Mat lut(1,256,CV_8UC1);
    for(int i=0;i<256;i++)
    {
        float x=(float)i/256.0;
        lut.at<uchar>(i)=cvRound(256*(1/(1+pow(exponential_e,-((x-0.5)/0.1)))));
    }
    vector<Mat> bgr;
    split(srcImage,bgr);
    LUT(bgr[2],lut,bgr[2]);
    merge(bgr,result);
    Mat halo(srcImage.rows,srcImage.cols,CV_32FC3,Scalar(0.3,0.3,0.3));
    circle(halo,Point(srcImage.cols/2,srcImage.rows/2),srcImage.cols/3,Scalar(1,1,1),-1);
    blur(halo,halo,Size(srcImage.cols/3,srcImage.cols/3));
    Mat resultf;
    result.convertTo(resultf,CV_32FC3);
    multiply(resultf,halo,resultf);
    resultf.convertTo(result,CV_8UC3);
    imshow("Lomograpy",result);
    waitKey(0);
}
void cartoonCallback(int state,void*userData)
{
    Mat imgMedian;
    //应用终止滤波器去除可能的噪声
    medianBlur(srcImage,imgMedian,7);
    //用Canny检测边缘
    Mat imgCanny;
    Canny(imgMedian,imgCanny,50,150);//即Canny前滤波去噪
    Mat kernel=getStructuringElement(MORPH_RECT,Size(2,2));//边缘膨胀的核
    dilate(imgCanny,imgCanny,kernel);
    imgCanny=imgCanny/255;//将边缘值缩放至1并翻转;
    imgCanny=1-imgCanny;//翻转
    Mat imgCannyf;
    imgCanny.convertTo(imgCannyf,CV_32FC3);
    //应用双边滤波器，实现色彩均匀化
    Mat imgBF;
    bilateralFilter(srcImage,imgBF,9,150.0,150.0);
    //截断颜色
    Mat result=imgBF/25;
    result=result*25;
    //为边缘创建三通道
    Mat imgCanny3c;
    Mat cannyChannels[]={imgCannyf,imgCannyf,imgCannyf};
    merge(cannyChannels,3,imgCanny3c);
    Mat resultf;
    result.convertTo(resultf,CV_32FC3);
    multiply(resultf,imgCanny3c,resultf);
    resultf.convertTo(result,CV_8UC3);
    imshow("Result",result);

    waitKey(0);
}
