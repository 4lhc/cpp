cmake_minimum_required(VERSION 2.8)

project(Apr21)
add_executable(${PROJECT_NAME} "main.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 11)
