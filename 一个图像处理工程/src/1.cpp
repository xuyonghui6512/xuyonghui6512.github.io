//created by xuyonghui6512
//2017-12-7
#include"1.h"

#include<iostream>
#include<vector>

#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
namespace c{
void PictureProgress::ORBmatch(cv::Mat &input_img1,cv::Mat &input_img2,int KeyPoints_num,cv::Mat &output_img)
{
    vector<KeyPoint> kpt_1,kpt_2;
    Mat descriptors_1,descriptors_2;
    Ptr<ORB> orb=ORB::create(KeyPoints_num);

    //寻找角点位置
    orb->detect(input_img1,kpt_1);
    orb->detect(input_img2,kpt_2);
    //计算BRIEF描述子
    orb->compute(input_img1,kpt_1,descriptors_1);
    orb->compute(input_img1,kpt_2,descriptors_2);

    std::vector<DMatch> matches;

    BFMatcher matcher(NORM_HAMMING);

    matcher.match(descriptors_1,descriptors_2,matches);
//筛选
    double min_dist=10000,max_dist=0;
    for(int i=0;i<descriptors_1.rows;i++)
    {
        double dist = matches[i].distance;
        if(dist<min_dist) min_dist=dist;
        if(dist>max_dist) max_dist=dist;
    }
   // cout<<"Max dist : "<<max_dist<<endl;
   // cout<<"Min dist : "<<min_dist<<endl;

    
    std::vector<DMatch> good_matches;
    for(int i=0;i<descriptors_1.rows;i++)
    {
        if(matches[i].distance<=max(2*min_dist,30.0))
        {
            good_matches.push_back(matches[i]);
        }
    }
    drawMatches(input_img1,kpt_1,input_img2,kpt_2,good_matches,output_img);
}

}
