cmake_minimum_required(VERSION 3.18)
project(Text)

add_executable(Text
	./main.cpp
	./src/TextRunner.hpp
	)

target_link_libraries(Text PRIVATE ${LIBS} Core Shader)
target_include_directories(Text PRIVATE ${ENTT_INCLUDE})
