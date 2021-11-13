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

void window::set_size(float_t width, float_t height) {
    m_width = width;
    m_height = height;
    m_aspect_ratio = (float_t) width / (float_t) height;
}

size_t window::find_display_profile_width(display_profile_t display_profile) {
    if (display_profile == DISPLAY_PROFILE_640_480) return 640;
    if (display_profile == DISPLAY_PROFILE_1280_720) return 1280;
    if (display_profile == DISPLAY_PROFILE_1920_1080) return 1920;
    if (display_profile == DISPLAY_PROFILE_2560_1440) return 2560;
    if (display_profile == DISPLAY_PROFILE_2048_1080) return 2048;
    if (display_profile == DISPLAY_PROFILE_3840_2160) return 3840;
    if (display_profile == DISPLAY_PROFILE_7680_4320) return 7680;
    return 0;
}

size_t window::find_display_profile_height(display_profile_t display_profile) {
    if (display_profile == DISPLAY_PROFILE_640_480) return 480;
    if (display_profile == DISPLAY_PROFILE_1280_720) return 720;
    if (display_profile == DISPLAY_PROFILE_1920_1080) return 1080;
    if (display_profile == DISPLAY_PROFILE_2560_1440) return 1440;
    if (display_profile == DISPLAY_PROFILE_2048_1080) return 1080;
    if (display_profile == DISPLAY_PROFILE_3840_2160) return 2160;
    if (display_profile == DISPLAY_PROFILE_7680_4320) return 4320;
    return 0;
}
