cmake_minimum_required(VERSION 2.8.3)
project(tight_circle_control)

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

add_executable(tight_circle_control src/main.cpp)
target_link_libraries(tight_circle_control ${catkin_LIBRARIES})
add_dependencies(tight_circle_control ${catkin_EXPORTED_TARGETS})
