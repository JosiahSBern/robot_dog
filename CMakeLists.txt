cmake_minimum_required(VERSION 3.5)
project(robot_dog)


# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)

# Override system turtlesim with local version

# Add src as an include directory
include_directories(src)

# Main executable source files
set(ROBOT_DOG_SOURCES
  src/Environment.cpp
  src/GameEnvironment.cpp
  src/Turtle.cpp
  src/TrashTurtle.cpp
  src/TeleopTurtle.cpp 
  src/main.cpp
)

# Main executable for the game environment
add_executable(robot_dog ${ROBOT_DOG_SOURCES})
ament_target_dependencies(robot_dog
    rclcpp
    turtlesim
    geometry_msgs
)


# Separate executable for teleop control
add_executable(teleop_turtle
  src/TeleopTurtle.cpp
  src/Turtle.cpp
  src/TeleopMain.cpp
)

# Link libraries and dependencies for robot_dog
ament_target_dependencies(robot_dog
    rclcpp
    turtlesim
    geometry_msgs
)

# Link libraries and dependencies for teleop_turtle
ament_target_dependencies(teleop_turtle
  rclcpp
  turtlesim
  geometry_msgs
)

# Install the executables
install(TARGETS 
  robot_dog
  teleop_turtle
  DESTINATION lib/${PROJECT_NAME}
)


# Install headers
install(DIRECTORY src/
    DESTINATION include/${PROJECT_NAME}
    FILES_MATCHING PATTERN "*.h"
)

# Declare the package
ament_package()
