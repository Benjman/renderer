project(camera_runner)

add_executable(camera_runner
	./main.cpp
	)

target_include_directories(camera_runner PRIVATE ${GL_INCLUDES})
target_link_libraries(camera_runner PRIVATE ${LIBS} Core)
