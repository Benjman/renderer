project(TextRunner)

add_executable(TextRunner
	./main.cpp
	)

target_link_libraries(TextRunner PRIVATE ${LIBS} Core)
