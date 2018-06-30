// FACE DETECTION

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    string faceCascadeName = "/home/xuxuxu/b/cmake/带面具/haarcascade_frontalface_alt.xml";
    CascadeClassifier faceCascade;//
//CascadeClassifier，是Opencv中做人脸检测的时候的一个级联分类器，现在有两种选择：一是使用老版本的CvHaarClassifierCascade函数，一是使用新版本的CascadeClassifier类。
//老版本的分类器只支持类Haar特征，而新版本的分类器既可以使用Haar，也可以使用LBP特征。
    
    if( !faceCascade.load(faceCascadeName) )
    {
        cerr << "Error loading cascade file. Exiting!" << endl;
        return -1;
    }
    
    Mat faceMask = imread("1.jpg");
    
    if ( !faceMask.data )
    {
        cerr << "Error loading mask image. Exiting!" << endl;
    }
    
    // Current frame
    Mat frame, frameGray;
    Mat frameROI, faceMaskSmall;
    Mat grayMaskSmall, grayMaskSmallThresh, grayMaskSmallThreshInv;
    Mat maskedFace, maskedFrame;
    
    char ch;
    
    // Create the capture object
    // 0 -> input arg that specifies it should take the input from the webcam
    VideoCapture cap(0);
    
    // If you cannot open the webcam, stop the execution!
    if( !cap.isOpened() )
        return -1;
    
    //create GUI windows
    namedWindow("Frame");
    
    // Scaling factor to resize the input frames from the webcam
    float scalingFactor = 0.75;
    
    vector<Rect> faces;
    
    // Iterate until the user presses the Esc key
    while(true)
    {
        // Capture the current frame
        cap >> frame;
        
        // Resize the frame
        resize(frame, frame, Size(), scalingFactor, scalingFactor, INTER_AREA);
        
        // Convert to grayscale
        cvtColor(frame, frameGray, CV_BGR2GRAY);
        
        // Equalize the histogram
        equalizeHist(frameGray, frameGray);//图像均匀化
        
        // Detect faces
        faceCascade.detectMultiScale(frameGray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
        
        // Draw green rectangle around the face
        for(int i = 0; i < faces.size(); i++)
        {
            Rect faceRect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
            
            // Custom parameters to make the mask fit your face. You may have to play around with them to make sure it works.
            int x = faces[i].x - int(0.35*faces[i].width);
            int y = faces[i].y - int(0.3*faces[i].height);
            int w = int(1.8 * faces[i].width);
            int h = int(1.6 * faces[i].height);
            
            // Extract region of interest (ROI) covering your face
            frameROI = frame(Rect(x,y,w,h));
            
            // Resize the face mask image based on the dimensions of the above ROI
            resize(faceMask, faceMaskSmall, Size(w,h));
            
            // Convert the above image to grayscale
            cvtColor(faceMaskSmall, grayMaskSmall, CV_BGR2GRAY);
            
            // Threshold the above image to isolate the pixels associated only with the face mask
            threshold(grayMaskSmall, grayMaskSmallThresh, 100, 255, CV_THRESH_BINARY);
            
            // Create mask by inverting the above image (because we don't want the background to affect the overlay)
            bitwise_not(grayMaskSmallThresh, grayMaskSmallThreshInv);
            
            // Use bitwise "AND" operator to extract precise boundary of face mask
            bitwise_and(faceMaskSmall, faceMaskSmall, maskedFace, grayMaskSmallThresh);
            
            // Use bitwise "AND" operator to overlay face mask
            bitwise_and(frameROI, frameROI, maskedFrame, grayMaskSmallThreshInv);
            
            // Add the above masked images and place it in the original frame ROI to create the final image
            add(maskedFace, maskedFrame, frame(Rect(x,y,w,h)));
        }
        
        // Show the current frame
        imshow("Frame", frame);
        
        // Get the keyboard input and check if it's 'Esc'
        // 27 -> ASCII value of 'Esc' key
        ch = waitKey( 30 );
        if (ch == 27) {
            break;
        }
    }
    
    // Release the video capture object
    cap.release();
    
    // Close all windows
    destroyAllWindows();
    
    return 1;
}
