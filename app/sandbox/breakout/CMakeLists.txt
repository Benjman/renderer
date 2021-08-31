cmake_minimum_required(VERSION 3.18)
project(Breakout)

add_executable(Breakout
	./main.cpp
	./src/Breakout.hpp
	./src/components/Ball.cpp
	./src/components/Block.cpp
	./src/components/Player.cpp
	./src/components/Position.cpp
	./src/components/Sprite.cpp
	./src/systems/CollisionSystem.cpp
	./src/systems/MoveSystem.cpp
	./src/systems/RenderSystem.cpp
	)

target_link_libraries(Breakout PRIVATE ${LIBS} Shader Core)
target_include_directories(Breakout PRIVATE ${ENTT_INCLUDE})
