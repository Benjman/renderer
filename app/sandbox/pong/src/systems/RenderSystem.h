#ifndef PONG_RENDERSYSTEM_H
#define PONG_RENDERSYSTEM_H

#include <entt/fwd.hpp>

class RenderSystem final {
	public:
		RenderSystem() = default;
		~RenderSystem() = default;

		void render(entt::registry &registry);
};

#endif // PONG_RENDERSYSTEM_H
