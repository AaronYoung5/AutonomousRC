cmake_minimum_required(VERSION 2.8.3)
project(py_centerline_follower_circles)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	common_msgs
	perception_msgs
	control_utilities
	common_utilities
	rviz_visual_tools
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_python_setup()

catkin_package(

)

catkin_install_python(PROGRAMS nodes/py_centerline_follower_circles DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
