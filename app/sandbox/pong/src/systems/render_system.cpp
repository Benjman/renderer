#include <entt/entt.hpp>

#include <core/components/position2d.h>

#include "../components/sprite.h"

#include "render_system.h"

void RenderSystem::render(entt::registry &registry, int width, int height, std::vector<GLfloat> &texture) {
	std::fill(texture.begin(), texture.end(), 0.1);
	auto view = registry.view<Sprite, Position2D>();
	view.each([&](const Sprite &sprite, const Position2D &position) {
		auto row_end = position.y + sprite.radius + sprite.height;
		auto col_end = position.x + sprite.radius + sprite.width;
		if (row_end > height) row_end = height;
		if (col_end > width) col_end = width;
		for (auto y = (uint32_t) position.y; y < row_end; y++) {
			for (auto x = (uint32_t)position.x; x < col_end; x++) {
				size_t location = (x + y * width) * 3;
				texture.at(location + 0) = sprite.color.r;
				texture.at(location + 1) = sprite.color.g;
				texture.at(location + 2) = sprite.color.b;
			}
		}
	});
}
