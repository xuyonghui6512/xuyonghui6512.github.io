#include<opencv2/opencv.hpp>
using namespace cv;

int main(int agrc,char**agrv)
{
 Mat srcImage=imread("1.jpeg");
 A=srcImage.clone();
 imshow("origin picture",srcImage);
 //进行腐蚀操作
 Mat element=getStructuringElement(MORPH_ELLIPSE,Size(20,20));//返回指定形状和尺寸的元素结构（内核矩阵）
 Mat dstImage;
 Mat element1=getStructuringElement(MORPH_RECT,Size(30,30));
 Mat dstImage1;
 erode(srcImage,dstImage,element);//腐蚀ercode
 blur(A,A,)
  erode(srcImage,dstImage1,element1);
 imshow("Eroded Picture",dstImage);
 imshow("Eroded Pinctue1",dstImage1);
 waitKey(0);
}
