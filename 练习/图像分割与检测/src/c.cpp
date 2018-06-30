#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
Mat calculateLightPattern(Mat img);
Mat quguang(Mat img,Mat pattern);
Mat quguangchufa(Mat img,Mat pattern);
//void ConnectedComponents(Mat img);
void ConnectedComponentsStats(Mat img);
static Scalar randomColor( RNG& rng )  
{  
  int icolor = (unsigned) rng;  
  return Scalar( icolor&255, (icolor>>8)&255, (icolor>>16)&255 );  
}  
int main(int agrc,char**agrv)
{
	Mat srcImage=imread("1.jpg");
	medianBlur(srcImage,srcImage,3);
	Mat element=getStructuringElement(MORPH_ELLIPSE,Size(7,7));
	dilate(srcImage,srcImage,element);
	erode(srcImage,srcImage,element);
	Mat pattern;
	Mat result1,result2;
	Mat img_thr;	
	pattern=calculateLightPattern(srcImage);
	result1=quguang(srcImage,pattern);
	result2=quguangchufa(srcImage,pattern);	
	//imshow("result",result2);
	//imshow("result1",result1);
	//imshow("srcImage",srcImage);
	threshold(result1,img_thr,40,255,THRESH_BINARY); //阀值来处理
	cvtColor(img_thr,img_thr,CV_RGB2GRAY);//因为
	ConnectedComponentsStats(img_thr);
	//Mat img1;
	//img_thr.convertTo(img1,CV_8SC1);
	//imshow("img_",img_thr);
	//ConnectedComponents(img1);
	
	waitKey(0);

	
}
Mat calculateLightPattern(Mat img)
{
	Mat pattern;
	blur(img,pattern,Size(img.cols/2,img.rows/2));//将原图大核模糊可近似作为光图近似值
	return pattern;
}
Mat quguang(Mat img,Mat pattern)
{
	Mat result;
	result=pattern-img;
	return result;

}
Mat quguangchufa(Mat img,Mat pattern)
{
	Mat img32,pattern32;
	img.convertTo(img32,CV_32F);
	pattern.convertTo(pattern32,CV_32F);
	Mat result;
	result=1-(img32/pattern32);
	result=result*255;
        result.convertTo(result,CV_8UC1);
	return result;	
}
/*void ConnectedComponents(Mat img)
{
	img.convertTo(img,CV_8UC1);
    Mat labels=img.clone();
    //检测到连通区域的数目给lebels
    int num_objects=connectedComponents(img,labels);
    if(num_objects<2)//1的时候应该是只有背景（个人理解）
    {
        cout<<"No object detected"<<endl;
        return;
    }
    else
    {
        cout<<"Number of objects detected:"<<num_objects-1<<endl;
    }
//创建彩色目标输出图像
Mat output=Mat::zeros(img.rows,img.cols,CV_8UC3);//3通道8位uchar 0矩阵
RNG rng(0xFFFFFFFF);//RNG为随机数生成器类 
for(int i=1;i<num_objects;i++)
{
    Mat mask=(labels==i);//A
    output.setTo(randomColor(rng),mask);//B
}
    imshow("result",output);
}*/
void ConnectedComponentsStats(Mat img)
{
    //连通区域统计信息的三个量
    Mat labels,stats,centroids;
    int num_objects=connectedComponentsWithStats(img,labels,stats,centroids);
    //检查检测到连通域的数目
    if(num_objects<2)//1的时候应该是只有背景（个人理解）
    {
        cout<<"No object detected"<<endl;
        return;
    }
    else
    {
        cout<<"Number of objects detected:"<<num_objects-1<<endl;
    }
    Mat output=Mat::zeros(img.rows,img.cols,CV_8UC3);
    RNG rng(0xFFFFFFFF);//RNG为随机数生成器类
    for(int i=1;i<num_objects;i++)
    {
        cout<<"Object"<<i<<"with pos:"<<centroids.at<Point2d>(i)<<"with area"<<stats.at<int>(i,CC_STAT_AREA)<<endl;//A
        Mat mask=(labels==i);
        output.setTo(randomColor(rng),mask);
        //使用区域绘制文本
        stringstream ss;//添加统计区域信息
        ss<<"area:"<<stats.at<int>(i,CC_STAT_AREA);
        putText(output,ss.str(),centroids.at<Point2d>(i),FONT_HERSHEY_SIMPLEX,0.4,Scalar(255,255,255));
        //在output上描述信息（这里利用了putText函数）
    }
    imshow("result",output);
}

