cmake_minimum_required(VERSION 3.4)
project(GETTING_STARTED)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp test11.cpp)
add_executable(mein_programm ${SOURCE_FILES})