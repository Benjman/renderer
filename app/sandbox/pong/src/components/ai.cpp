#include "ai.h"

AI::AI(const double x, const double y) noexcept : x{x}, y{y} {
}

AI::AI(AI&& ai) noexcept {
    x = ai.x;
    y = ai.y;
}

AI& AI::operator=(AI &&ai) noexcept {
    if (this != &ai) {
        x = ai.x;
        y = ai.y;
    }

    return *this;
}
