#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <cmath>

/** display profile is 4 bits **/
using display_profile_t = size_t;
inline constexpr display_profile_t DISPLAY_PROFILE_640_480     = 1;
inline constexpr display_profile_t DISPLAY_PROFILE_1280_720    = 2;
inline constexpr display_profile_t DISPLAY_PROFILE_1920_1080   = 3;
inline constexpr display_profile_t DISPLAY_PROFILE_2560_1440   = 4;
inline constexpr display_profile_t DISPLAY_PROFILE_2048_1080   = 5;
inline constexpr display_profile_t DISPLAY_PROFILE_3840_2160   = 6;
inline constexpr display_profile_t DISPLAY_PROFILE_7680_4320   = 7;


namespace window {
    float_t aspect_ratio();
    float_t width();
    float_t height();

    void display_profile(display_profile_t display_profile);
    display_profile_t display_profile();
    display_profile_t find_display_profile(size_t width, size_t height);

    void set_size(display_profile_t display_profile);
    void set_size(float_t width, float_t height);

    size_t find_display_profile_width(display_profile_t display_profile);
    size_t find_display_profile_height(display_profile_t display_profile);
}

#endif // CORE_WINDOW_H
