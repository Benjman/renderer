find_package(Threads REQUIRED)

include_directories(
	../include
	../src
	)

add_executable(tests_core
	./src/main.cpp
    ./src/input_test.cpp
    )

target_link_libraries(tests_core
	${GL_LIBS}

	GTest::GTest
	GTest::Main

	core)

target_include_directories(tests_core PRIVATE ${GL_INCLUDES})

add_test(tests_core tests_core)
