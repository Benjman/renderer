#include <core/window.h>

namespace window {
    float m_aspect_ratio = 1.0;
    float m_width = 1.0;
    float m_height = 1.0;
    display_profile_t m_display_profile;
}

float window::aspect_ratio() {
    return m_aspect_ratio;
}

float window::width() {
    return m_width;
}

float window::height() {
    return m_height;
}

void window::set_size(float width, float height) {
    m_width = width;
    m_height = height;
    m_aspect_ratio = (float) width / (float) height;
}

float window::find_display_profile_width(display_profile_t display_profile) {
    if (display_profile == DISPLAY_PROFILE_640_480)
        return 640;
    if (display_profile == DISPLAY_PROFILE_1280_720)
        return 1280;
    if (display_profile == DISPLAY_PROFILE_1920_1080)
        return 1920;
    if (display_profile == DISPLAY_PROFILE_2560_1440)
        return 2560;
    if (display_profile == DISPLAY_PROFILE_2048_1080)
        return 2048;
    if (display_profile == DISPLAY_PROFILE_3840_2160)
        return 3840;
    if (display_profile == DISPLAY_PROFILE_7680_4320)
        return 7680;
    return 0;
}

float window::find_display_profile_height(display_profile_t display_profile) {
    if (display_profile == DISPLAY_PROFILE_640_480)
        return 480;
    if (display_profile == DISPLAY_PROFILE_1280_720)
        return 720;
    if (display_profile == DISPLAY_PROFILE_1920_1080)
        return 1080;
    if (display_profile == DISPLAY_PROFILE_2560_1440)
        return 1440;
    if (display_profile == DISPLAY_PROFILE_2048_1080)
        return 1080;
    if (display_profile == DISPLAY_PROFILE_3840_2160)
        return 2160;
    if (display_profile == DISPLAY_PROFILE_7680_4320)
        return 4320;
    return 0;
}

display_profile_t window::find_display_profile(float width, float height) {
    if (width == 640 && height == 480)
        return DISPLAY_PROFILE_640_480;
    if (width == 1280 && height == 720)
        return DISPLAY_PROFILE_1280_720;
    if (width == 1920 && height == 1080)
        return DISPLAY_PROFILE_1920_1080;
    if (width == 2560 && height == 1440)
        return DISPLAY_PROFILE_2560_1440;
    if (width == 2048 && height == 1080)
        return DISPLAY_PROFILE_2048_1080;
    if (width == 3840 && height == 2160)
        return DISPLAY_PROFILE_3840_2160;
    if (width == 7680 && height == 4320)
        return DISPLAY_PROFILE_7680_4320;
    return 0;
}

display_profile_t window::display_profile() {
    return m_display_profile;
}

void window::display_profile(display_profile_t display_profile) {
    m_display_profile = display_profile;
    set_size(find_display_profile_width(display_profile), find_display_profile_height(display_profile));
}
