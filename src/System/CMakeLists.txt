cmake_minimum_required(VERSION 3.18)
project(System)

add_library(System STATIC
	./src/glfw.cpp
	)

target_link_libraries(System PUBLIC ${GL_LIBS})
target_include_directories(System PUBLIC ./include)
