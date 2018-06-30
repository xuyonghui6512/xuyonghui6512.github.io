#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main(int agrc,char**agrv)
{
    Mat A=imread("2.jpg");
    Mat B=imread("1.jpg");
    Mat C;
    imshow("Origin1",A);
    imshow("Orgin2",B);
    double AlphaValue=0.6;
    double betaValue;
    if(!A.data){
        cout<<"FAIL!"<<endl;
        return -1;
    }
    if(!B.data)
    {
        cout<<"FAIL!"<<endl;
        return -1;
    }
    betaValue=1-AlphaValue;
    addWeighted(A,AlphaValue,B,betaValue,0.0,C);
    imshow("blended picture",C);
    waitKey(0);
    return 0;
}
