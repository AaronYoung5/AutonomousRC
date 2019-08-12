cmake_minimum_required(VERSION 2.8.3)
project(straight_line_control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  common_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

catkin_package(

)

add_executable(straight_line_control src/main.cpp)
target_link_libraries(straight_line_control ${catkin_LIBRARIES})
add_dependencies(straight_line_control ${catkin_EXPORTED_TARGETS})
