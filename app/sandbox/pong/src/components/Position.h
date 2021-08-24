#ifndef PONG_POSITION_H
#define PONG_POSITION_H

#include <math.h>

class Position final {
	public:
		Position(const double_t x, const double_t y) noexcept;
		Position(Position&&) noexcept;
		~Position() noexcept = default;

		Position &operator=(Position&&) noexcept;

	public:
		double_t m_x;
		double_t m_y;
};

#endif // PONG_POSITION_H
