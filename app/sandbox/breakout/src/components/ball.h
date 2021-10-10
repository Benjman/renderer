#ifndef BREAKOUT_BALL_H
#define BREAKOUT_BALL_H

#include <glm/vec3.hpp>

struct Ball final {
	double vel_x;
	double vel_y;
	double initial_x_vel;

	int bounce_immune_ticks = 0;

	Ball(const double vel_x, const double vel_y) noexcept;
	Ball(Ball&&) noexcept;
	~Ball() noexcept = default;
	Ball &operator=(Ball&&) noexcept;

};

#endif // BREAKOUT_BALL_H
