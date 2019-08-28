cmake_minimum_required(VERSION 2.8.3)
project(point_cloud_threshold_and_cluster)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  perception_msgs
  common_utilities
)

find_package(PCL 1.2 REQUIRED)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  include
)

catkin_package(

)

add_executable(point_cloud_threshold_and_cluster src/main.cpp src/cone_detector.cpp src/thresholder.cpp src/clusterer.cpp)
target_link_libraries(point_cloud_threshold_and_cluster ${catkin_LIBRARIES})
add_dependencies(point_cloud_threshold_and_cluster ${catkin_EXPORTED_TARGETS})
