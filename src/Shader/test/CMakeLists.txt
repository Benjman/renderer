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
	./src/VaoTest.cpp)

target_link_libraries(ShaderTests
	${LIBS}

	GTest::GTest
	GTest::Main

	Shader
	System)

add_test(ShaderTests ShaderTests)
