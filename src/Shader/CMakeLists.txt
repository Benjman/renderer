cmake_minimum_required(VERSION 3.18)
project(Shader)

find_package(GTest REQUIRED)

add_library(Shader
	STATIC
	./src/Shader.cpp
	./src/Uniform.cpp
	./src/Vao.cpp
	./src/Vbo.cpp
	./src/VertexAttribute.cpp
	)

target_include_directories(Shader PUBLIC ./include)
target_link_libraries(Shader PUBLIC GL)

add_subdirectory(test)
