#ifndef PONG_AI_H
#define PONG_AI_H

class AI final {
    public:
        double x;
        double y;

        AI(const double x, const double y) noexcept;
        AI(AI&&) noexcept;
        ~AI() noexcept = default;
        AI& operator=(AI&&) noexcept;

};

#endif // PONG_AI_H
