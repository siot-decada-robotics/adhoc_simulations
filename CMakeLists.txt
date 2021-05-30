cmake_minimum_required(VERSION 3.5.0)

project(adhoc_simulations)


#===============================================================================
find_package(catkin QUIET)
find_package(GAZEBO REQUIRED)


if (catkin_FOUND)

  catkin_package()

  link_directories(${GAZEBO_LIBRARY_DIRS})
  include_directories(
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
  )

  install(
    DIRECTORY rviz
    # DESTINATION share/${PROJECT_NAME}
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

  install(
    DIRECTORY launch
    # DESTINATION share/${PROJECT_NAME}
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

  install(
    DIRECTORY maps
    # DESTINATION share/${PROJECT_NAME}
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

  install(
    DIRECTORY worlds
    # DESTINATION share/${PROJECT_NAME}
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

  install(
    DIRECTORY models
    # DESTINATION share/${PROJECT_NAME}
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

else()
  message("catkin not found so skipping this ROS1 package")
endif()
