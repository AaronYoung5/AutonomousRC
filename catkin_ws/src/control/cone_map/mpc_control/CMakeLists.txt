cmake_minimum_required(VERSION 2.8.3)
project(mpc_control)

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

add_executable(mpc_control src/main.cpp src/controller.cpp)
target_link_libraries(mpc_control ${catkin_LIBRARIES})
add_dependencies(mpc_controlmpc_control ${catkin_EXPORTED_TARGETS})
