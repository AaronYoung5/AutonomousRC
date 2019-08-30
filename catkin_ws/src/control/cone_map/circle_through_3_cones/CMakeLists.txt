cmake_minimum_required(VERSION 2.8.3)
project(circle_through_3_cones)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	common_msgs
	perception_msgs
	control_utilities
	common_utilities
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

catkin_package(

)

add_executable(circle_through_3_cones src/main.cpp src/controller.cpp)
target_link_libraries(circle_through_3_cones ${catkin_LIBRARIES})
add_dependencies(circle_through_3_cones ${catkin_EXPORTED_TARGETS})
