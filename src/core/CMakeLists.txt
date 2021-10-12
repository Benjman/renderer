cmake_minimum_required(VERSION 3.18)
project(core)

add_library(core STATIC
	./src/file.cpp
    ./src/intput.cpp
	./src/runner.cpp
	./src/components/position2d.cpp
	./src/components/position3d.cpp
	./src/utils/glfw.cpp
	)

find_package(GLFW REQUIRED)

target_link_libraries(core
	PUBLIC camera shader text ${GL_LIBS}
	PRIVATE ${GL_LIBS})

target_include_directories(core
	PUBLIC ./include ${ENTT_INCLUDE} ${STB_INCLUDE}
	PRIVATE ${GL_INCLUDES})

add_subdirectory(test)
