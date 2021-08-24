#include <entt/entt.hpp>

#include "RenderSystem.h"

#include "../components/Position.h"
#include "../components/Sprite.h"

void RenderSystem::render(entt::registry &registry) {
	auto view = registry.view<Sprite, Position>();
	view.each([&](const auto &spr, auto &pos) {
			if (spr.radius != 0) {
			} else {
			}
	});
}
