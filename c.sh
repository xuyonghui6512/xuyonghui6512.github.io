#!/bin/bash
#PROJECT made by XuYonghui
#此程序是用来帮助写CMakeLists.txt
#Date 2017/12/02

PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
key=1
while [ $key == 1 ]
do
read -p  "请输入需要创建CMakeLIsts.txt的绝对路径: " path
test -d ${path} && a=1 || a=0
if [ $a == 1 ];then
key=0
fi
while [ $a == 0 ]
do
read -p "该目录并不存在，重新输入请选1，创建该目录请选2: " num
if [ $num == 1 ];then
key=1 && a=1 
elif [ $num == 2 ];then
mkdir ${path} && key=0 && a=1
fi
done
done
cd ${path}
read -p "请告诉我程序名称（例如main.cpp或者measure.py）:" filename
read -p "请输入项目名称PROJECT（）：" project
read -p "请选出您需要的相应库的代码（需要1 2 请写12）:\
	 1.OpenCV\
	 2.OpenNI\
	 3.PCL \
         4.Eigen :  " num1
read -p "你确定要开始建立新项目了么（Y/N）?:" yn

if [ $yn == "n" -o $yn == "N" ];then
exit
fi
if [ $yn == y -o $yn == "Y" ];then
mkdir build
echo -e "CMAKE_MINIMUM_REQUIRED(VERSION 3.5)" >> CMakeLists.txt
echo -e "PROJECT($project)" >> CMakeLists.txt
echo -e "SET(CMAKE_CXX_STANDARD 11)" >> CMakeLists.txt
echo -e 'set(CMAKE_MODULE_PATH /home/xuxuxu/cmake_modules)' >> CMakeLists.txt
echo -e "set(CMAKE_BUILD_TYPE Release)" >>CMakeLists.txt
echo -e 'set(CMAKE_CONFIGURATION_TYPES Debug Release)' >> CMakeLists.txt
echo -e 'set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3 -march=native")' >> CMakeLists.txt
echo -e 'set(CMAKE_CXX_FLAGS_DEBUG    "${CMAKE_CXX_FLAGS_DEBUG} -Wall -pg -march=native")' >> CMakeLists.txt
echo -e 'set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)' >> CMakeLists.txt
echo -e "set(SOURCE_FILES $filename )" >> CMakeLists.txt
echo -e "add_executable($project \${SOURCE_FILES})" >> CMakeLists.txt
case $num1 in
"1")
echo -e 'find_package(OpenCV 3.1.0 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENCV_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project  \${OpenCV_LIBS})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<opencv2/opencv.hpp>' >> $filename
echo -e "">> $filename
echo -e 'using namespace cv;' >> $filename
echo -e 'using namespace std;' >> $filename
;;
"2")
echo -e 'find_package(OpenNI2 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENNI2_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${OpenNI2_LIBRARIES})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<OpenNI.h>' >> $filename
echo -e "">> $filename
echo -e 'using namespace std;' >> $filename
;;
"3")
echo -e 'find_package(PCL 1.7 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${PCL_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${PCL_LIBRARIES})" >> CMakeLists.txt
echo -e 'list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")' >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<pcl>' >> $filename
echo -e "">> $filename
echo -e 'using namespace std;' >> $filename
;;
"4")
echo -e 'include_directories("/usr/include/eigen3")' >>CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename

echo -e '#include<Eigen/Dense>' >>$filename
echo -e "">> $filename

echo -e 'using namespace std;' >> $filename
;;
"12" | "21")
echo -e 'find_package(OpenCV 3.1.0 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENCV_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'find_package(OpenNI2 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENNI2_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${OpenNI2_LIBRARIES} \${OpenCV_LIBS})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<OpenNI.h>' >> $filename
echo -e '#include<opencv2/opencv.hpp>' >> $filename
echo -e "">> $filename
echo -e 'using namespace cv;' >> $filename
echo -e 'using namespace std;' >> $filename
;;
"13" | "31")
echo -e 'find_package(PCL 1.7 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${PCL_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")' >> CMakeLists.txt
echo -e 'find_package(OpenCV 3.1.0 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENCV_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${OpenCV_LIBS} \${PCL_LIBRARIES})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<opencv2/opencv.hpp>' >> $filename
echo -e '#include<pcl>' >> $filename
echo -e "">> $filename
echo -e 'using namespace cv;' >> $filename
echo -e 'using namespace std;' >> $filename
;;
"23" | "32")
echo -e 'find_package(PCL 1.7 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${PCL_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")' >> CMakeLists.txt
echo -e 'find_package(OpenNI2 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENNI2_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${OpenNI2_LIBRARIES} \${PCL_LIBRARIES})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<OpenNI.h>' >> $filename
echo -e '#include<pcl>' >> $filename
echo -e "">> $filename
echo -e 'using namespace std;' >> $filename
;;
"123" | "321" | "312" | "213" | "132" | "231")
echo -e 'find_package(OpenCV 3.1.0 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENCV_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'find_package(PCL 1.7 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${PCL_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")' >> CMakeLists.txt
echo -e 'find_package(OpenNI2 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENNI2_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${OpenNI2_LIBRARIES} \${OpenCV_LIBS} \${PCL_LIBRARIES})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<OpenNI.h>' >> $filename
echo -e '#include<opencv2/opencv.hpp>' >> $filename
echo -e '#include<pcl>' >> $filename
echo -e "">> $filename
echo -e 'using namespace cv;' >> $filename
echo -e 'using namespace std;' >> $filename
;;
"14" | "41")
echo -e 'find_package(OpenCV 3.1.0 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENCV_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project  \${OpenCV_LIBS})" >> CMakeLists.txt
echo -e 'include_directories("/usr/include/eigen3")' >>CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<opencv2/opencv.hpp>' >> $filename
echo -e "">> $filename
echo -e '#include<Eigen/Dense>' >>$filename
echo -e "">> $filename
echo -e 'using namespace cv' >> $filename
echo -e 'using namespace std;' >> $filename
;;
"24" | "42")
echo -e 'find_package(OpenNI2 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENNI2_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'include_directories("/usr/include/eigen3")' >>CMakeLists.txt
echo -e "target_link_libraries($project \${OpenNI2_LIBRARIES})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<OpenNI.h>' >> $filename
echo -e "">> $filename
echo -e '#include<Eigen/Dense>' >>$filename
echo -e "">> $filename
echo -e 'using namespace std;' >> $filename
;;
"34" | "43")
echo -e 'find_package(PCL 1.7 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${PCL_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'include_directories("/usr/include/eigen3")' >>CMakeLists.txt
echo -e "target_link_libraries($project \${PCL_LIBRARIES})" >> CMakeLists.txt
echo -e 'list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")' >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<pcl>' >> $filename
echo -e "">> $filename
echo -e '#include<Eigen/Dense>' >>$filename
echo -e "">> $filename
echo -e 'using namespace std;' >> $filename
;;
"124" | "142" | "412" | "421" | "214" | "241")
echo -e 'find_package(OpenCV 3.1.0 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENCV_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'include_directories("/usr/include/eigen3")' >>CMakeLists.txt
echo -e 'find_package(OpenNI2 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENNI2_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${OpenNI2_LIBRARIES} \${OpenCV_LIBS})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<OpenNI.h>' >> $filename
echo -e '#include<opencv2/opencv.hpp>' >> $filename
echo -e "">> $filename
echo -e '#include<Eigen/Dense>' >>$filename
echo -e "">> $filename
echo -e 'using namespace cv;' >> $filename
echo -e 'using namespace std;' >> $filename
;;
"134" | "143" | "431" | "413" | "314" | "341")
echo -e 'find_package(PCL 1.7 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${PCL_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'include_directories("/usr/include/eigen3")' >>CMakeLists.txt
echo -e 'list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")' >> CMakeLists.txt
echo -e 'find_package(OpenCV 3.1.0 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENCV_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${OpenCV_LIBS} \${PCL_LIBRARIES})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<opencv2/opencv.hpp>' >> $filename
echo -e '#include<pcl>' >> $filename
echo -e "">> $filename
echo -e '#include<Eigen/Dense>' >>$filename
echo -e "">> $filename
echo -e 'using namespace cv;' >> $filename
echo -e 'using namespace std;' >> $filename
;;
"234" | "243" | "324" | "342" | "432" | "423")
echo -e 'find_package(PCL 1.7 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${PCL_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'include_directories("/usr/include/eigen3")' >>CMakeLists.txt
echo -e 'list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")' >> CMakeLists.txt
echo -e 'find_package(OpenNI2 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENNI2_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${OpenNI2_LIBRARIES} \${PCL_LIBRARIES})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<OpenNI.h>' >> $filename
echo -e '#include<pcl>' >> $filename
echo -e "">> $filename
echo -e '#include<Eigen/Dense>' >>$filename
echo -e "">> $filename
echo -e 'using namespace std;' >> $filename
;;
"1234" | "1243" | "1324" | "1342" | "1432" | "1423" | "2134" | "2143" | "2341" | "2314" | "2413" | "2431" | "3124" | "3142" | "3214" | "3241" | "3412" | "3421" | "4321" | "4312" | "4123" | "4132" | "4213" | "4231" )
echo -e 'find_package(OpenCV 3.1.0 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENCV_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'include_directories("/usr/include/eigen3")' >>CMakeLists.txt
echo -e 'find_package(PCL 1.7 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${PCL_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e 'list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")' >> CMakeLists.txt
echo -e 'find_package(OpenNI2 REQUIRED)' >> CMakeLists.txt
echo -e 'include_directories(${OPENNI2_INCLUDE_DIRS})' >> CMakeLists.txt
echo -e "target_link_libraries($project \${OpenNI2_LIBRARIES} \${OpenCV_LIBS} \${PCL_LIBRARIES})" >> CMakeLists.txt
echo -e '#include<iostream>' >> $filename
echo -e '#include<vector>' >> $filename
echo -e "">> $filename
echo -e '#include<OpenNI.h>' >> $filename
echo -e '#include<opencv2/opencv.hpp>' >> $filename
echo -e '#include<pcl>' >> $filename
echo -e "">> $filename
echo -e '#include<Eigen/Dense>' >>$filename
echo -e "">> $filename
echo -e 'using namespace cv;' >> $filename
echo -e 'using namespace std;' >> $filename
;;
esac
fi
echo -e "" >> $filename
echo -e 'int main(int argc,char**argv)' >>$filename
echo -e '{'>>$filename
echo -e "" >>$filename
echo -e "" >>$filename
echo -e '}'>>$filename
read -p "你希望现在就进行编辑嘛（Y/N）" yn1
if [ $yn1 == "Y" -o $yn1 == "y" ];then
vim $filename
else
echo "5秒后即将退出！"
sleep 5
exit
fi
