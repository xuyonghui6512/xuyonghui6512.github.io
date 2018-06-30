#include<opencv2/opencv.hpp>
using namespace cv;
int main(int argc,char**argv)
{
	Mat srcImage=imread("1.jpg");
	Mat logo=imread("2.jpg");
	namedWindow("原画");
	imshow("原画",srcImage);
	namedWindow("logo");
	imshow("logo",logo);
	Mat imageROI;
    //imageROI=srcImage(Rect(0,0,logo.cols,logo.rows));
    imageROI=srcImage(Range(100,100+logo.rows),Range(200,200+logo.cols));
    addWeighted(imageROI,0.9,logo,0.3,0.,imageROI);//srcImage占0.9的比重 logo占0.3的比重
	namedWindow("混合");
	imshow("混合",srcImage);
	imwrite("混合后的图.jpg",srcImage);
	waitKey(0);
	return 0;
}
