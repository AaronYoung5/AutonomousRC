cmake_minimum_required(VERSION 2.8.3)
project(midpoint_path2)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  # opencv_msgs
  # cv_bridge
  # image_transport
)

find_package( OpenCV 3 REQUIRED )

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

catkin_package(

)

# add_executable(image2d_midpoint_path src/main.cpp src/image_converter.cpp)
 # target_link_libraries(image2d_midpoint_path ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
#
 # add_dependencies(image2d_midpoint_path ${catkin_EXPORTED_TARGETS})
