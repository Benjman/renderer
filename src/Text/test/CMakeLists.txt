find_package(Threads REQUIRED)

include_directories(
	../include
	../src

	${STB_INCLUDE}
	)

add_executable(TextTests
	./src/FontLoaderTest.cpp
	./src/main.cpp
	./src/TextTest.cpp
	./src/TextStructureTests.cpp
	)

target_link_libraries(TextTests
	GTest::GTest
	GTest::Main

	Text)

add_test(TextTests TextTests)
