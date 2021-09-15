cmake_minimum_required(VERSION 3.18)
project(Camera)

add_executable(Camera
	./main.cpp
	)

target_link_libraries(Camera PRIVATE ${LIBS} Shader Core)
target_include_directories(Camera PRIVATE ${ENTT_INCLUDE})
