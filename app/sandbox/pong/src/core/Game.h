#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <string>
#include <entt/entt.hpp>
#include <gl.h>

#include "../systems/AISystem.h"
#include "../systems/CollisionSystem.h"
#include "../systems/MoveSystem.h"
#include "../systems/RenderSystem.h"

class Game {
	public:
		Game(const char *title, const int width, const int height); 

		~Game() noexcept;

		const int run();

		void keyEvent(int key, int mode);

	private:
		const int width;
		const int height;
		std::vector<GLfloat> texture;
		entt::registry registry;
		entt::dispatcher dispatcher;
		AISystem ai_system;
		CollisionSystem collision_system;
		CollisionHolder collideables;
		MoveSystem move_system;
		RenderSystem render_system;

		Game() = delete;

		void update(const double time);

		void render();

};


#endif //PONG_GAME_H
