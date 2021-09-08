cmake_minimum_required(VERSION 3.18)
project(Core)

add_library(Core STATIC
	./src/Camera2D.cpp
	./src/Game.cpp
	./src/Texture.cpp
	./src/components/Position2D.cpp
	./src/components/Position3D.cpp
	)

target_link_libraries(Core PRIVATE GL Shader)
target_include_directories(Core PUBLIC ${ENTT_INCLUDE} ./include)
