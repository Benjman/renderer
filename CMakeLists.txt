cmake_minimum_required(VERSION 3.18)
project(Renderer)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
	enable_testing() # TODO should this be in its own if block?
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")
set(CMAKE_CONFIG_PATH ${CMAKE_CONFIG_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(THREADS_PREFER_PTHREAD_FLAG ON)
message("${CMAKE_CONFIG_PATH}")

configure_file(${CMAKE_CONFIG_PATH}/core/include/config.h.in ${CMAKE_SOURCE_DIR}/src/core/include/core/config.h)

find_package(GLFW REQUIRED)
find_package(GTest REQUIRED)

find_package(spdlog REQUIRED)
set(LIBS ${LIBS} spdlog::spdlog Threads::Threads)

add_subdirectory(./app)
add_subdirectory(./lib)
add_subdirectory(./src/camera)
add_subdirectory(./src/core)
add_subdirectory(./src/shader)
add_subdirectory(./src/text)
