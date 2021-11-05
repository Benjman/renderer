cmake_minimum_required(VERSION 3.18)
project(shader)

if (NOT CMAKE_MODULE_PATH)
	set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake/modules")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_definitions("-DSHADER_DEBUG")
endif ()

find_package(GTest REQUIRED)
find_package(GLFW REQUIRED)

add_library(shader
	STATIC
	${GLAD_C}
	./src/shader.cpp
	./src/texture.cpp
	./src/uniform.cpp
	./src/vao.cpp
	./src/vbo.cpp
	./src/vertex_attribute.cpp
	)

target_include_directories(shader
	PUBLIC ./include
	PRIVATE ${GL_INCLUDES})

target_link_libraries(shader PRIVATE ${GL_LIBS} spdlog::spdlog)

add_subdirectory(test)
