project(CameraRunner)

add_executable(CameraRunner
	./main.cpp
	)

target_include_directories(CameraRunner PRIVATE ${GL_INCLUDES})
target_link_libraries(CameraRunner PRIVATE ${LIBS} Core)
