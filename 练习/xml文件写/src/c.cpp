#include<iostream>
#include<opencv2/opencv.hpp>
#include<time.h>
using namespace cv;
using namespace std;



int main(int argc ,const char** argv)
{

FileStorage fs("test.xml",FileStorage::WRITE);
time_t rawtime;//写入当前时间
time(&rawtime);
fs<<"calibrationDate"<<asctime(localtime(&rawtime));

fs.release();
cout<<asctime(localtime(&rawtime))<<endl;
printf("that's all");
getchar();
return 0;
}
