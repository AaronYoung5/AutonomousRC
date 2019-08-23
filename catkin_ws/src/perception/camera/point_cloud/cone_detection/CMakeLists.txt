cmake_minimum_required(VERSION 2.8.3)
project(pcl_cone_detect)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  perception_msgs
  image_transport
)

find_package( OpenCV 3 REQUIRED )

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

catkin_package(

)

add_executable(pcl_cone_detect src/main.cpp src/pcl_detector.cpp)
target_link_libraries(pcl_cone_detect ${catkin_LIBRARIES}) 
add_dependencies(pcl_cone_detect ${catkin_EXPORTED_TARGETS})
