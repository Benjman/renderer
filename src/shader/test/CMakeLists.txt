find_package(Threads REQUIRED)

include_directories(
	../include
	../src
	)

add_executable(tests_shader
	./src/main.cpp
	./src/shader_test_fixture.cpp
	./src/vbo_test.cpp
	./src/vertex_attribute_test.cpp
	./src/shader_loader_test.cpp
	./src/vao_test.cpp
	./src/utils/glfw.cpp)

target_link_libraries(tests_shader
	${GL_LIBS}

	GTest::GTest
	GTest::Main

	shader)

target_include_directories(tests_shader PRIVATE ${GL_INCLUDES})

add_test(tests_shader tests_shader)
