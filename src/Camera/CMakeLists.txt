cmake_minimum_required(VERSION 3.18)
project(Camera)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

if (NOT CMAKE_MODULE_PATH)
	set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake/modules")
endif()

find_package(GTest REQUIRED)

add_library(Camera
	STATIC
	./src/Camera.cpp
	)

target_include_directories(Camera PUBLIC ./include)

add_subdirectory(test)

