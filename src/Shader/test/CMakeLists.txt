find_package(Threads REQUIRED)

include_directories(
	../include
	../src
	)

add_executable(ShaderTests
	./src/main.cpp
	./src/ShaderTestFixture.cpp
	./src/VboTest.cpp
	./src/VertexAttributeTest.cpp
	./src/ShaderLoaderTest.cpp
	./src/VaoTest.cpp
	./src/utils/glfw.cpp)

target_link_libraries(ShaderTests
	${GL_LIBS}

	GTest::GTest
	GTest::Main

	Shader)

target_include_directories(ShaderTests PRIVATE ${GL_INCLUDES})

add_test(ShaderTests ShaderTests)
