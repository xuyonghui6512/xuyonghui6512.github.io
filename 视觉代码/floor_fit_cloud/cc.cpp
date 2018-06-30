#include <iostream>
#include <vector>

#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/visualization/cloud_viewer.h>

#include <opencv2/opencv.hpp>

#include <OpenNI.h>

using namespace openni;

int main()
{
	double camera_factor=1000;
	 float camera_cx = 255.5;   //Kinect 1号
 	float camera_cy = 204.961;
 	 float camera_fx = 366.534;
 	 float camera_fy = 366.534;
	Mat IntrinsicMat=(Mat_<float>(3,3)<<366.534,0,255.5,0,366.534,204.961,0,0,1);

	Mat ExtrinsicMat=(Mat_<float>(4,4)<<0.99920309, 0.039683517, -0.0042863693, -0.041451491,
 4.6836984e-10, 0.10738918, 0.99421704, -0.11217358,
 0.039914336, -0.99342477, 0.10730362, 1.0376837,
 0, 0, 0, 1);
	Status rc=STATUS_OK;
	VideoFrameRef oniDepthImage,oniColorImage;
	rc =OpenNI::initialize();
	Device device;
	rc=device.open(ANY_DEVICE);
	VideoStream oniDepthStream;
	rc=oniDepthStream.create(device,SENSOR_DEPTH);
	oniDepthStream.setMirroringEnabled(true);
  if( STATUS_OK == rc )
  {
    VideoMode modeDepth;//1
   // modeDepth.setResolution(512,424/*640,480*/); //分辨率
    modeDepth.setFps(30); //帧率
    modeDepth.setPixelFormat(PIXEL_FORMAT_DEPTH_1_MM); //深度像素格式
    oniDepthStream.setVideoMode(modeDepth);//1

    oniDepthStream.start(); // 打开深度数据流
    if(STATUS_OK !=  rc)
    {
      std::cerr << "无法打开深度数据流："<<OpenNI::getExtendedError()<<std::endl;
      oniDepthStream.destroy();
    }
  }
  else
  {
    std::cerr << "无法创建深度数据流："<<OpenNI::getExtendedError()<<std::endl;
  }

  VideoStream oniColorStream;  //RGB数据流
  rc = oniColorStream.create(device, SENSOR_COLOR);//颜色传感器
  oniColorStream.setMirroringEnabled(true);
  if(STATUS_OK == rc)
  {
    //设置彩色视频模式
    VideoMode modeColor;
    //分辨率
    //modeColor.setResolution(320,240);
    modeColor.setFps(30);//帧率
    modeColor.setPixelFormat(PIXEL_FORMAT_RGB888);
    if(device.isImageRegistrationModeSupported(IMAGE_REGISTRATION_DEPTH_TO_COLOR))
    {
      device.setImageRegistrationMode(IMAGE_REGISTRATION_DEPTH_TO_COLOR); //深度到彩色图配准
    }

    rc = oniColorStream.start();
    if( STATUS_OK != rc )
    {
      std::cerr<< "无法打开彩色数据流："<<OpenNI::getExtendedError()<<std::endl;
      oniColorStream.destroy();
    }
  }
  else
  {
    std::cerr << "无法创建彩色数据流："<<OpenNI::getExtendedError()<<std::endl;
  }

  if (!oniDepthStream.isValid() || !oniColorStream.isValid() )
  {
    std::cerr << "深度数据流不合法"<<std::endl;
    OpenNI::shutdown();
  }
  pcl::visualization::CloudViewer viewer("viewer");
while(key != 'q')
  {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    
    const DepthPixel* pDepth = NULL;
    const RGB888Pixel* pColor =NULL;
    ///std::cout << " true " << endl;

    if( STATUS_OK == oniDepthStream.readFrame(&oniDepthImg) && STATUS_OK == oniColorStream.readFrame(&oniColorImg) )
    {
      pDepth =(const DepthPixel*) oniDepthImg.getData();  //获取深度数据
      pColor =(const RGB888Pixel*) oniColorImg.getData(); //获取彩色数据
      for (int m = 0; m < oniDepthImg.getHeight(); m++)
        for(int n = 0; n < oniDepthImg.getWidth(); n++)
        {
          //获取深度图中（m,n）处的值
          double depthv = pDepth[m*oniDepthImg.getWidth() + n];//很关键
          if(depthv == 0)
            continue;
          RGB888Pixel colorv = pColor[m*oniColorImg.getWidth() + n];
          pcl::PointXYZ p,pw;
	 //CoordinateConverter::convertDepthToWorld(oniDepthStream, n, m, depthv, &(p.x), &(p.y), &(p.z)); //xtion
          p.x = n;
          p.y = m;
          p.z = depth;
		Mat B=(Mat_<float>(3,1)<<p.x,p.y,p.z);
		B=IntrinsicMat.inv()*B;
	Mat C=(Mat_<float>(4,1)<<B.at<float>(0,0),B.at<float>(1,0),B.at<float>(2,0),1);
	C=ExtrinsicMat*C;
	  pw.x=c.at<float>(0,0);
	pw.y=c.at<float>(1,0);
	pw.z=c.at<float>(2,0);
	cloud -> points.push_back(pw);
	}
	viewer.showCloud(cloud);
	key = cv::waitKey(5);
	}
	}
	 cloud -> points.clear();
  oniDepthStream.destroy();
  oniColorStream.destroy();
  device.close();
  OpenNI::shutdown();
	

}
