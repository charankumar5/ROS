cmake_minimum_required(VERSION 3.8)
project(my_rviz_plugin)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rviz_common REQUIRED)
find_package(pluginlib REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Add include directories
include_directories(
  include
  ${rviz_common_INCLUDE_DIRS}  # Include RViz directories
)

# Add the plugin source files
add_library(${PROJECT_NAME} SHARED
  src/my_plugin.cpp
)

# Link against RViz and Qt5 libraries
target_link_libraries(${PROJECT_NAME}
  rviz_common::rviz_common
  Qt5::Widgets
)

# Register the plugin description file
pluginlib_export_plugin_description_file(rviz_common src/plugins.xml)

# Export package dependencies
ament_target_dependencies(${PROJECT_NAME}
  rviz_common
  pluginlib
  Qt5
)

# Install targets
install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
)

# Install plugin XML
install(FILES src/plugins.xml
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
