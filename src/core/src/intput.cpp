#include <core/input.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <algorithm> // std::fill

namespace input {
    int m_mods = 0;
    int m_last_key_pressed = KEY_UNKNOWN;
    int m_last_key_released = KEY_UNKNOWN;

    bool m_keys_down[KEY_LAST + 1]{false};
    bool m_keys_pressed[KEY_LAST + 2]{false}; // +2 because last element keeps the state for if any key was pressed
    bool m_keys_released[KEY_LAST + 2]{false}; // +2 because last element keeps the state for if any key was released
}

bool input::key_down(int key, int mods) {
    return m_keys_released[KEY_LAST + 1];
}

bool input::key_up(int key, int mods) {
    return key_down(key) == false;
}

bool input::key_pressed(int key) {
    return m_keys_pressed[key];
}

bool input::key_released(int key) {
    return m_keys_released[key];
}

bool input::any_key_pressed() {
    return m_keys_pressed[KEY_LAST + 1];
}

bool input::any_key_released() {
	return false;
}

void input::reset() {
    if (m_keys_pressed[KEY_LAST + 1]) {
        std::fill(m_keys_pressed, m_keys_pressed + sizeof(m_keys_pressed), false);
    }
    if (m_keys_released[KEY_LAST + 1]) {
        std::fill(m_keys_released, m_keys_released + sizeof(m_keys_released), false);
    }
}

void input::key_event(const int key, const int scancode, const int action, const int mods) {
    m_mods = mods;
    if (action == GLFW_PRESS) {
        m_keys_down[key] = true;
        m_keys_pressed[key] = true;
        m_keys_pressed[KEY_LAST + 1] = true; // last element keeps global state of if any key has been pressed
    } else if (action == GLFW_RELEASE) {
        m_keys_down[key] = false;
        m_keys_released[key] = true;
        m_keys_released[KEY_LAST + 1] = true; // last element keeps global state of if any key has been released
    }
}

int input::last_key_pressed() {
    return m_last_key_pressed;
}

int input::last_key_released() {
    return m_last_key_released;
}

int input::mods() {
    return m_mods;
}
