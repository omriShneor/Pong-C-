cmake_minimum_required(VERSION 3.9)
project(untitled)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE Debug)

add_executable(untitled main.cpp Ball.h Paddle.h GameManager.h)