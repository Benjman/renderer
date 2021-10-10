#ifndef CORE_COMPONENTS_POSITION2D_H
#define CORE_COMPONENTS_POSITION2D_H

#include <math.h>

struct Position2D final {
	double_t x;
	double_t y;

	Position2D(const double_t x, const double_t y) noexcept;
	Position2D(Position2D&&) noexcept;
	~Position2D() noexcept = default;

	Position2D &operator=(Position2D&&) noexcept;

};


#endif // CORE_COMPONENTS_POSITION2D_H
