find_package(Threads REQUIRED)

include_directories(
	../include
	../src
	)

add_executable(tests_camera
	./src/main.cpp
	)

target_link_libraries(tests_camera
	GTest::GTest
	GTest::Main

	camera)

add_test(tests_camera camera_tests)
