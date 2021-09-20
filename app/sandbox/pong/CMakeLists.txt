project(Pong)

add_executable(Pong
	./main.cpp
	./src/PongRunner.hpp
	./src/components/AI.cpp
	./src/components/Ball.cpp
	./src/components/Player.cpp
	./src/components/Sprite.cpp
	./src/systems/AISystem.cpp
	./src/systems/CollisionSystem.cpp
	./src/systems/MoveSystem.cpp
	./src/systems/RenderSystem.cpp)

target_link_libraries(Pong PRIVATE ${LIBS} Core)
