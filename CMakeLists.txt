cmake_minimum_required(VERSION 3.23)
project(Super_mario)

set(CMAKE_CXX_STANDARD 23)

add_executable(Super_mario main.cpp Cell.cpp Champion.cpp Map.cpp Gem.cpp Obstacle.cpp)
