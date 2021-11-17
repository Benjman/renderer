cmake_minimum_required(VERSION 3.18)
project(app)

add_subdirectory(./sandbox)

add_executable(app
    ./main.cpp
    # ./main_test.cpp
    ${GLAD_C}

    ./SimplexNoise.h
    ./SimplexNoise.cpp
    )

target_link_libraries(app PRIVATE ${LIBS} core ${GL_LIBS})
target_include_directories(app PRIVATE ${GL_INCLUDES})
