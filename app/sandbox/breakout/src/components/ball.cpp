#include "ball.h"

Ball::Ball(const double vel_x, const double vel_y) noexcept : vel_x(vel_x), vel_y(vel_y), initial_x_vel(vel_x) {
}

Ball::Ball(Ball&& b) noexcept {
    this->vel_x = b.vel_x;
    this->vel_y = b.vel_y;
    this->initial_x_vel = b.initial_x_vel;
    this->bounce_immune_ticks = b.bounce_immune_ticks;
}

Ball &Ball::operator=(Ball&& b) noexcept {
    if (this != &b) {
        this->vel_x = b.vel_x;
        this->vel_y = b.vel_y;
        this->initial_x_vel = b.initial_x_vel;
        this->bounce_immune_ticks = b.bounce_immune_ticks;
    }

    return *this;
}

