# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/hitcrt/lab/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/hitcrt/lab/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hitcrt/code/floor_fit_cloud

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hitcrt/code/floor_fit_cloud/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/floor_fit_cloud.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/floor_fit_cloud.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/floor_fit_cloud.dir/flags.make

CMakeFiles/floor_fit_cloud.dir/main.cpp.o: CMakeFiles/floor_fit_cloud.dir/flags.make
CMakeFiles/floor_fit_cloud.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hitcrt/code/floor_fit_cloud/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/floor_fit_cloud.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/floor_fit_cloud.dir/main.cpp.o -c /home/hitcrt/code/floor_fit_cloud/main.cpp

CMakeFiles/floor_fit_cloud.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/floor_fit_cloud.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hitcrt/code/floor_fit_cloud/main.cpp > CMakeFiles/floor_fit_cloud.dir/main.cpp.i

CMakeFiles/floor_fit_cloud.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/floor_fit_cloud.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hitcrt/code/floor_fit_cloud/main.cpp -o CMakeFiles/floor_fit_cloud.dir/main.cpp.s

CMakeFiles/floor_fit_cloud.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/floor_fit_cloud.dir/main.cpp.o.requires

CMakeFiles/floor_fit_cloud.dir/main.cpp.o.provides: CMakeFiles/floor_fit_cloud.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/floor_fit_cloud.dir/build.make CMakeFiles/floor_fit_cloud.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/floor_fit_cloud.dir/main.cpp.o.provides

CMakeFiles/floor_fit_cloud.dir/main.cpp.o.provides.build: CMakeFiles/floor_fit_cloud.dir/main.cpp.o


# Object files for target floor_fit_cloud
floor_fit_cloud_OBJECTS = \
"CMakeFiles/floor_fit_cloud.dir/main.cpp.o"

# External object files for target floor_fit_cloud
floor_fit_cloud_EXTERNAL_OBJECTS =

../bin/floor_fit_cloud: CMakeFiles/floor_fit_cloud.dir/main.cpp.o
../bin/floor_fit_cloud: CMakeFiles/floor_fit_cloud.dir/build.make
../bin/floor_fit_cloud: /usr/local/lib/libopencv_videostab.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_superres.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_stitching.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_shape.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_photo.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_objdetect.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_calib3d.so.3.1.0
../bin/floor_fit_cloud: /usr/lib/libOpenNI2.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_system.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_thread.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_regex.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_common.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
../bin/floor_fit_cloud: /usr/local/lib/libpcl_kdtree.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_octree.so
../bin/floor_fit_cloud: /usr/lib/libOpenNI2.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_io.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_search.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_visualization.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_sample_consensus.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_filters.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_features.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_registration.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_ml.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_recognition.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libqhull.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_surface.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_segmentation.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_keypoints.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_tracking.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_stereo.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_outofcore.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_people.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_system.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_thread.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libboost_regex.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libqhull.so
../bin/floor_fit_cloud: /usr/lib/libOpenNI2.so
../bin/floor_fit_cloud: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
../bin/floor_fit_cloud: /usr/lib/libvtkGenericFiltering.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkGeovis.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkCharts.so.5.10.1
../bin/floor_fit_cloud: /usr/local/lib/libopencv_features2d.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_ml.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_highgui.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_videoio.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_flann.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_video.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_imgproc.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libopencv_core.so.3.1.0
../bin/floor_fit_cloud: /usr/local/lib/libpcl_common.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_kdtree.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_octree.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_io.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_search.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_visualization.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_sample_consensus.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_filters.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_features.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_registration.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_ml.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_recognition.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_surface.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_segmentation.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_keypoints.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_tracking.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_stereo.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_outofcore.so
../bin/floor_fit_cloud: /usr/local/lib/libpcl_people.so
../bin/floor_fit_cloud: /usr/lib/libvtkViews.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkInfovis.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkWidgets.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkVolumeRendering.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkHybrid.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkParallel.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkRendering.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkImaging.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkGraphics.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkIO.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkFiltering.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtkCommon.so.5.10.1
../bin/floor_fit_cloud: /usr/lib/libvtksys.so.5.10.1
../bin/floor_fit_cloud: CMakeFiles/floor_fit_cloud.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hitcrt/code/floor_fit_cloud/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/floor_fit_cloud"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/floor_fit_cloud.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/floor_fit_cloud.dir/build: ../bin/floor_fit_cloud

.PHONY : CMakeFiles/floor_fit_cloud.dir/build

CMakeFiles/floor_fit_cloud.dir/requires: CMakeFiles/floor_fit_cloud.dir/main.cpp.o.requires

.PHONY : CMakeFiles/floor_fit_cloud.dir/requires

CMakeFiles/floor_fit_cloud.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/floor_fit_cloud.dir/cmake_clean.cmake
.PHONY : CMakeFiles/floor_fit_cloud.dir/clean

CMakeFiles/floor_fit_cloud.dir/depend:
	cd /home/hitcrt/code/floor_fit_cloud/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hitcrt/code/floor_fit_cloud /home/hitcrt/code/floor_fit_cloud /home/hitcrt/code/floor_fit_cloud/cmake-build-debug /home/hitcrt/code/floor_fit_cloud/cmake-build-debug /home/hitcrt/code/floor_fit_cloud/cmake-build-debug/CMakeFiles/floor_fit_cloud.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/floor_fit_cloud.dir/depend

