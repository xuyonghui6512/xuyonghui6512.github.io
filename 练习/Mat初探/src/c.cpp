#include<opencv2/opencv.hpp>
using namespace cv;
Mat A=imread("1.jpeg");
int main(int argc,char**argv)
{
    Mat B(A);
    imshow("1",B);
    Mat C(A,Rect(10,10,100,100));//仅显示Rect区域的图像
    imshow("2",C);
    waitKey(0);


}
