#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

/** display_profile_t represents the DISPLAY_PROFILE_X_Y type. **/
using display_profile_t = char;

/** Display profile to represent a width of 640px and a height of 480px**/
inline constexpr display_profile_t DISPLAY_PROFILE_640_480     = 1;

/** Display profile to represent a width of 1280px and a height of 720px**/
inline constexpr display_profile_t DISPLAY_PROFILE_1280_720    = 2;

/** Display profile to represent a width of 1920px and a height of 1080px**/
inline constexpr display_profile_t DISPLAY_PROFILE_1920_1080   = 3;

/** Display profile to represent a width of 2560px and a height of 1440px**/
inline constexpr display_profile_t DISPLAY_PROFILE_2560_1440   = 4;

/** Display profile to represent a width of 2048px and a height of 1080px**/
inline constexpr display_profile_t DISPLAY_PROFILE_2048_1080   = 5;

/** Display profile to represent a width of 3840px and a height of 2160px**/
inline constexpr display_profile_t DISPLAY_PROFILE_3840_2160   = 6;

/** Display profile to represent a width of 7680px and a height of 4320px**/
inline constexpr display_profile_t DISPLAY_PROFILE_7680_4320   = 7;


namespace window {
    /** Set the display profile **/
    void display_profile(display_profile_t display_profile);

    /** Set display profile to `{display_profile}` **/
    void set_size(display_profile_t display_profile);

    /** Get the aspect ratio of the currently set display profile **/
    float aspect_ratio();

    /** Get the display profile **/
    display_profile_t display_profile();

    /** Find the display profile matching `DISPLAY_PROFILE_{width}_{height})` **/
    display_profile_t find_display_profile(float width, float height);

    /** Find the {height} in DISPLAY_PROFILE_WIDTH_{height}`**/
    float find_display_profile_height(display_profile_t display_profile);

    /** Find the {width} in DISPLAY_PROFILE_{width}_HEIGHT`**/
    float find_display_profile_width(display_profile_t display_profile);

    /** Get the width of the currently set display profile **/
    float height();

    /** Set the display profile to one matching `DISPLAY_PROFILE_{width}_{height}` **/
    void set_size(float width, float height);

    /** Get the height of the currently set display profile **/
    float width();

}

#endif // CORE_WINDOW_H
