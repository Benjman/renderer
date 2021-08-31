#ifndef BREAKOUT_POSITION_H
#define BREAKOUT_POSITION_H

#include <math.h>

struct Position final {
	double_t x;
	double_t y;

	Position(const double_t x, const double_t y) noexcept;
	Position(Position&&) noexcept;
	~Position() noexcept = default;

	Position &operator=(Position&&) noexcept;

};


#endif // BREAKOUT_POSITION_H
