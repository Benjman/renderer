#ifndef CORE_INPUT_H
#define CORE_INPUT_H

#include <cmath>
#include <cstdint>

namespace input {
    bool key_down(uint16_t key, uint16_t mods = 0);
    bool key_up(uint16_t key, uint16_t mods = 0);

    bool key_pressed(uint16_t key);
    bool key_released(uint16_t key);

    bool any_key_pressed();
    bool any_key_released();

    void key_event(const uint16_t key, const uint16_t scancode, const uint16_t action, const uint16_t mods);
    void reset();

    uint16_t last_key_pressed();
    uint16_t last_key_released();
    uint16_t mods();

    double_t mouse_x();
    double_t mouse_y();

    double_t mouse_dx();
    double_t mouse_dy();

    bool mouse_down(uint16_t button);
    bool mouse_up(uint16_t button);

    bool mouse_pressed(uint16_t button);
    bool mouse_released(uint16_t button);

    void mouse_move_event(double_t x, double_t y);
    void mouse_button_event(uint16_t button, uint16_t action, uint16_t mods);
}


// These values mirror glfw. Not using glfw header for increased compile times, but accuracy is provided by tests.
inline constexpr int KEY_UNKNOWN            = -1;

inline constexpr int KEY_SPACE              = 32;
inline constexpr int KEY_APOSTROPHE         = 39;  /* ' */
inline constexpr int KEY_COMMA              = 44;  /* , */
inline constexpr int KEY_MINUS              = 45;  /* - */
inline constexpr int KEY_PERIOD             = 46;  /* . */
inline constexpr int KEY_SLASH              = 47;  /* / */
inline constexpr int KEY_0                  = 48;
inline constexpr int KEY_1                  = 49;
inline constexpr int KEY_2                  = 50;
inline constexpr int KEY_3                  = 51;
inline constexpr int KEY_4                  = 52;
inline constexpr int KEY_5                  = 53;
inline constexpr int KEY_6                  = 54;
inline constexpr int KEY_7                  = 55;
inline constexpr int KEY_8                  = 56;
inline constexpr int KEY_9                  = 57;
inline constexpr int KEY_SEMICOLON          = 59;  /* ; */
inline constexpr int KEY_EQUAL              = 61;  /* = */
inline constexpr int KEY_A                  = 65;
inline constexpr int KEY_B                  = 66;
inline constexpr int KEY_C                  = 67;
inline constexpr int KEY_D                  = 68;
inline constexpr int KEY_E                  = 69;
inline constexpr int KEY_F                  = 70;
inline constexpr int KEY_G                  = 71;
inline constexpr int KEY_H                  = 72;
inline constexpr int KEY_I                  = 73;
inline constexpr int KEY_J                  = 74;
inline constexpr int KEY_K                  = 75;
inline constexpr int KEY_L                  = 76;
inline constexpr int KEY_M                  = 77;
inline constexpr int KEY_N                  = 78;
inline constexpr int KEY_O                  = 79;
inline constexpr int KEY_P                  = 80;
inline constexpr int KEY_Q                  = 81;
inline constexpr int KEY_R                  = 82;
inline constexpr int KEY_S                  = 83;
inline constexpr int KEY_T                  = 84;
inline constexpr int KEY_U                  = 85;
inline constexpr int KEY_V                  = 86;
inline constexpr int KEY_W                  = 87;
inline constexpr int KEY_X                  = 88;
inline constexpr int KEY_Y                  = 89;
inline constexpr int KEY_Z                  = 90;
inline constexpr int KEY_LEFT_BRACKET       = 91;  /* [ */
inline constexpr int KEY_BACKSLASH          = 92;  /* \ */
inline constexpr int KEY_RIGHT_BRACKET      = 93;  /* ] */
inline constexpr int KEY_GRAVE_ACCENT       = 96;  /* ` */
inline constexpr int KEY_WORLD_1            = 161; /* non-US #1 */
inline constexpr int KEY_WORLD_2            = 162; /* non-US #2 */
inline constexpr int KEY_ESCAPE             = 256;
inline constexpr int KEY_ENTER              = 257;
inline constexpr int KEY_TAB                = 258;
inline constexpr int KEY_BACKSPACE          = 259;
inline constexpr int KEY_INSERT             = 260;
inline constexpr int KEY_DELETE             = 261;
inline constexpr int KEY_RIGHT              = 262;
inline constexpr int KEY_LEFT               = 263;
inline constexpr int KEY_DOWN               = 264;
inline constexpr int KEY_UP                 = 265;
inline constexpr int KEY_PAGE_UP            = 266;
inline constexpr int KEY_PAGE_DOWN          = 267;
inline constexpr int KEY_HOME               = 268;
inline constexpr int KEY_END                = 269;
inline constexpr int KEY_CAPS_LOCK          = 280;
inline constexpr int KEY_SCROLL_LOCK        = 281;
inline constexpr int KEY_NUM_LOCK           = 282;
inline constexpr int KEY_PRINT_SCREEN       = 283;
inline constexpr int KEY_PAUSE              = 284;
inline constexpr int KEY_F1                 = 290;
inline constexpr int KEY_F2                 = 291;
inline constexpr int KEY_F3                 = 292;
inline constexpr int KEY_F4                 = 293;
inline constexpr int KEY_F5                 = 294;
inline constexpr int KEY_F6                 = 295;
inline constexpr int KEY_F7                 = 296;
inline constexpr int KEY_F8                 = 297;
inline constexpr int KEY_F9                 = 298;
inline constexpr int KEY_F10                = 299;
inline constexpr int KEY_F11                = 300;
inline constexpr int KEY_F12                = 301;
inline constexpr int KEY_F13                = 302;
inline constexpr int KEY_F14                = 303;
inline constexpr int KEY_F15                = 304;
inline constexpr int KEY_F16                = 305;
inline constexpr int KEY_F17                = 306;
inline constexpr int KEY_F18                = 307;
inline constexpr int KEY_F19                = 308;
inline constexpr int KEY_F20                = 309;
inline constexpr int KEY_F21                = 310;
inline constexpr int KEY_F22                = 311;
inline constexpr int KEY_F23                = 312;
inline constexpr int KEY_F24                = 313;
inline constexpr int KEY_F25                = 314;
inline constexpr int KEY_KP_0               = 320;
inline constexpr int KEY_KP_1               = 321;
inline constexpr int KEY_KP_2               = 322;
inline constexpr int KEY_KP_3               = 323;
inline constexpr int KEY_KP_4               = 324;
inline constexpr int KEY_KP_5               = 325;
inline constexpr int KEY_KP_6               = 326;
inline constexpr int KEY_KP_7               = 327;
inline constexpr int KEY_KP_8               = 328;
inline constexpr int KEY_KP_9               = 329;
inline constexpr int KEY_KP_DECIMAL         = 330;
inline constexpr int KEY_KP_DIVIDE          = 331;
inline constexpr int KEY_KP_MULTIPLY        = 332;
inline constexpr int KEY_KP_SUBTRACT        = 333;
inline constexpr int KEY_KP_ADD             = 334;
inline constexpr int KEY_KP_ENTER           = 335;
inline constexpr int KEY_KP_EQUAL           = 336;
inline constexpr int KEY_LEFT_SHIFT         = 340;
inline constexpr int KEY_LEFT_CONTROL       = 341;
inline constexpr int KEY_LEFT_ALT           = 342;
inline constexpr int KEY_LEFT_SUPER         = 343;
inline constexpr int KEY_RIGHT_SHIFT        = 344;
inline constexpr int KEY_RIGHT_CONTROL      = 345;
inline constexpr int KEY_RIGHT_ALT          = 346;
inline constexpr int KEY_RIGHT_SUPER        = 347;
inline constexpr int KEY_MENU               = 348;
inline constexpr int KEY_LAST               = KEY_MENU;

inline constexpr int KEY_RELEASE            = 0;
inline constexpr int KEY_PRESS              = 1;

inline constexpr int MOUSE_BUTTON_1         = 0;
inline constexpr int MOUSE_BUTTON_2         = 1;
inline constexpr int MOUSE_BUTTON_3         = 2;
inline constexpr int MOUSE_BUTTON_4         = 3;
inline constexpr int MOUSE_BUTTON_5         = 4;
inline constexpr int MOUSE_BUTTON_6         = 5;
inline constexpr int MOUSE_BUTTON_7         = 6;
inline constexpr int MOUSE_BUTTON_8         = 7;
inline constexpr int MOUSE_BUTTON_LAST      = MOUSE_BUTTON_8;
inline constexpr int MOUSE_BUTTON_LEFT      = MOUSE_BUTTON_1;
inline constexpr int MOUSE_BUTTON_RIGHT     = MOUSE_BUTTON_2;
inline constexpr int MOUSE_BUTTON_MIDDLE    = MOUSE_BUTTON_3;

#endif // CORE_INPUT_H
