cmake_minimum_required(VERSION 3.5)
project(test1)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CONFIGURATION_TYPES Debug Release)

set(CMAKE_C_FLAGS_RELEASE  "${CMAKE_C_FLAGS_RELEASE} -Wall -O3 -march=native")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -pg -march=native")

set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3 -march=native")
set(CMAKE_CXX_FLAGS_DEBUG    "${CMAKE_CXX_FLAGS_DEBUG} -Wall -pg -march=native")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenCV 3.2.0 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(G2O REQUIRED)
find_package(CSparse REQUIRED)
find_package(OpenNI2 REQUIRED)
find_package(PCL 1.7 REQUIRED)
find_package(Boost  REQUIRED)

include_directories(
        ${OPENCV_INCLUDE_DIRS}
        ${OPENNI2_INCLUDE_DIRS}
        ${PCL_INCLUDE_DIRS}
)

set(SOURCE_FILES main.cpp
        rgbd_camera.h
        rgbd_camera.cpp
        )
list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")
add_executable(test1 ${SOURCE_FILES})

target_link_libraries(test1
        ${OpenCV_LIBS}
        ${OpenNI2_LIBRARIES}
        ${PCL_LIBRARIES}
        )
