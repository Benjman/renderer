#include <core/input.h>

#include <algorithm> // std::fill
#include <iostream>

#include <spdlog/spdlog.h>

#include <glm/vec2.hpp>

namespace input {
    uint16_t m_mods = 0;
    uint16_t m_last_key_pressed = KEY_UNKNOWN;
    uint16_t m_last_key_released = KEY_UNKNOWN;

    bool m_keys_down[KEY_LAST + 1]{false};
    bool m_keys_pressed[KEY_LAST + 2]{false}; // +2 because last element keeps the state for if any key was pressed
    bool m_keys_released[KEY_LAST + 2]{false}; // +2 because last element keeps the state for if any key was released

    glm::vec2 m_mouse_pos(0);
    glm::vec2 m_mouse_delta(0);

    bool m_mouse_buttons_down[MOUSE_BUTTON_LAST + 1]{false};
    bool m_mouse_buttons_pressed[MOUSE_BUTTON_LAST + 2]{false};
    bool m_mouse_buttons_released[MOUSE_BUTTON_LAST + 2]{false};
}

bool input::key_down(uint16_t key, uint16_t mods) {
    return m_keys_down[key];
}

bool input::key_up(uint16_t key, uint16_t mods) {
    return key_down(key) == false;
}

bool input::key_pressed(uint16_t key) {
    return m_keys_pressed[key];
}

bool input::key_released(uint16_t key) {
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
        spdlog::trace("keys_pressed reset");
    }
    if (m_keys_released[KEY_LAST + 1]) {
        std::fill(m_keys_released, m_keys_released + sizeof(m_keys_released), false);
        spdlog::trace("keys_released reset");
    }

    m_mouse_delta = glm::vec2(0);
    if (m_mouse_buttons_pressed[MOUSE_BUTTON_LAST + 1]) {
        std::fill(m_mouse_buttons_pressed, m_mouse_buttons_pressed + sizeof(m_mouse_buttons_pressed), false);
        spdlog::trace("mouse_buttons_pressed reset");
    }
    if (m_mouse_buttons_released[MOUSE_BUTTON_LAST + 1]) {
        std::fill(m_mouse_buttons_released, m_mouse_buttons_released + sizeof(m_mouse_buttons_released), false);
        spdlog::trace("mouse_buttons_released reset");
    }
}

void input::key_event(const uint16_t key, const uint16_t scancode, const uint16_t action, const uint16_t mods) {
    spdlog::debug("KEY EVENT - key({0})\taction({1})", scancode, action);
    m_mods = mods;
    if (action == KEY_PRESS) {
        m_keys_down[key] = true;
        m_keys_pressed[key] = true;
        m_keys_pressed[KEY_LAST + 1] = true; // last element keeps global state of if any key has been pressed
    } else if (action == KEY_RELEASE) {
        m_keys_down[key] = false;
        m_keys_released[key] = true;
        m_keys_released[KEY_LAST + 1] = true; // last element keeps global state of if any key has been released
    }
}

uint16_t input::last_key_pressed() {
    return m_last_key_pressed;
}

uint16_t input::last_key_released() {
    return m_last_key_released;
}

uint16_t input::mods() {
    return m_mods;
}

void input::mouse_move_event(double_t x, double_t y) {
    m_mouse_delta = glm::vec2(x - m_mouse_pos.x, y - m_mouse_pos.y);
    m_mouse_pos = glm::vec2(x, y);
    spdlog::trace("MOUSE MOVE - pos({0:f} {1:f})\tdelta({2:f} {3:f})", m_mouse_pos.x, m_mouse_pos.y, m_mouse_delta.x, m_mouse_delta.y);
}

double_t input::mouse_x() {
    return m_mouse_pos.x;
}

double_t input::mouse_y() {
    return m_mouse_pos.y;
}

double_t input::mouse_dx() {
    return m_mouse_delta.x;
}

double_t input::mouse_dy() {
    return m_mouse_delta.y;
}

void input::mouse_button_event(uint16_t button, uint16_t action, uint16_t mods) {
    spdlog::debug("MOUSE BUTTON - button({0})\taction({1})\tmods({2})", button, action, mods);
    if (action == KEY_PRESS) {
        m_mouse_buttons_down[button] = true;
        m_mouse_buttons_pressed[button] = true;
        m_mouse_buttons_pressed[MOUSE_BUTTON_LAST + 1] = true; // last element keeps global state of if any button has been pressed
    } else if (action == KEY_RELEASE) {
        m_mouse_buttons_down[button] = false;
        m_mouse_buttons_released[button] = true;
        m_mouse_buttons_released[MOUSE_BUTTON_LAST + 1] = true; // last element keeps global state of if any button has been released
    }
}

bool input::mouse_down(uint16_t button) {
    return m_mouse_buttons_down[button];
}

bool input::mouse_up(uint16_t button) {
    return mouse_down(button) == false;
}

bool input::mouse_pressed(uint16_t button) {
    return m_mouse_buttons_pressed[button];
}

bool input::mouse_released(uint16_t button) {
    return m_mouse_buttons_released[button];
}
