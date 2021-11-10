#include <core/components/position2d.h>

Position2D::Position2D(const double_t x, const double_t y) noexcept 
: x(x), y(y) {
}

Position2D::Position2D(Position2D &&p) noexcept {
    this->x = p.x;
    this->y = p.y;
}

Position2D &Position2D::operator=(Position2D && p) noexcept {
    if (this != &p) {
        this->x = p.x;
        this->y = p.y;
    }
    return *this;
}

