cmake_minimum_required(VERSION 3.5.0)

project(adhoc_simulations)


#===============================================================================
find_package(catkin QUIET)
find_package(ament_cmake QUIET)

find_package(catkin REQUIRED COMPONENTS
    gazebo_msgs
    roscpp
    std_msgs
    tf2_ros
    nav_msgs
  )


find_package(GAZEBO REQUIRED)


if (catkin_FOUND)

  catkin_package()
  

  link_directories(${GAZEBO_LIBRARY_DIRS})
  include_directories(
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
  )
  
  add_executable(odom_tf_node src/odom_tf.cpp)
  add_dependencies(odom_tf_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
  
   target_link_libraries(odom_tf_node
   ${catkin_LIBRARIES}
 )

  install(
    DIRECTORY launch maps models rviz tb3_urdf worlds scripts config
    DESTINATION share/${PROJECT_NAME}
    # DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )
  
  install(TARGETS
  odom_tf_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

else()

  ament_package()

  link_directories(${GAZEBO_LIBRARY_DIRS})
  include_directories(
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
  )
  
  add_library(odom_tf src/odom_tf.cpp)
  add_dependencies(odom_tf ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
  
  

  install(
    DIRECTORY launch maps models rviz tb3_urdf worlds scripts config
    DESTINATION share/${PROJECT_NAME}
  )
  
  install(TARGETS
  odom_tf
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

endif()
