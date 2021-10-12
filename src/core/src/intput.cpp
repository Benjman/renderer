#include <core/input.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <algorithm>

void InputState::key_event(const int key, const int scancode, const int action, const int mods) {
    m_mods = mods;
    if (action == GLFW_PRESS) {
        m_keys_down[key] = true;
        m_keys_pressed[key] = true;
        m_keys_pressed[KEY_LAST + 1] = true; // last element keeps global state of if any key has been pressed
        last_key_pressed = key;
    } else if (action == GLFW_RELEASE) {
        m_keys_down[key] = false;
        m_keys_released[key] = true;
        m_keys_released[KEY_LAST + 1] = true; // last element keeps global state of if any key has been released
        last_key_released = key;
    }
}

void InputState::reset() {
    if (m_keys_pressed[KEY_LAST + 1]) {
        std::fill(m_keys_pressed, m_keys_pressed + sizeof(m_keys_pressed), false);
        last_key_pressed = KEY_UNKNOWN;
    }
    if (m_keys_released[KEY_LAST + 1]) {
        std::fill(m_keys_released, m_keys_released + sizeof(m_keys_released), false);
        last_key_released = KEY_UNKNOWN;
    }
    m_mods = 0;
}
