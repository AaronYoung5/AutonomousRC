cmake_minimum_required(VERSION 2.8.3)
project(figure_eight_control)

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

add_executable(figure_eight_control src/main.cpp)
target_link_libraries(figure_eight_control ${catkin_LIBRARIES})
add_dependencies(figure_eight_control ${catkin_EXPORTED_TARGETS})
