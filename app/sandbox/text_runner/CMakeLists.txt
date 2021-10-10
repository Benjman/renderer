project(text_runner)

add_executable(text_runner
	./main.cpp
	)

target_include_directories(text_runner PRIVATE ${GL_INCLUDES})
target_link_libraries(text_runner PRIVATE ${LIBS} core)
