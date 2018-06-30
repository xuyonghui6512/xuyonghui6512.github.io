#include<iostream>

#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include "opencv2/imgproc.hpp"

#include "opencv2/ml.hpp"

using namespace cv;
using namespace std;

using namespace cv::ml;

int main(int argc,char **argv)
{
    Mat srcImage1=imread("1.jpg");
    Mat srcImage2;
    resize(srcImage1,srcImage2,Size(),0.5,0.5);
    if(!srcImage1.data||!srcImage2.data)
    {
        cout<<"No picture loaded sucessfully"<<endl;
        return -1;
    }
    int minHessian(700);
     Ptr<SURF> detector = SURF::create(minHessian);
    vector<KeyPoint> keyPoint1,keyPoint2;
    detector.detect(srcImage1,keyPoint1);
     detector.detect(srcImage2,keyPoint2);
     Ptr<SURF> extractor=SURF::create();
     Mat descriptors1,descrptors2;
     extractor.compute(srcImage1,keyPoint1,descriptors1);
      extractor.compute(srcImage2,keyPoint2,descriptors2);
     // BruteForceMatcher<L2<float> > matcher;
       Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce");
      vector<DMatch> matches;
      matcher.match(descriptors1,descrptors2,matches);
      Mat imgMatches;
      drawMatches(srcImage1,keyPoint1,srcImage2,keyPoint2,matches,imgMatches);
      imshow("xiaoguo",imgMatches);
     waitKey(0);
     return 0;
}
