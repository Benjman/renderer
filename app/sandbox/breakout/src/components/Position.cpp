#include "Position.h"

Position::Position(const double_t x, const double_t y) noexcept 
: x(x), y(y) {
}

Position::Position(Position &&p) noexcept {
	this->x = p.x;
	this->y = p.y;
}

Position &Position::operator=(Position && p) noexcept {
	if (this != &p) {
		this->x = p.x;
		this->y = p.y;
	}
	return *this;
}

