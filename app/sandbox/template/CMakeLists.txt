project(Template)

add_executable(Template
	./main.cpp
	./src/TemplateRunner.hpp
	)

target_link_libraries(Template PRIVATE ${LIBS} Core)
