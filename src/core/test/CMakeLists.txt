find_package(Threads REQUIRED)

include_directories(
    ../include
    ../src
    )

add_executable(tests_core
    ./src/utils/gl_fixture.cpp

    ./src/controller_test.cpp
    ./src/main.cpp
    ./src/input_test.cpp
    ./src/math_test.cpp
    ./src/memory_test.cpp
    ./src/window.cpp

    ./src/ui/ui_element_test.cpp
    ./src/ui/ui_element_mesh_generator_test.cpp
    )

target_link_libraries(tests_core
    ${GL_LIBS}

    GTest::GTest
    GTest::Main

    core)

target_include_directories(tests_core PRIVATE ${GL_INCLUDES})

add_test(tests_core tests_core)
