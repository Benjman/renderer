project(pong)

add_executable(pong
    ./main.cpp
    ./src/pong_runner.hpp
    ./src/components/ai.cpp
    ./src/components/ball.cpp
    ./src/components/player.cpp
    ./src/components/sprite.cpp
    ./src/systems/ai_system.cpp
    ./src/systems/collision_system.cpp
    ./src/systems/move_system.cpp
    ./src/systems/render_system.cpp)

target_include_directories(pong PRIVATE ${GL_INCLUDES})
target_link_libraries(pong PRIVATE ${LIBS} core)
