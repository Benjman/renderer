project(ui_demo)

add_executable(ui_demo
    ./main.cpp

    ./src/ui_demo.h
    )

target_include_directories(ui_demo PRIVATE ${GL_INCLUDES})
target_link_libraries(ui_demo PRIVATE ${LIBS} core)

