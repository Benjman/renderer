project(Breakout)

add_executable(Breakout
	./main.cpp
	./src/BreakoutRunner.hpp
	./src/components/Ball.cpp
	./src/components/Block.cpp
	./src/components/Player.cpp
	./src/components/Sprite.cpp
	./src/systems/CollisionSystem.cpp
	./src/systems/MoveSystem.cpp
	./src/systems/RenderSystem.cpp)

target_link_libraries(Breakout PRIVATE ${LIBS} Core)
target_include_directories(Breakout PRIVATE ${GL_INCLUDES})
