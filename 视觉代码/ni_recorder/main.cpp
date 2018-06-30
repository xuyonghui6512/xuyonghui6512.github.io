#include <iostream>

// OpenCV Header
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// OpenNI Header
#include <OpenNI.h>

using namespace cv;
using namespace std;
using namespace openni;


int main( int argc, char **argv )
{
  // 1. Initial OpenNI


        double camera_factor=1000;
	 float camera_cx = 255.5;   //Kinect 1号
 	float camera_cy = 204.961;
 	 float camera_fx = 366.534;
 	 float camera_fy = 366.534;
	char key=' ';
	cv::Mat IntrinsicMat=(cv::Mat_<float>(3,3)<<366.534,0,255.5,0,366.534,204.961,0,0,1);

	cv::Mat ExtrinsicMat=(cv::Mat_<float>(4,4)<<0.99920309, 0.039683517, -0.0042863693, -0.041451491,
 4.6836984e-10, 0.10738918, 0.99421704, -0.11217358,
 0.039914336, -0.99342477, 0.10730362, 1.0376837,
 0, 0, 0, 1);
  if( OpenNI::initialize() != STATUS_OK )
  {
    cerr << "OpenNI Initial Error: "
         << OpenNI::getExtendedError() << endl;
    return -1;
  }

  // 2. Open Device
  Device mDevice;
  if( mDevice.open( ANY_DEVICE ) != STATUS_OK )
  {
    cerr << "Can't Open Device: "
         << OpenNI::getExtendedError() << endl;
    return -1;
  }
  openni::Status status;


  // 3. Create depth stream
  VideoStream mDepthStream;
  if( mDevice.hasSensor( SENSOR_DEPTH ) )
  {
    if( mDepthStream.create( mDevice, SENSOR_DEPTH ) == STATUS_OK )
    {
      // 3a. set video mode
      VideoMode mMode;
      mMode.setResolution(512,424);
      mMode.setFps( 30 );
      mMode.setPixelFormat( PIXEL_FORMAT_DEPTH_1_MM );

      mDepthStream.setMirroringEnabled(true);

      if( mDepthStream.setVideoMode( mMode) != STATUS_OK )
      {
        cout << "Can't apply VideoMode: "
             << OpenNI::getExtendedError() << endl;
      }
    }
    else
    {
      cerr << "Can't create depth stream on device: "
           << OpenNI::getExtendedError() << endl;
      return -1;
    }
  }
  else
  {
    cerr << "ERROR: This device does not have depth sensor" << endl;
    return -1;
  }


  // 4. Create color stream
  VideoStream mColorStream;
  if( mDevice.hasSensor( SENSOR_COLOR ) )
  {
    if( mColorStream.create( mDevice, SENSOR_COLOR ) == STATUS_OK )
    {
      // 4a. set video mode
      VideoMode mMode;
      //mMode.setResolution( 320, 240 );
      mMode.setFps( 30 );
      mMode.setPixelFormat( PIXEL_FORMAT_RGB888 );

      mColorStream.setMirroringEnabled(true);

      if( mColorStream.setVideoMode( mMode) != STATUS_OK )
      {
        cout << "Can't apply VideoMode: "
             << OpenNI::getExtendedError() << endl;
      }

      // 4b. image registration
      if( mDevice.isImageRegistrationModeSupported(IMAGE_REGISTRATION_DEPTH_TO_COLOR ) )
      {
        mDevice.setImageRegistrationMode( IMAGE_REGISTRATION_DEPTH_TO_COLOR );
      }
    }
    else
    {
      cerr << "Can't create color stream on device: "
           << OpenNI::getExtendedError() << endl;
      return -1;
    }
  }

   if( mDevice.isImageRegistrationModeSupported( IMAGE_REGISTRATION_DEPTH_TO_COLOR ) )
  {
	status=mDevice.setImageRegistrationMode( IMAGE_REGISTRATION_DEPTH_TO_COLOR );
  }
  // 5. create OpenCV Window
  cv::namedWindow( "Depth Image",  CV_WINDOW_AUTOSIZE );
  cv::namedWindow( "Color Image",  CV_WINDOW_AUTOSIZE );

  // 6. start
  VideoFrameRef  mColorFrame;
  VideoFrameRef  mDepthFrame;
  mDepthStream.start();
  mColorStream.start();
  int iMaxDepth = mDepthStream.getMaxPixelValue();
  int ImgNum=0;
  char ImagesName[50];
  cv::Mat cImageBGR;
  cv::Mat mScaledDepth;

  Recorder mRecorder;

  if( mRecorder.create("data.ONI") != STATUS_OK)
  {
    cerr << "Can't create Recorder: "
          << OpenNI::getExtendedError() << endl;
  }

    if( mRecorder.attach(mDepthStream) != STATUS_OK || mRecorder.attach(mColorStream) != STATUS_OK)
  {
    cerr << "Can't Open Recorder: "
          << OpenNI::getExtendedError() << endl;
    return -1;
  }

	char key = ' ';
  while( true )
  {
    // 7. check is color stream is available
    if( mColorStream.isValid() )
    {
      // 7a. get color frame
      if( mColorStream.readFrame( &mColorFrame ) == STATUS_OK )
      {
        // 7b. convert data to OpenCV format
        const cv::Mat mImageRGB(
                mColorFrame.getHeight(), mColorFrame.getWidth(),
                CV_8UC3, (void*)mColorFrame.getData() );
        // 7c. convert form RGB to BGR

        cv::cvtColor( mImageRGB, cImageBGR, CV_RGB2BGR );//转换色彩
        // 7d. show image
        //cv::flip(cImageBGR,cImageBGR,1);
        cv::imshow( "Color Image", cImageBGR );
      }
    }

    // 8a. get depth frame
    if( mDepthStream.readFrame( &mDepthFrame ) == STATUS_OK )
    {
      // 8b. convert data to OpenCV format


      const cv::Mat mImageDepth(
                mDepthFrame.getHeight(), mDepthFrame.getWidth(),
                CV_16UC1, (DepthPixel*)mDepthFrame.getData() );
      // 8c. re-map depth data [0,Max] to [0,255]

      mImageDepth.convertTo( mScaledDepth, CV_8U, 255.0 / iMaxDepth );
      //cv::flip(mScaledDepth,mScaledDepth,1);
      cv::imshow( "Depth Image",mScaledDepth );
    }

    // 6a. check keyboard
	if( key == 'q' )
    break;
	if( key == 's' )
    {
        if( mRecorder.isValid())
        {
            if( mRecorder.start() == STATUS_OK ) cout << " START RECORDING...... " << endl;
            else cout << "OH! NO!....."  << endl;
        }
    }
    key = cv::waitKey( 10 );
}
  // 9. stop
  mRecorder.stop();
  mRecorder.destroy();
  mDepthStream.destroy();
  mColorStream.destroy();
  mDevice.close();
  OpenNI::shutdown();
  system("pause");
  return 0;
}

