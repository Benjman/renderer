find_package(Threads REQUIRED)

include_directories(
	../include
	../src

	${STB_INCLUDE}
	)

add_executable(tests_text
	./src/font_loader_test.cpp
	./src/main.cpp
    ./src/text_builder_test.cpp
    ./src/text_test_fixture.cpp
    #./src/text_test.cpp
    #./src/text_structure_tests.cpp
	)

target_link_libraries(tests_text
	GTest::GTest
	GTest::Main

	text)

add_test(tests_text tests_text)
