#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <cmath>
namespace window {
    float_t aspect_ratio();
    float_t width();
    float_t height();

    void update(float_t width, float_t height);
}

#endif // CORE_WINDOW_H
