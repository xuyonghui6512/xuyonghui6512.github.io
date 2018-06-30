
#include<opencv2/opencv.hpp>

using namespace cv;



int main(int argc ,const char** argv)
{
 Mat lena=imread("1.jpeg");
 imshow("show",lena);
 waitKey(0);

}
