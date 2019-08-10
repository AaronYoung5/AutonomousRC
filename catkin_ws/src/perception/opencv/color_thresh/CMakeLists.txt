cmake_minimum_required(VERSION 2.8.3)
project(color_thresh)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  opencv_msgs
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

add_executable(color_thresh src/main.cpp src/color_thresholder.cpp)
target_link_libraries(color_thresh ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(color_thresh ${catkin_EXPORTED_TARGETS})
