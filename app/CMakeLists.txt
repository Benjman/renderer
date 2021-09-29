cmake_minimum_required(VERSION 3.18)
project(App)

add_subdirectory(./sandbox)

add_executable(App
	./main.cpp
	# ./main_test.cpp
	${GLAD_C}

	./utils/glfw.cpp

	./SimplexNoise.h
	./SimplexNoise.cpp
	)

target_link_libraries(App PRIVATE ${LIBS} Core ${GL_LIBS})
target_include_directories(App PRIVATE ${GL_INCLUDES})
