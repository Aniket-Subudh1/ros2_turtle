cmake_minimum_required(VERSION 3.8)
project(turtle_circle)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# Add executable
add_executable(turtle_circle_node src/turtle_circle_node.cpp)
target_include_directories(turtle_circle_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  turtle_circle_node
  rclcpp
  geometry_msgs
)

# Install executable
install(TARGETS turtle_circle_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()