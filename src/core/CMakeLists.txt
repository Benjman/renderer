cmake_minimum_required(VERSION 3.18)
project(core)

add_library(core STATIC
    ./src/file.cpp
    ./src/glfw.cpp
    ./src/input.cpp
    ./src/runner.cpp
    ./src/window.cpp
    ./src/camera/camera.cpp
    ./src/camera/camera_controller.cpp
    ./src/components/position2d.cpp
    ./src/components/position3d.cpp
    ./src/ui/ui_element.cpp
    )

find_package(GLFW REQUIRED)

target_link_libraries(core
    PUBLIC shader text ${GL_LIBS}
    PRIVATE ${GL_LIBS}
    spdlog::spdlog)

target_include_directories(core
    PUBLIC ./include ${ENTT_INCLUDE} ${STB_INCLUDE}
    PRIVATE ${GL_INCLUDES})

add_subdirectory(test)
