#ifndef BREAKOUT_SPRITE_H
#define BREAKOUT_SPRITE_H

#include <glm/vec3.hpp>

struct Sprite final {
		int width;
		int height;
		int radius;
		glm::vec3 color;

		Sprite(const int w, const int h, glm::vec3 color) noexcept;
		Sprite(const int radius, glm::vec3 color) noexcept;
		Sprite(Sprite&&) noexcept;
		~Sprite() noexcept = default;
		Sprite& operator=(Sprite&&) noexcept;

};

#endif // BREAKOUT_SPRITE_H
