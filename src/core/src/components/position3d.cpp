#include <core/components/position3d.h>

Position3D::Position3D(const double_t x, const double_t y, const double_t z) noexcept 
: x(x), y(y), z(z) {
}

Position3D::Position3D(Position3D &&p) noexcept {
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
}

Position3D &Position3D::operator=(Position3D && p) noexcept {
	if (this != &p) {
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
	}
	return *this;
}

