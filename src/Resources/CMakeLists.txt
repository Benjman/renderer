cmake_minimum_required(VERSION 3.18)
project(Resources)

add_library(Resources src/resources.cpp)
target_include_directories(Resources PUBLIC include)
