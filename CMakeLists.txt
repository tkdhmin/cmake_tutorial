cmake_minimum_required(VERSION 3.10)
project(FactorialProject)

# C++ 14 Setting
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Factorial library
add_library(factorial factorial.cpp)

# Target creation
add_executable(main main.cpp)
target_link_libraries(main PRIVATE factorial)

# Google Test Setting
enable_testing()
add_subdirectory(external/googletest)
add_subdirectory(tests)