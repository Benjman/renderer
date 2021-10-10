find_package(Threads REQUIRED)

include_directories(
	../include
	../src
	)

add_executable(camera_tests
	./src/main.cpp
	)

target_link_libraries(camera_tests
	GTest::GTest
	GTest::Main

	camera)

add_test(camera_tests camera_tests)
