cmake_minimum_required(VERSION 3.5)
project(my_rviz_plugin)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rviz_common REQUIRED)
find_package(rviz_rendering REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${PROJECT_NAME} SHARED
    src/my_rviz_plugin.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    include
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    rviz_common::rviz_common
)

ament_target_dependencies(${PROJECT_NAME}
    rclcpp
    rviz_common
    rviz_rendering
)

install(
    TARGETS ${PROJECT_NAME}
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
