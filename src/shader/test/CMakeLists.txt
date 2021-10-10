find_package(Threads REQUIRED)

include_directories(
	../include
	../src
	)

add_executable(shader_tests
	./src/main.cpp
	./src/shader_test_fixture.cpp
	./src/vbo_test.cpp
	./src/vertex_attribute_test.cpp
	./src/shader_loader_test.cpp
	./src/vao_test.cpp
	./src/utils/glfw.cpp)

target_link_libraries(shader_tests
	${GL_LIBS}

	GTest::GTest
	GTest::Main

	shader)

target_include_directories(shader_tests PRIVATE ${GL_INCLUDES})

add_test(shader_tests shader_tests)
