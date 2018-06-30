#include<iostream>
#include<opencv2/opencv.hpp>

#include<math.h>

using namespace std;
using namespace cv;
void translateTransform(cv::Mat const& src, cv::Mat& dst, int dx, int dy)  
{  
    //CV_Assert(src.depth() == CV_8U);  
    const int rows = src.rows;  
    const int cols = src.cols;  
    dst.create(rows, cols, src.type());  
    Vec3b *p;  
    for (int i = 0; i < rows; i++)  
    {  
        p = dst.ptr<Vec3b>(i);  
        for (int j = 0; j < cols; j++)  
        {  
            //平移后坐标映射到原图像  
            int x = j - dx;  
            int y = i - dy;  
            //保证映射后的坐标在原图像范围内  
            if (x >= 0 && y >= 0 && x < cols && y < rows)  
                p[j] = src.ptr<Vec3b>(y)[x];  
        }  
    }  
} 

int main(int argc,char**argv)
{
	Mat srcImage=imread("1.jpg");
	Mat dstImage;
	double x=srcImage.cols;
	double y=srcImage.rows;
	Mat B;
	int resize_x=2*srcImage.cols;
	int resize_y=2*srcImage.rows;
	double o=3.14/3.0;
	resize(srcImage,B,Size(resize_x,resize_y));
	Mat matrix=(Mat_<double>(2,3)<<1.1*cos(o),1.1*sin(o),((1-1.1*cos(o))*x-1.1*y*sin(o)),
	-1.1*sin(o),1.1*cos(o),(1.1*sin(o)*x+(1-1.1*cos(o))*y));
	warpAffine(srcImage,dstImage,matrix,B.size(),CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );
	
	translateTransform(dstImage,B,100,30);
	imshow("1",B);
	waitKey(0);
	
	
}
