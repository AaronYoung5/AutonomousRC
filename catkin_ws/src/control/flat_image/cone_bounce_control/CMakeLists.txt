cmake_minimum_required(VERSION 2.8.3)
project(cone_bounce_control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  common_msgs
  common_utilities
  control_utilities
  opencv_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

catkin_package(

)

add_executable(cone_bounce_control src/main.cpp src/controller.cpp)
 target_link_libraries(cone_bounce_control ${catkin_LIBRARIES})
 add_dependencies(cone_bounce_control ${catkin_EXPORTED_TARGETS})
