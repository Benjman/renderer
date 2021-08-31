cmake_minimum_required(VERSION 3.18)
project(Pong)

add_executable(Pong
	./main.cpp
	./src/Pong.hpp
	./src/components/AI.cpp
	./src/components/Ball.cpp
	./src/components/Player.cpp
	./src/components/Position.cpp
	./src/components/Sprite.cpp
	./src/systems/AISystem.cpp
	./src/systems/CollisionSystem.cpp
	./src/systems/MoveSystem.cpp
	./src/systems/RenderSystem.cpp)

target_link_libraries(Pong PRIVATE ${LIBS} Core Shader)
target_include_directories(Pong PRIVATE ${ENTT_INCLUDE})
