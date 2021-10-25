project(textured_cube_runner)

add_executable(textured_cube_runner
	./main.cpp
	)

target_include_directories(textured_cube_runner PRIVATE ${GL_INCLUDES})
target_link_libraries(textured_cube_runner PRIVATE ${LIBS} core)

