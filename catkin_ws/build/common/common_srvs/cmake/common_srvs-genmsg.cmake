# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "common_srvs: 0 messages, 2 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Icommon_msgs:/home/aaron/AutonomousRC/catkin_ws/src/common/common_msgs/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(common_srvs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv" NAME_WE)
add_custom_target(_common_srvs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_srvs" "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv" "geometry_msgs/Point"
)

get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv" NAME_WE)
add_custom_target(_common_srvs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_srvs" "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv" "common_msgs/Cone:geometry_msgs/Point"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_srvs
)
_generate_srv_cpp(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv"
  "${MSG_I_FLAGS}"
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_msgs/msg/Cone.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_srvs
)

### Generating Module File
_generate_module_cpp(common_srvs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_srvs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(common_srvs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(common_srvs_generate_messages common_srvs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_cpp _common_srvs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_cpp _common_srvs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_srvs_gencpp)
add_dependencies(common_srvs_gencpp common_srvs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_srvs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_srvs
)
_generate_srv_eus(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv"
  "${MSG_I_FLAGS}"
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_msgs/msg/Cone.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_srvs
)

### Generating Module File
_generate_module_eus(common_srvs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_srvs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(common_srvs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(common_srvs_generate_messages common_srvs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_eus _common_srvs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_eus _common_srvs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_srvs_geneus)
add_dependencies(common_srvs_geneus common_srvs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_srvs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_srvs
)
_generate_srv_lisp(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv"
  "${MSG_I_FLAGS}"
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_msgs/msg/Cone.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_srvs
)

### Generating Module File
_generate_module_lisp(common_srvs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_srvs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(common_srvs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(common_srvs_generate_messages common_srvs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_lisp _common_srvs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_lisp _common_srvs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_srvs_genlisp)
add_dependencies(common_srvs_genlisp common_srvs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_srvs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_srvs
)
_generate_srv_nodejs(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv"
  "${MSG_I_FLAGS}"
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_msgs/msg/Cone.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_srvs
)

### Generating Module File
_generate_module_nodejs(common_srvs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_srvs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(common_srvs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(common_srvs_generate_messages common_srvs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_nodejs _common_srvs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_nodejs _common_srvs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_srvs_gennodejs)
add_dependencies(common_srvs_gennodejs common_srvs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_srvs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_srvs
)
_generate_srv_py(common_srvs
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv"
  "${MSG_I_FLAGS}"
  "/home/aaron/AutonomousRC/catkin_ws/src/common/common_msgs/msg/Cone.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_srvs
)

### Generating Module File
_generate_module_py(common_srvs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_srvs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(common_srvs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(common_srvs_generate_messages common_srvs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/Path.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_py _common_srvs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/aaron/AutonomousRC/catkin_ws/src/common/common_srvs/srv/ConeMap.srv" NAME_WE)
add_dependencies(common_srvs_generate_messages_py _common_srvs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_srvs_genpy)
add_dependencies(common_srvs_genpy common_srvs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_srvs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_srvs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_srvs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(common_srvs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(common_srvs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET common_msgs_generate_messages_cpp)
  add_dependencies(common_srvs_generate_messages_cpp common_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_srvs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_srvs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(common_srvs_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(common_srvs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET common_msgs_generate_messages_eus)
  add_dependencies(common_srvs_generate_messages_eus common_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_srvs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_srvs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(common_srvs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(common_srvs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET common_msgs_generate_messages_lisp)
  add_dependencies(common_srvs_generate_messages_lisp common_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_srvs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_srvs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(common_srvs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(common_srvs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET common_msgs_generate_messages_nodejs)
  add_dependencies(common_srvs_generate_messages_nodejs common_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_srvs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_srvs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_srvs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(common_srvs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(common_srvs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET common_msgs_generate_messages_py)
  add_dependencies(common_srvs_generate_messages_py common_msgs_generate_messages_py)
endif()
