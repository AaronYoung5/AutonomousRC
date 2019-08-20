cmake_minimum_required(VERSION 2.8.3)
project(point_cloud)

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

add_executable(point_cloud src/main.cpp src/point_cloud_thresholder.cpp)
target_link_libraries(point_cloud ${catkin_LIBRARIES}) 
add_dependencies(point_cloud ${catkin_EXPORTED_TARGETS})
