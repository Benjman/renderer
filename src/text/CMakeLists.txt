cmake_minimum_required(VERSION 3.18)
project(text)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

if (NOT CMAKE_MODULE_PATH)
	set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake/modules")
endif()

find_package(GTest REQUIRED)
find_package(stb REQUIRED)


add_library(text
	STATIC

	./src/font.cpp
	./src/generator.cpp
	./src/text.cpp
	)

target_link_libraries(text PRIVATE spdlog::spdlog)

target_include_directories(text
	PUBLIC ./include
	PRIVATE ${STB_INCLUDE})

#add_subdirectory(test)
