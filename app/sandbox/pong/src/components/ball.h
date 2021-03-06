#ifndef PONG_BALL_H
#define PONG_BALL_H

class Ball final {
    public:
        const double initial_x_vel() const noexcept;
        const double initial_y_vel() const noexcept;

        double vel_x;
        double vel_y;
        int bounce_immune_ticks;

        Ball(const double vel_x, const double vel_y) noexcept;
        Ball(Ball&&) noexcept;
        ~Ball() noexcept = default;
        Ball &operator=(Ball&&) noexcept;

    private:
        double initial_vel_x;
        double initial_vel_y;
};

#endif // PONG_BALL_H
