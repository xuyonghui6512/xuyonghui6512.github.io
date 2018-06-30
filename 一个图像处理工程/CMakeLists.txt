cmake_minimum_required(VERSION 3.5)
project(Myjob)

set(CMAKE_CXX_STANDARD 11)


SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CONFIGURATION_TYPES Debug Release)

set(CMAKE_C_FLAGS_RELEASE  "${CMAKE_C_FLAGS_RELEASE} -Wall -O3 -march=native")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -pg -march=native")

set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3 -march=native")
set(CMAKE_CXX_FLAGS_DEBUG    "${CMAKE_CXX_FLAGS_DEBUG} -Wall -pg -march=native")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

##OpenCV
find_package(OpenCV 3.1.0 REQUIRED)
include_directories(
        ${OPENCV_INCLUDE_DIRS}
)

##Sophus
find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )

##Eigen
include_directories( "/usr/include/eigen3" )

set( MY_PARTY_LIBS 
    ${OpenCV_LIBS}
${Sophus_LIBRARIES}
    
)

include_directories( ${PROJECT_SOURCE_DIR}/include )
add_subdirectory( src )
add_subdirectory( test )










