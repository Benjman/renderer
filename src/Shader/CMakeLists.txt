cmake_minimum_required(VERSION 3.18)
project(Shader)

add_library(Shader
	STATIC
	./src/Shader.cpp
	./src/Uniform.cpp
	./src/Vao.cpp
	./src/Vbo.cpp
	./src/VertexAttribute.cpp
	)

target_link_libraries(Shader PRIVATE ${LIBS} ${GL_LIBS} System)

target_include_directories(Shader PUBLIC ./include)

add_subdirectory(test)
