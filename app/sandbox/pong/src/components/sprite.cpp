#include "sprite.h"

Sprite::Sprite(const int w, const int h, glm::vec3 col) noexcept
: width {w}, height {h}, color {col}, radius {0} {
}

Sprite::Sprite(const int radius, glm::vec3 col) noexcept
: radius {radius}, color {col}, width {0}, height {0} {
}

Sprite::Sprite(Sprite&& s) noexcept {
	this->color = s.color;
	this->height = s.height;
	this->radius = s.radius;
	this->width  = s.width;
}

Sprite& Sprite::operator=(Sprite&& s) noexcept {
	if (this != &s) {
		this->color = s.color;
		this->height = s.height;
		this->radius = s.radius;
		this->width  = s.width;
	}

	return *this;
}

