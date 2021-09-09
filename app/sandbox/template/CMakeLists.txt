cmake_minimum_required(VERSION 3.18)
project(Template)

add_executable(Template
	./main.cpp
	./src/TemplateRunner.hpp
	)

target_link_libraries(Template PRIVATE ${LIBS} Core Shader)
target_include_directories(Template PRIVATE ${ENTT_INCLUDE})
