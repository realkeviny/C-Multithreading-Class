cmake_minimum_required(VERSION 3.28) 

project(DoubleCheckedLocking VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(EXECUTABLE_NAME Homework)

add_subdirectory(configured)
add_subdirectory(app)
