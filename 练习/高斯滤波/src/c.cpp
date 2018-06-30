#include<opencv2/opencv.hpp>
using namespace cv;
int main(int agrc,char**agrv)
{
Mat A=imread("1.jpeg");
Mat B;
imshow("Origin",A);
GaussianBlur(A,B,Size(5,5),0,0);
imshow("Gaussian Picture",B);
waitKey(0);

}
