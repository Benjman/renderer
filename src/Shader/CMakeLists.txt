cmake_minimum_required(VERSION 3.18)
project(Shader)

if (NOT CMAKE_MODULE_PATH)
	set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake/modules")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_definitions("-DSHADER_DEBUG")
endif ()

find_package(GTest REQUIRED)
find_package(GLFW REQUIRED)

add_library(Shader
	STATIC
	${GLAD_C}
	./src/Shader.cpp
	./src/Texture.cpp
	./src/Uniform.cpp
	./src/Vao.cpp
	./src/Vbo.cpp
	./src/VertexAttribute.cpp
	)

target_include_directories(Shader
	PUBLIC ./include
	PRIVATE ${GL_INCLUDES})

target_link_libraries(Shader PRIVATE ${GL_LIBS})

add_subdirectory(test)
