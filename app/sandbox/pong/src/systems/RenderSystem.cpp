#include <entt/entt.hpp>

#include "RenderSystem.h"

#include "../components/Position.h"
#include "../components/Sprite.h"

void RenderSystem::render(entt::registry &registry, int width, int height, std::vector<GLfloat> &texture) {
	std::fill(texture.begin(), texture.end(), 0.1);
	auto view = registry.view<Sprite, Position>();
	view.each([&](const Sprite &sprite, const Position &position) {
		auto row_end = position.m_y + sprite.radius + sprite.height;
		auto col_end = position.m_x + sprite.radius + sprite.width;
		if (row_end > height) row_end = height;
		if (col_end > width) col_end = width;
		for (auto y = (uint32_t) position.m_y; y < row_end; y++) {
			for (auto x = (uint32_t)position.m_x; x < col_end; x++) {
				size_t location = (x + y * width) * 3;
				texture.at(location + 0) = sprite.color.r;
				texture.at(location + 1) = sprite.color.g;
				texture.at(location + 2) = sprite.color.b;
			}
		}
	});
}
