cmake_minimum_required(VERSION 3.18)
project(Core)

add_library(Core STATIC
	./src/Game.cpp
	)

target_link_libraries(Core PRIVATE GL Shader)
target_include_directories(Core PUBLIC ${ENTT_INCLUDE} ./include)
