cmake_minimum_required(VERSION 3.18)
project(App)

add_subdirectory(./sandbox)

add_executable(App
	./main.cpp
	# ./main_test.cpp

	./SimplexNoise.h
	./SimplexNoise.cpp
	)


target_link_libraries(App PRIVATE
	${LIBS}

	Shader
	System
	)
