#include "RenderSystem.h"

#include <entt/entt.hpp>

#include "../components/Position.h"
#include "../components/Sprite.h"

void RenderSystem::render(entt::registry &registry) {
	std::fill(m_texture.begin(), m_texture.end(), 0.25);
	auto view = registry.view<Sprite, Position>();
	view.each([&](const Sprite &sprite, const Position &pos) {
		int x_start = pos.x;
		int x_end = x_start + sprite.width + sprite.radius;
		int y_start = pos.y;
		int y_end = y_start + sprite.height + sprite.radius;
		x_start = std::clamp(x_start, 0, width);
		x_end = std::clamp(x_end, 0, width);
		y_start = std::clamp(y_start, 0, height);
		y_end = std::clamp(y_end, 0, height);
		for (auto y = (uint32_t) pos.y; y < y_end; y++) {
			for (auto x = (uint32_t)pos.x; x < x_end; x++) {
				size_t location = (x + y * width) * 3;
				m_texture.at(location + 0) = sprite.color.r;
				m_texture.at(location + 1) = sprite.color.g;
				m_texture.at(location + 2) = sprite.color.b;
			}
		}
	});

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_FLOAT, &m_texture.at(0));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void RenderSystem::setViewport(int width, int height) {
	this->width = width;
	this->height = height;
	m_texture = std::vector<GLfloat>(width * height * 3);
}
