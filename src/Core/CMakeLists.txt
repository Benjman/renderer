cmake_minimum_required(VERSION 3.18)
project(Core)

add_library(Core STATIC
	./src/Camera2D.cpp
	./src/File.cpp
	./src/Runner.cpp
	./src/components/Position2D.cpp
	./src/components/Position3D.cpp
	./src/utils/glfw.cpp
	)

find_package(GLFW REQUIRED)

target_link_libraries(Core
	PUBLIC Camera Shader Text ${GL_LIBS}
	PRIVATE ${GL_LIBS})

target_include_directories(Core
	PUBLIC ./include ${ENTT_INCLUDE} ${STB_INCLUDE}
	PRIVATE ${GL_INCLUDES})
