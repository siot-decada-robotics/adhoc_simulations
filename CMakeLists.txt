cmake_minimum_required(VERSION 3.5.0)

project(adhoc_simulations)


#===============================================================================
find_package(catkin QUIET)
find_package(gazebo REQUIRED)


if (catkin_FOUND)

  catkin_package()

  link_directories(${GAZEBO_LIBRARY_DIRS})
  include_directories(
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
  )

  install(
    DIRECTORY rviz
    DESTINATION share/${PROJECT_NAME}
  )

  install(
    DIRECTORY launch
    DESTINATION share/${PROJECT_NAME}
  )

  install(
    DIRECTORY maps
    DESTINATION share/${PROJECT_NAME}
  )

  install(
    DIRECTORY worlds
    DESTINATION share/${PROJECT_NAME}
  )

  install(
    DIRECTORY models
    DESTINATION share/${PROJECT_NAME}
  )

else()
  message("catkin not found so skipping this ROS1 package")
endif()
