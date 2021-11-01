#include <core/window.h>

namespace window {
    float_t m_aspect_ratio = 1.0;
    float_t m_width = 0.0;
    float_t m_height = 0.0;
}

float_t window::aspect_ratio() {
    return m_aspect_ratio;
}

float_t window::width() {
    return m_width;
}

float_t window::height() {
    return m_height;
}

void window::update(float_t width, float_t height) {
    m_width = width;
    m_height = height;
    m_aspect_ratio = (float_t) width / (float_t) height;
}
