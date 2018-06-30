#include <iostream>
#include <sys/time.h>
#include <opencv2/opencv.hpp>
#include "rgbd_camera.h"

using namespace hitcrt;

int main()
{
 //RGBDcamera xtion(RGBDcamera::Live_mode,RGBDcamera::Xtion);     //创建一个xtion对象
    RGBDcamera Kinect(RGBDcamera::Live_mode,RGBDcamera::Kinect);
    Kinect.showdevice();
    char key = ' ';
    struct timeval st,en;
    while(key != 'q') {
        gettimeofday(&st,NULL);
        cv::Mat depth_img,depth_img2,color_img;
        color_img = Kinect.getFrameRGB();
//        depth_img = xtion.getFrameDepth();
        depth_img2 = Kinect.getFrameDepth();
        gettimeofday(&en,NULL);
        std::cout << "time : " << (en.tv_usec - st.tv_usec)/1000.0 << "ms" << std::endl;
        cv::Mat cvDIamge8u;
        depth_img2.convertTo(cvDIamge8u,CV_8UC1);
//        cv::imshow("xtion",depth_img);
        cv::imshow("kinect",cvDIamge8u);
        cv::imshow("rgb",color_img);
        key = cv::waitKey(1);
    }
    return 0;
}

