#ifndef BREAKOUT_RENDERSYSTEM_H
#define BREAKOUT_RENDERSYSTEM_H

#include <entt/fwd.hpp>
#include <vector>
#include <gl.h>

class RenderSystem final {
	public:
		RenderSystem() = default;

		void render(entt::registry &registry);

		void setViewport(int width, int height);

	private:
		int width;
		int height;
		std::vector<GLfloat> m_texture;

};

#endif // BREAKOUT_RENDERSYSTEM_H
