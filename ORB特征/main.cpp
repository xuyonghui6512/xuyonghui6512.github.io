#include<iostream>
#include<vector>

#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc,char**argv)
{
    /*if(argc !=3)
    {
        cout<<"请输入两张图片："<<endl;
        return 1;
    }*/

    Mat img_1 = imread("/home/xuxuxu/b/ORB特征/bin/1.jpeg",CV_LOAD_IMAGE_COLOR);
    Mat img_2 = imread("/home/xuxuxu/b/ORB特征/bin/3.jpeg",CV_LOAD_IMAGE_COLOR);
    //初始化
    vector<KeyPoint> kpt_1,kpt_2;
    Mat descriptors_1,descriptors_2;
    Ptr<ORB> orb=ORB::create(4);
    //寻找角点位置
    orb->detect(img_1,kpt_1);
    orb->detect(img_2,kpt_2);
    //计算BRIEF描述子
    orb->compute(img_1,kpt_1,descriptors_1);
    orb->compute(img_2,kpt_2,descriptors_2);

    Mat outputimg;
    drawKeypoints(img_1,kpt_1,outputimg,Scalar::all(-1),DrawMatchesFlags::DEFAULT);
    imshow("ORB",outputimg);
    //进行匹配
    vector<DMatch> match;

    BFMatcher matcher(NORM_HAMMING);

    matcher.match(descriptors_1,descriptors_2,match);

//绘出未做处理的匹配点
    Mat imgMatch1;
    drawMatches(img_1,kpt_1,img_2,kpt_2,match,imgMatch1);


    imshow("HAMMING",imgMatch1);
    //筛选
    double min_dist=10000,max_dist=0;
    for(int i=0;i<descriptors_1.rows;i++)
    {
        double dist = match[i].distance;
        if(dist<min_dist) min_dist=dist;
        if(dist>max_dist) max_dist=dist;
    }
    cout<<"Max dist : "<<max_dist<<endl;
    cout<<"Min dist : "<<min_dist<<endl;

    Mat imggoodmatch;
    vector<DMatch> good_match;
    for(int i=0;i<descriptors_1.rows;i++)
    {
        if(match[i].distance<=max(2*min_dist,30.0))
        {
            good_match.push_back(match[i]);
        }
    }
    drawMatches(img_1,kpt_1,img_2,kpt_2,good_match,imggoodmatch);
    imshow("good match",imggoodmatch);
    cout<<kpt_1[2].angle<<"      "<<kpt_1[2].pt<<endl;
    cout<<kpt_2[2].angle<<"     "<<kpt_2[2].pt<<endl;
    Mat test;
    circle(img_2,kpt_2[2].pt,5,Scalar(0,0,255));
    imshow("1",img_2);
    waitKey(0);
}
