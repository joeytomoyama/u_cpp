cmake_minimum_required(VERSION 3.4)
project(GETTING_STARTED)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp vec3f.cpp)
add_executable(mein_programm ${SOURCE_FILES})