#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(int agrc,char**agrv)
{
    Mat srcImage=imread("1.jpeg");
    Mat midImage,dstImage;
    imshow("Origin",srcImage);
    cvtColor(srcImage,midImage,COLOR_BGR2GRAY);
    GaussianBlur(midImage,midImage,Size(9,9),2,2);
    vector<Vec3f> circles;
    HoughCircles(midImage,circles,HOUGH_GRADIENT,1.5,100,200,100,0,0);
    for(size_t i=0;i<circles.size();i++)
    {
        Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
        int r=cvRound(circles[i][2]);
        circle(srcImage,center,3,Scalar(0,0,255),-1,8,0);
        circle(srcImage,center,r,Scalar(255,0,0),3,8,0);
    }
    imshow("after",srcImage);
    waitKey(0);
    return 0;
}
