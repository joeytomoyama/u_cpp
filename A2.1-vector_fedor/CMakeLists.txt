cmake_minimum_required(VERSION 3.5)

project(A2_1)

set(CMAKE_CXX_STANDARD "14")

set(SOURCE_FILES main.cpp payload.cpp test21.cpp)
add_executable(test_it ${SOURCE_FILES})