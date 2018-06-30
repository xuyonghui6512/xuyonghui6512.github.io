cmake_minimum_required(VERSION 3.5)
project(floor_fit_cloud)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3 -march=native")
set(CMAKE_CXX_FLAGS_DEBUG    "${CMAKE_CXX_FLAGS_DEBUG} -Wall -pg -march=native")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenCV 3.1.0 REQUIRED)
find_package(OpenNI2 REQUIRED)
find_package(PCL 1.7 REQUIRED)


include_directories(
        ${OPENCV_INCLUDE_DIRS}
        ${OPENNI2_INCLUDE_DIRS}
        ${PCL_INCLUDE_DIRS}
)

set(SOURCE_FILES main.cpp)
list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")
add_executable(floor_fit_cloud ${SOURCE_FILES})

target_link_libraries(floor_fit_cloud
        ${OpenCV_LIBS}
        ${OpenNI2_LIBRARIES}
        ${PCL_LIBRARIES}
        )
