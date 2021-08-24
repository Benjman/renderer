#ifndef PONG_RENDERSYSTEM_H
#define PONG_RENDERSYSTEM_H

#include <entt/fwd.hpp>
#include <vector>
#include <gl.h>

class RenderSystem final {
	public:
		RenderSystem() = default;
		~RenderSystem() = default;

		void render(entt::registry &registry, int width, int height, std::vector<GLfloat> &texture);
};

#endif // PONG_RENDERSYSTEM_H
