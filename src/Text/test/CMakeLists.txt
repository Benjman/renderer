find_package(Threads REQUIRED)

find_package(glad REQUIRED)

include_directories(
	../include
	../src

	${STB_INCLUDE}
	${GLAD_INCLUDE}
	)

add_executable(TextTests
	./src/utils/glfw.cpp
	./src/FontLoaderTest.cpp
	./src/main.cpp
	./src/TextTest.cpp
	./src/TextStructureTests.cpp
	${GLAD_C}
	)

target_link_libraries(TextTests
	GTest::GTest
	GTest::Main

	Text)

add_test(TextTests TextTests)
