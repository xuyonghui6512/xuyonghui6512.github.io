#include<opencv2/opencv.hpp>
using namespace cv;
int main(int argc,char**argv)
{
    Mat srcImage=imread("1.jpeg");
    imshow("origin picture",srcImage);
    Mat dstImage;
    blur(srcImage,dstImage,Size(7,7));
    imshow("blurred picture",dstImage);
    waitKey(0);
}
