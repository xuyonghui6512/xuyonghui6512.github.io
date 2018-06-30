#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
#include<opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main(int argc,char**argv)
{
    Mat src=imread("0.png",1);
    char image_name[50];
    int isColor = 1;
    int fps = 10;
    int frameWidth = src.cols;
    int frameHeight = src.rows;

    VideoWriter writer("30.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps,
                        Size(frameWidth, frameHeight), isColor);

    cout << "info:" << endl
        << "ff.avi" << endl
        << "Size:" << frameWidth << "*" << frameHeight << endl
        << "fps:" << fps << endl;

    for (int i = 0; i < 30; i++)
    {
        sprintf(image_name, "%d.png", i);
        src = imread(image_name, 1);
        if (src.empty())
        {
           cout<<"that's all"<<endl;
        }
        imshow("【src】", src);
        waitKey(5);
        writer.write(src);

    }
return 0;
}
