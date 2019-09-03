cmake_minimum_required(VERSION 2.8.3)
project(odom_local_planner)

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

add_executable(odom_local_planner src/main.cpp src/controller.cpp)
target_link_libraries(odom_local_planner ${catkin_LIBRARIES})
add_dependencies(odom_local_planner ${catkin_EXPORTED_TARGETS})
