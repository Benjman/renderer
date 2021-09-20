cmake_minimum_required(VERSION 3.18)
project(Text)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

if (NOT CMAKE_MODULE_PATH)
	set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake/modules")
endif()

find_package(GLFW REQUIRED)
find_package(GTest REQUIRED)
find_package(glad REQUIRED)
find_package(stb REQUIRED)

add_library(Text
	STATIC
	${GLAD_C}

	./src/Font.cpp
	./src/Flags.cpp)

target_include_directories(Text
	PUBLIC ./include

	PRIVATE
	${STB_INCLUDE}
	${GLAD_INCLUDE})

target_link_libraries(Text PRIVATE ${CMAKE_DL_LIBS} ${GLFW_LIBRARY})

add_subdirectory(test)
