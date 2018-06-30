#include<opencv2/opencv.hpp>
using namespace cv;


#define WINDOW_NAME1 "yuantu"
#define WINDOW_NAME2 "xiaoguotu"


Mat g_srcImage; Mat g_templateImage; Mat g_resultImage;
int g_nMatchMethod;
int g_nMaxTrackbarNum = 5;
Mat C;


void on_Matching( int, void* );

int main(  )
{

    system("color 1F");

    g_srcImage = imread( "1.jpg", 1 );
    g_templateImage = imread( "2.jpg", 1 );
    C=imread("1.jpg",1);


   resize(g_srcImage,g_srcImage,Size(),0.5,0.5);
    resize( g_templateImage, g_templateImage,Size(),0.9,0.9);

    namedWindow( WINDOW_NAME1, WINDOW_AUTOSIZE );
    namedWindow( WINDOW_NAME2, WINDOW_AUTOSIZE );


    createTrackbar( "����", WINDOW_NAME1, &g_nMatchMethod, g_nMaxTrackbarNum, on_Matching );
    on_Matching( 0, 0 );

    waitKey(0);
    return 0;

}


void on_Matching( int, void* )
{

    Mat srcImage;
   C.copyTo( srcImage );


    int resultImage_cols =  C.cols - C.cols + 1;
    int resultImage_rows = C.rows - C.rows + 1;
    g_resultImage.create( resultImage_cols, resultImage_rows, CV_32FC1 );


    matchTemplate( g_srcImage, g_templateImage, g_resultImage, g_nMatchMethod );
    normalize( g_resultImage, g_resultImage, 0, 1, NORM_MINMAX, -1, Mat() );


    double minValue; double maxValue; Point minLocation; Point maxLocation;
    Point matchLocation;
    minMaxLoc( g_resultImage, &minValue, &maxValue, &minLocation, &maxLocation, Mat() );


    if( g_nMatchMethod  == TM_SQDIFF || g_nMatchMethod == TM_SQDIFF_NORMED )
    { matchLocation = minLocation; }
    else
    { matchLocation = maxLocation; }


    rectangle( srcImage, matchLocation, Point( matchLocation.x + g_templateImage.cols , matchLocation.y + g_templateImage.rows ), Scalar(0,0,255), 2, 8, 0 );
    rectangle( g_resultImage, matchLocation, Point( matchLocation.x + g_templateImage.cols , matchLocation.y + g_templateImage.rows ), Scalar(0,0,255), 2, 8, 0 );

    imshow( WINDOW_NAME1, srcImage );
    imshow( WINDOW_NAME2, g_resultImage );

}

