find_package(Threads REQUIRED)

include_directories(
	../include
	../src
	)

add_executable(CameraTests
	./src/main.cpp
	./src/OrthographicCameraTests.cpp
	)

target_link_libraries(CameraTests
	GTest::GTest
	GTest::Main

	Camera)

add_test(CameraTests CameraTests)
