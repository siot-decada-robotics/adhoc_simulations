cmake_minimum_required(VERSION 3.5.0)

project(adhoc_simulations)


#===============================================================================
find_package(catkin QUIET)
find_package(ament_cmake QUIET)


find_package(GAZEBO REQUIRED)


if (catkin_FOUND)

  catkin_package()

  link_directories(${GAZEBO_LIBRARY_DIRS})
  include_directories(
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
  )

  install(
    DIRECTORY launch maps models rviz tb3_urdf worlds scripts tb3_navigation
    DESTINATION share/${PROJECT_NAME}
    # DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

else()

  ament_package()

  link_directories(${GAZEBO_LIBRARY_DIRS})
  include_directories(
    ${catkin_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS}
  )

  install(
    DIRECTORY launch maps models rviz tb3_urdf worlds scripts tb3_navigation
    DESTINATION share/${PROJECT_NAME}
  )

endif()
