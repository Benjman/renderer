cmake_minimum_required(VERSION 3.18)
project(Renderer)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
	enable_testing()
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")
set(THREADS_PREFER_PTHREAD_FLAG ON)

# set GL_LIBS
set(GL_LIBS ${GL_LIBS} glad glfw3)
if (UNIX AND NOT APPLE)
	find_package(X11 REQUIRED)
	find_package(Threads REQUIRED)
	set(GL_LIBS
		${GL_LIBS}
		${LIBRARIES}
		${X11_LIBRARIES}
		${X11_Xrandr_LIB}
		${CMAKE_DL_LIBS}
		Threads::Threads)
endif()

# ========== Libraries
add_subdirectory(./lib)
find_package(GTest REQUIRED)

find_package(spdlog REQUIRED)
set(LIBS ${LIBS} spdlog::spdlog Threads::Threads)
# ==========


add_subdirectory(./src/System)
add_subdirectory(./src/Shader)
add_subdirectory(./app)
