cmake_minimum_required(VERSION 2.8.3)
<<<<<<< HEAD
project(circle_through_3_cones)
=======
project(cone_midpoint_control_2)
>>>>>>> 1b51b11038f65a072f38f4ab930e8301277e0079

find_package(catkin REQUIRED COMPONENTS
	roscpp
	common_msgs
	perception_msgs
	control_utilities
	common_utilities
)

include_directories(
<<<<<<< HEAD
  ${catkin_INCLUDE_DIRS}
=======
  ${catkin)INCLUDE_DIRS}
>>>>>>> 1b51b11038f65a072f38f4ab930e8301277e0079
  include
)

catkin_package(

)

add_executable(circle_through_3_cones src/main.cpp src/controller.cpp)
<<<<<<< HEAD
target_link_libraries(circle_through_3_cones ${catkin_LIBRARIES})
=======
target_lin_libraries(circle_through_3_cones ${catkin_LIBRARIES})
>>>>>>> 1b51b11038f65a072f38f4ab930e8301277e0079
add_dependencies(circle_through_3_cones ${catkin_EXPORTED_TARGETS})
