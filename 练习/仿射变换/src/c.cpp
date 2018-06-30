#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc,char**argv)
{
    Point2f srcTr[3];//定义原图上三个点（三点确定一平面）
    Point2f dstTr[3];//目标图上三点
    Mat rotMat(2,3,CV_32FC1);//warp仿射矩阵和旋转矩阵都是2X3的
    Mat warpMat(2,3,CV_32FC1);
    Mat srcImage,dstImage_warp,dstImage_warp_rotate;
    srcImage=imread("1.jpeg",1);
    dstImage_warp=Mat::zeros(srcImage.rows,srcImage.cols,srcImage.type());
    srcTr[0]=Point2f(0,0);//原图3点与目标图3点以求仿射变换矩阵warpMat
    srcTr[1]=Point2f(static_cast<float>(srcImage.cols-1),0);
    srcTr[2]=Point2f(0,static_cast<float>(srcImage.rows-1));
    dstTr[0]=Point2f(static_cast<float>(srcImage.cols*0.0),static_cast<float>(srcImage.rows*0.33));
    dstTr[1]=Point2f(static_cast<float>(srcImage.cols*0.8),static_cast<float>(srcImage.rows*0.0));
     dstTr[2]=Point2f(static_cast<float>(srcImage.cols*0.5),static_cast<float>(srcImage.rows*0.8));
     warpMat=getAffineTransform(srcTr,dstTr);//来求warp矩阵，注意变换后那3点时对应的
     warpAffine(srcImage,dstImage_warp,warpMat,dstImage_warp.size(),CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );
     Point center=Point(dstImage_warp.cols/2,dstImage_warp.rows/2);//旋转中心
     double angle=-180;//旋转角度
      double scale=1.2;//放大倍数
       rotMat=getRotationMatrix2D(center,angle,scale);//旋转矩阵
       warpAffine(dstImage_warp,dstImage_warp_rotate,rotMat,dstImage_warp.size());
       imshow("origin",srcImage);
       imshow("warp",dstImage_warp);
        imshow("warp_rotation",dstImage_warp_rotate);
        waitKey(0);
         return 0;
}
