#include "ball.h"
#include "../random.hpp"

Ball::Ball(const double vel_x, const double vel_y) noexcept : initial_vel_x(vel_x), initial_vel_y(vel_y), bounce_immune_ticks {0}, vel_x(vel_x), vel_y(vel_y) {
    switch (random(0, 3)) {
        case 0:
            this->vel_x = initial_vel_x;
            break;

        case 1:
            this->vel_x = -initial_vel_x;
            break;

        case 2:
            this->vel_y = initial_vel_y;
            break;

        case 3:
            this->vel_y = -initial_vel_y;
            break;
    }
}

Ball::Ball(Ball&& b) noexcept {
    this->bounce_immune_ticks = b.bounce_immune_ticks;
    this->initial_vel_x = b.initial_vel_x;
    this->initial_vel_y = b.initial_vel_y;
    this->vel_x = b.vel_x;
    this->vel_y = b.vel_y;
}

Ball& Ball::operator=(Ball && b) noexcept {
    if (this != &b) {
        this->bounce_immune_ticks = b.bounce_immune_ticks;
        this->initial_vel_x = b.initial_vel_x;
        this->initial_vel_y = b.initial_vel_y;
        this->vel_x = b.vel_x;
        this->vel_y = b.vel_y;
    }

    return *this;
}

const double Ball::initial_x_vel() const noexcept {
    return initial_vel_x;
}

const double Ball::initial_y_vel() const noexcept {
    return initial_vel_y;
}
