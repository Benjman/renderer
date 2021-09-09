#ifndef CORE_COMPONENTS_POSITION3D_H
#define CORE_COMPONENTS_POSITION3D_H

#include <math.h>

struct Position3D final {
	double_t x;
	double_t y;
	double_t z;

	Position3D(const double_t x, const double_t y, const double_t z) noexcept;
	Position3D(Position3D&&) noexcept;
	~Position3D() noexcept = default;

	Position3D &operator=(Position3D&&) noexcept;

};


#endif // CORE_COMPONENTS_POSITION3D_H
