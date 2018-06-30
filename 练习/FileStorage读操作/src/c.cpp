#include<iostream>
#include<opencv/highgui.h>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main(int argc,char**argv)
{
    FileStorage fs("test.yml", FileStorage::READ);  
    int width;  
    int height;  
    fs["imageWidth"]>>width;  
    fs["imageHeight"]>>height;  
    cout<<"width readed = "<<width<<endl;  
    cout<<"height readed = "<<height<<endl<<endl;  
  
// read Mat  
    cv::Mat resultMatRead;  
    fs["resultMat"]>>resultMatRead;  
    cout<<"resultMat readed = "<<resultMatRead<<endl<<endl;  
      
    cv::Mat cameraMatrixRead,distCoeffsRead;  
    fs["cameraMatrix"]>>cameraMatrixRead;  
    fs["distCoeffs"]>>distCoeffsRead;  
    cout<<"cameraMatrix readed = "<<cameraMatrixRead<<endl;  
    cout<<"distCoeffs readed = "<<distCoeffsRead<<endl<<endl;  
  
// read string  
    string timeRead;  
    fs["calibrationDate"]>>timeRead;  
    cout<<"calibrationDate readed = "<<timeRead<<endl<<endl;  
  
    fs.release();   
	
		
}

