project(TextRunner)

add_executable(TextRunner
	./main.cpp
	)

target_include_directories(TextRunner PRIVATE ${GL_INCLUDES})
target_link_libraries(TextRunner PRIVATE ${LIBS} Core)
