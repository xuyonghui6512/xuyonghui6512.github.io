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


///openni开启摄像头
int main()
{
  double camera_factor = 1000.0;
//  double camera_cx = 256.162;   //kinect 2号
//  double camera_cy = 213.28;
//  double camera_fx = 364.485;
//  double camera_fy = 364.485;

  double camera_cx = 255.5;   //Kinect 1号
  double camera_cy = 204.961;
  double camera_fx = 366.534;
  double camera_fy = 366.534;

  char key = ' ';

  std::ofstream outfile;//
  outfile.open("/home/xuxuxu/b/视觉代码/floor_fit_cloud/cloud2.txt");

  Status rc = STATUS_OK; // OpenNI函数执行结果

  //OpenNI2图
  VideoFrameRef oniDepthImg, oniColorImg;
  //初始化OpenNI2
  rc = OpenNI::initialize();

  //打开Kinect或Xtion设备
  Device device;
  const char * deviceURL = openni::ANY_DEVICE;  //设备名
 // rc = device.open("freenect2://0?serial=019991643547");
//  openni::PlaybackControl* playback;
  rc = device.open(deviceURL);
//  playback = device.getPlaybackControl();
//  playback->setSpeed(0.1);
//  playback->setRepeatEnabled(true);
  //创建并打开深度数据流
  VideoStream oniDepthStream; //深度数据流

  rc = oniDepthStream.create(device, SENSOR_DEPTH);//深度传感器
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

  int i = 0;

  while(key != 'q')
  {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);//点云容器？
    pcl::ExtractIndices<pcl::PointXYZ> extract;
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
          pcl::PointXYZ p;

//          double z =  depthv;
//          double x = (n - camera_cx) * depthv / camera_fx;
//          double y = (m - camera_cy) * depthv / camera_fy;
//          p.x = (double)x/camera_factor;
//          p.y = (double)y/camera_factor;
//          p.z = (double)z/camera_factor;
          //计算这个点的空间坐标
          CoordinateConverter::convertDepthToWorld(oniDepthStream, n, m, depthv, &(p.x), &(p.y), &(p.z)); //xtion
          p.x = -(double)p.x/camera_factor;
          p.y = -(double)p.y/camera_factor;
          p.z = (double)p.z/camera_factor;
          cloud -> points.push_back(p);
        }
    }

    cloud->height = 1;
    cloud->width = cloud->points.size();
    //std::cout << "point cloud size =" << cloud ->points.size()<<std::endl;
    cloud ->is_dense = false;

    if((cloud ->points.size()) == 0) continue;

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;//StatisticalOutlierRemoval滤波器移除离群点
    sor.setInputCloud (cloud);
    sor.setMeanK (100);//设置在进行统计时考虑查询点邻近点
    sor.setStddevMulThresh (1.0);//设置判断是否为离群点的阈值
    sor.filter (*cloud_filtered);//执行滤波处理保存内点到cloud_filtered


    pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);//创建模型参数对象
    pcl::PointIndices::Ptr inliers (new pcl::PointIndices);//创建误差能容忍的点 记录的是点云的序号
    // Create the segmentation object
    pcl::SACSegmentation<pcl::PointXYZ> seg;//创建一个分割器
    // Optional
    seg.setOptimizeCoefficients (true);
    // Mandatory
    seg.setModelType (pcl::SACMODEL_PLANE);//设置目标的几何形状
    seg.setMethodType (pcl::SAC_RANSAC);//分割方法：随机采样法
    seg.setDistanceThreshold (0.03);//能容忍的误差范围

    seg.setInputCloud (cloud_filtered);//输入点云
    seg.segment (*inliers, *coefficients);


    //outfile << "cofficients : " << " "
    std::cout << coefficients->values[0] <<" "
              << coefficients->values[1] <<" "
              << coefficients->values[2] <<" "
              << coefficients->values[3] << std::endl;


    //viewer.showCloud(cloud_filtered);

    // show inliers
    extract.setInputCloud (cloud_filtered);
    extract.setIndices (inliers);
    extract.setNegative (false);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane (new pcl::PointCloud<pcl::PointXYZ> ());
    pcl::PointCloud<pcl::PointXYZ>::Ptr plane_flitered (new pcl::PointCloud<pcl::PointXYZ> ());
    extract.filter (*cloud_plane);
    if (cloud_plane->points.empty ())
      std::cerr << "Can't find !" << std::endl;
    else
    {
      std::cerr << " size is" << cloud_plane -> points.size() << std::endl;
      viewer.showCloud(cloud_filtered);

      for (size_t i = 0; i < cloud_plane->points.size (); i = i + 5)
        outfile  << cloud_plane->points[i].x << " "
                 << cloud_plane->points[i].y << " "
                 << cloud_plane->points[i].z << " " <<std::endl;
    }

    cloud -> points.clear();
    cloud_filtered -> points.clear();
    cloud_plane -> points.clear();
    plane_flitered -> points.clear();

    key = cv::waitKey(5);
  }
  oniDepthStream.destroy();
  oniColorStream.destroy();
  outfile.close();
  device.close();
  OpenNI::shutdown();
}
