#include<opencv2/opencv.hpp>
using namespace cv;
int main(int argc,char**argv)
{
    Mat srcImage=imread("1.jpeg");
    imshow("origin picture",srcImage);
    Mat edge,grayImage;
    cvtColor(srcImage,grayImage,CV_BGR2GRAY);//将有颜色的图转变成灰度图
    blur(grayImage,edge,Size(3,3));
    Canny(edge,edge,3,9,3);
    imshow("edged picture",edge);
    waitKey(0);
    return 0;
}
