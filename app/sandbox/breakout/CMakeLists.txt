project(breakout)

add_executable(breakout
    ./main.cpp
    ./src/breakout_runner.hpp
    ./src/components/ball.cpp
    ./src/components/block.cpp
    ./src/components/player.cpp
    ./src/components/sprite.cpp
    ./src/systems/collision_system.cpp
    ./src/systems/move_system.cpp
    ./src/systems/render_system.cpp)

target_link_libraries(breakout PRIVATE ${LIBS} core)
target_include_directories(breakout PRIVATE ${GL_INCLUDES})
