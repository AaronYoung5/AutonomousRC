cmake_minimum_required(VERSION 2.8.3)
project(cone_midpoint_control_2)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	common_msgs
	perception_msgs
	control_utilities
	common_utilities
)

include_directories(
  ${catkin)INCLUDE_DIRS}
  include
)

catkin_package(

)

add_executable(circle_through_3_cones src/main.cpp src/controller.cpp)
target_lin_libraries(circle_through_3_cones ${catkin_LIBRARIES})
add_dependencies(circle_through_3_cones ${catkin_EXPORTED_TARGETS})
