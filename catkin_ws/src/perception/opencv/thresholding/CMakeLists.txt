cmake_minimum_required(VERSION 2.8.3)
project(opencv_thresholding)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  common_msgs
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

add_executable(opencv_thresholding src/main.cpp src/image_converter.cpp)
target_link_libraries(opencv_thresholding ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_dependencies(opencv_thresholding ${catkin_EXPORTED_TARGETS})
