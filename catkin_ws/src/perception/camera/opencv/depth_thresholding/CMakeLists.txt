cmake_minimum_required(VERSION 2.8.3)
project(depth_thresholding)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  perception_msgs
  cv_bridge
  image_transport
)

find_package( OpenCV 3 REQUIRED )

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

catkin_package(

)

add_executable(depth_thresholding src/main.cpp src/thresholder.cpp)
target_link_libraries(depth_thresholding ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(depth_thresholding ${catkin_EXPORTED_TARGETS})
