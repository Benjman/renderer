project(Camera)

add_executable(Camera
	./main.cpp
	)

target_link_libraries(Camera PRIVATE ${LIBS} Core)
target_include_directories(Camera PRIVATE ${GL_INCLUDES})
