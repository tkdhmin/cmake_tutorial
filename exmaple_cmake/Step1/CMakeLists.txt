cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file("${PROJECT_SOURCE_DIR}/TutorialConfig.h.in" "${PROJECT_SOURCE_DIR}/TutorialConfig.h")

add_executable(Tutorial tutorial.cxx)

target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")