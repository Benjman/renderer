cmake_minimum_required(VERSION 3.18)
project(GL)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/../../cmake/modules")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glad REQUIRED)
add_library(GL STATIC ./gl.cpp)

target_link_libraries(GL PRIVATE ${GL_LIBS})
target_include_directories(GL PUBLIC ./include ${GLAD_INCLUDE})
