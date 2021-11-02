#include <gtest/gtest.h>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define private public
#include <core/input.h>

using namespace input;

struct InputTestFixture : public ::testing::Test {
	protected:
        void SetUp() {
            input::mouse_move_event(0, 0);
            input::reset();
        }
};

TEST_F(InputTestFixture, initial_state) {
    // initial states
    for (int i = 0; i <= KEY_LAST; i++) {
        ASSERT_FALSE(key_down(i));
        ASSERT_FALSE(key_pressed(i));
        ASSERT_FALSE(key_released(i));
    }

    ASSERT_FALSE(key_pressed(KEY_LAST + 1));
    ASSERT_FALSE(key_released(KEY_LAST + 1));
    ASSERT_EQ(0, mods());
}

TEST_F(InputTestFixture, glfw_mirroring) {
	ASSERT_EQ(KEY_UNKNOWN, GLFW_KEY_UNKNOWN);
	ASSERT_EQ(KEY_SPACE, GLFW_KEY_SPACE);
	ASSERT_EQ(KEY_APOSTROPHE, GLFW_KEY_APOSTROPHE);
	ASSERT_EQ(KEY_COMMA, GLFW_KEY_COMMA);
	ASSERT_EQ(KEY_MINUS, GLFW_KEY_MINUS);
	ASSERT_EQ(KEY_PERIOD, GLFW_KEY_PERIOD);
	ASSERT_EQ(KEY_SLASH, GLFW_KEY_SLASH);
	ASSERT_EQ(KEY_0, GLFW_KEY_0);
	ASSERT_EQ(KEY_1, GLFW_KEY_1);
	ASSERT_EQ(KEY_2, GLFW_KEY_2);
	ASSERT_EQ(KEY_3, GLFW_KEY_3);
	ASSERT_EQ(KEY_4, GLFW_KEY_4);
	ASSERT_EQ(KEY_5, GLFW_KEY_5);
	ASSERT_EQ(KEY_6, GLFW_KEY_6);
	ASSERT_EQ(KEY_7, GLFW_KEY_7);
	ASSERT_EQ(KEY_8, GLFW_KEY_8);
	ASSERT_EQ(KEY_9, GLFW_KEY_9);
	ASSERT_EQ(KEY_SEMICOLON, GLFW_KEY_SEMICOLON);
	ASSERT_EQ(KEY_EQUAL, GLFW_KEY_EQUAL);
	ASSERT_EQ(KEY_A, GLFW_KEY_A);
	ASSERT_EQ(KEY_B, GLFW_KEY_B);
	ASSERT_EQ(KEY_C, GLFW_KEY_C);
	ASSERT_EQ(KEY_D, GLFW_KEY_D);
	ASSERT_EQ(KEY_E, GLFW_KEY_E);
	ASSERT_EQ(KEY_F, GLFW_KEY_F);
	ASSERT_EQ(KEY_G, GLFW_KEY_G);
	ASSERT_EQ(KEY_H, GLFW_KEY_H);
	ASSERT_EQ(KEY_I, GLFW_KEY_I);
	ASSERT_EQ(KEY_J, GLFW_KEY_J);
	ASSERT_EQ(KEY_K, GLFW_KEY_K);
	ASSERT_EQ(KEY_L, GLFW_KEY_L);
	ASSERT_EQ(KEY_M, GLFW_KEY_M);
	ASSERT_EQ(KEY_N, GLFW_KEY_N);
	ASSERT_EQ(KEY_O, GLFW_KEY_O);
	ASSERT_EQ(KEY_P, GLFW_KEY_P);
	ASSERT_EQ(KEY_Q, GLFW_KEY_Q);
	ASSERT_EQ(KEY_R, GLFW_KEY_R);
	ASSERT_EQ(KEY_S, GLFW_KEY_S);
	ASSERT_EQ(KEY_T, GLFW_KEY_T);
	ASSERT_EQ(KEY_U, GLFW_KEY_U);
	ASSERT_EQ(KEY_V, GLFW_KEY_V);
	ASSERT_EQ(KEY_W, GLFW_KEY_W);
	ASSERT_EQ(KEY_X, GLFW_KEY_X);
	ASSERT_EQ(KEY_Y, GLFW_KEY_Y);
	ASSERT_EQ(KEY_Z, GLFW_KEY_Z);
	ASSERT_EQ(KEY_LEFT_BRACKET, GLFW_KEY_LEFT_BRACKET);
	ASSERT_EQ(KEY_BACKSLASH, GLFW_KEY_BACKSLASH);
	ASSERT_EQ(KEY_RIGHT_BRACKET, GLFW_KEY_RIGHT_BRACKET);
	ASSERT_EQ(KEY_GRAVE_ACCENT, GLFW_KEY_GRAVE_ACCENT);
	ASSERT_EQ(KEY_WORLD_1, GLFW_KEY_WORLD_1);
	ASSERT_EQ(KEY_WORLD_2, GLFW_KEY_WORLD_2);
	ASSERT_EQ(KEY_ESCAPE, GLFW_KEY_ESCAPE);
	ASSERT_EQ(KEY_ENTER, GLFW_KEY_ENTER);
	ASSERT_EQ(KEY_TAB, GLFW_KEY_TAB);
	ASSERT_EQ(KEY_BACKSPACE, GLFW_KEY_BACKSPACE);
	ASSERT_EQ(KEY_INSERT, GLFW_KEY_INSERT);
	ASSERT_EQ(KEY_DELETE, GLFW_KEY_DELETE);
	ASSERT_EQ(KEY_RIGHT, GLFW_KEY_RIGHT);
	ASSERT_EQ(KEY_LEFT, GLFW_KEY_LEFT);
	ASSERT_EQ(KEY_DOWN, GLFW_KEY_DOWN);
	ASSERT_EQ(KEY_UP, GLFW_KEY_UP);
	ASSERT_EQ(KEY_PAGE_UP, GLFW_KEY_PAGE_UP);
	ASSERT_EQ(KEY_PAGE_DOWN, GLFW_KEY_PAGE_DOWN);
	ASSERT_EQ(KEY_HOME, GLFW_KEY_HOME);
	ASSERT_EQ(KEY_END, GLFW_KEY_END);
	ASSERT_EQ(KEY_CAPS_LOCK, GLFW_KEY_CAPS_LOCK);
	ASSERT_EQ(KEY_SCROLL_LOCK, GLFW_KEY_SCROLL_LOCK);
	ASSERT_EQ(KEY_NUM_LOCK, GLFW_KEY_NUM_LOCK);
	ASSERT_EQ(KEY_PRINT_SCREEN, GLFW_KEY_PRINT_SCREEN);
	ASSERT_EQ(KEY_PAUSE, GLFW_KEY_PAUSE);
	ASSERT_EQ(KEY_F1, GLFW_KEY_F1);
	ASSERT_EQ(KEY_F2, GLFW_KEY_F2);
	ASSERT_EQ(KEY_F3, GLFW_KEY_F3);
	ASSERT_EQ(KEY_F4, GLFW_KEY_F4);
	ASSERT_EQ(KEY_F5, GLFW_KEY_F5);
	ASSERT_EQ(KEY_F6, GLFW_KEY_F6);
	ASSERT_EQ(KEY_F7, GLFW_KEY_F7);
	ASSERT_EQ(KEY_F8, GLFW_KEY_F8);
	ASSERT_EQ(KEY_F9, GLFW_KEY_F9);
	ASSERT_EQ(KEY_F10, GLFW_KEY_F10);
	ASSERT_EQ(KEY_F11, GLFW_KEY_F11);
	ASSERT_EQ(KEY_F12, GLFW_KEY_F12);
	ASSERT_EQ(KEY_F13, GLFW_KEY_F13);
	ASSERT_EQ(KEY_F14, GLFW_KEY_F14);
	ASSERT_EQ(KEY_F15, GLFW_KEY_F15);
	ASSERT_EQ(KEY_F16, GLFW_KEY_F16);
	ASSERT_EQ(KEY_F17, GLFW_KEY_F17);
	ASSERT_EQ(KEY_F18, GLFW_KEY_F18);
	ASSERT_EQ(KEY_F19, GLFW_KEY_F19);
	ASSERT_EQ(KEY_F20, GLFW_KEY_F20);
	ASSERT_EQ(KEY_F21, GLFW_KEY_F21);
	ASSERT_EQ(KEY_F22, GLFW_KEY_F22);
	ASSERT_EQ(KEY_F23, GLFW_KEY_F23);
	ASSERT_EQ(KEY_F24, GLFW_KEY_F24);
	ASSERT_EQ(KEY_F25, GLFW_KEY_F25);
	ASSERT_EQ(KEY_KP_0, GLFW_KEY_KP_0);
	ASSERT_EQ(KEY_KP_1, GLFW_KEY_KP_1);
	ASSERT_EQ(KEY_KP_2, GLFW_KEY_KP_2);
	ASSERT_EQ(KEY_KP_3, GLFW_KEY_KP_3);
	ASSERT_EQ(KEY_KP_4, GLFW_KEY_KP_4);
	ASSERT_EQ(KEY_KP_5, GLFW_KEY_KP_5);
	ASSERT_EQ(KEY_KP_6, GLFW_KEY_KP_6);
	ASSERT_EQ(KEY_KP_7, GLFW_KEY_KP_7);
	ASSERT_EQ(KEY_KP_8, GLFW_KEY_KP_8);
	ASSERT_EQ(KEY_KP_9, GLFW_KEY_KP_9);
	ASSERT_EQ(KEY_KP_DECIMAL, GLFW_KEY_KP_DECIMAL);
	ASSERT_EQ(KEY_KP_DIVIDE, GLFW_KEY_KP_DIVIDE);
	ASSERT_EQ(KEY_KP_MULTIPLY, GLFW_KEY_KP_MULTIPLY);
	ASSERT_EQ(KEY_KP_SUBTRACT, GLFW_KEY_KP_SUBTRACT);
	ASSERT_EQ(KEY_KP_ADD, GLFW_KEY_KP_ADD);
	ASSERT_EQ(KEY_KP_ENTER, GLFW_KEY_KP_ENTER);
	ASSERT_EQ(KEY_KP_EQUAL, GLFW_KEY_KP_EQUAL);
	ASSERT_EQ(KEY_LEFT_SHIFT, GLFW_KEY_LEFT_SHIFT);
	ASSERT_EQ(KEY_LEFT_CONTROL, GLFW_KEY_LEFT_CONTROL);
	ASSERT_EQ(KEY_LEFT_ALT, GLFW_KEY_LEFT_ALT);
	ASSERT_EQ(KEY_LEFT_SUPER, GLFW_KEY_LEFT_SUPER);
	ASSERT_EQ(KEY_RIGHT_SHIFT, GLFW_KEY_RIGHT_SHIFT);
	ASSERT_EQ(KEY_RIGHT_CONTROL, GLFW_KEY_RIGHT_CONTROL);
	ASSERT_EQ(KEY_RIGHT_ALT, GLFW_KEY_RIGHT_ALT);
	ASSERT_EQ(KEY_RIGHT_SUPER, GLFW_KEY_RIGHT_SUPER);
	ASSERT_EQ(KEY_MENU, GLFW_KEY_MENU);
	ASSERT_EQ(KEY_LAST, GLFW_KEY_LAST);
	ASSERT_EQ(KEY_RELEASE, GLFW_RELEASE);
	ASSERT_EQ(KEY_PRESS, GLFW_PRESS);
}

TEST_F(InputTestFixture, any_pressed_flag) {
    ASSERT_FALSE(key_pressed(KEY_LAST + 1));
    key_event(KEY_Q, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_LAST + 1));
}

TEST_F(InputTestFixture, any_released_flag) {
    ASSERT_FALSE(key_released(KEY_LAST + 1));
    key_event(KEY_Q, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_LAST + 1));
}

TEST_F(InputTestFixture, key_pressed_state) {
    ASSERT_FALSE(key_pressed(KEY_SPACE));
    key_event(KEY_SPACE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_SPACE));

    ASSERT_FALSE(key_pressed(KEY_APOSTROPHE));
    key_event(KEY_APOSTROPHE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_APOSTROPHE));

    ASSERT_FALSE(key_pressed(KEY_COMMA));
    key_event(KEY_COMMA, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_COMMA));

    ASSERT_FALSE(key_pressed(KEY_MINUS));
    key_event(KEY_MINUS, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_MINUS));

    ASSERT_FALSE(key_pressed(KEY_PERIOD));
    key_event(KEY_PERIOD, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_PERIOD));

    ASSERT_FALSE(key_pressed(KEY_SLASH));
    key_event(KEY_SLASH, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_SLASH));

    ASSERT_FALSE(key_pressed(KEY_0));
    key_event(KEY_0, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_0));

    ASSERT_FALSE(key_pressed(KEY_1));
    key_event(KEY_1, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_1));

    ASSERT_FALSE(key_pressed(KEY_2));
    key_event(KEY_2, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_2));

    ASSERT_FALSE(key_pressed(KEY_3));
    key_event(KEY_3, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_3));

    ASSERT_FALSE(key_pressed(KEY_4));
    key_event(KEY_4, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_4));

    ASSERT_FALSE(key_pressed(KEY_5));
    key_event(KEY_5, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_5));

    ASSERT_FALSE(key_pressed(KEY_6));
    key_event(KEY_6, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_6));

    ASSERT_FALSE(key_pressed(KEY_7));
    key_event(KEY_7, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_7));

    ASSERT_FALSE(key_pressed(KEY_8));
    key_event(KEY_8, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_8));

    ASSERT_FALSE(key_pressed(KEY_9));
    key_event(KEY_9, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_9));

    ASSERT_FALSE(key_pressed(KEY_SEMICOLON));
    key_event(KEY_SEMICOLON, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_SEMICOLON));

    ASSERT_FALSE(key_pressed(KEY_EQUAL));
    key_event(KEY_EQUAL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_EQUAL));

    ASSERT_FALSE(key_pressed(KEY_A));
    key_event(KEY_A, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_A));

    ASSERT_FALSE(key_pressed(KEY_B));
    key_event(KEY_B, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_B));

    ASSERT_FALSE(key_pressed(KEY_C));
    key_event(KEY_C, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_C));

    ASSERT_FALSE(key_pressed(KEY_D));
    key_event(KEY_D, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_D));

    ASSERT_FALSE(key_pressed(KEY_E));
    key_event(KEY_E, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_E));

    ASSERT_FALSE(key_pressed(KEY_F));
    key_event(KEY_F, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F));

    ASSERT_FALSE(key_pressed(KEY_G));
    key_event(KEY_G, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_G));

    ASSERT_FALSE(key_pressed(KEY_H));
    key_event(KEY_H, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_H));

    ASSERT_FALSE(key_pressed(KEY_I));
    key_event(KEY_I, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_I));

    ASSERT_FALSE(key_pressed(KEY_J));
    key_event(KEY_J, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_J));

    ASSERT_FALSE(key_pressed(KEY_K));
    key_event(KEY_K, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_K));

    ASSERT_FALSE(key_pressed(KEY_L));
    key_event(KEY_L, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_L));

    ASSERT_FALSE(key_pressed(KEY_M));
    key_event(KEY_M, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_M));

    ASSERT_FALSE(key_pressed(KEY_N));
    key_event(KEY_N, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_N));

    ASSERT_FALSE(key_pressed(KEY_O));
    key_event(KEY_O, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_O));

    ASSERT_FALSE(key_pressed(KEY_P));
    key_event(KEY_P, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_P));

    ASSERT_FALSE(key_pressed(KEY_Q));
    key_event(KEY_Q, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_Q));

    ASSERT_FALSE(key_pressed(KEY_R));
    key_event(KEY_R, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_R));

    ASSERT_FALSE(key_pressed(KEY_S));
    key_event(KEY_S, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_S));

    ASSERT_FALSE(key_pressed(KEY_T));
    key_event(KEY_T, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_T));

    ASSERT_FALSE(key_pressed(KEY_U));
    key_event(KEY_U, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_U));

    ASSERT_FALSE(key_pressed(KEY_V));
    key_event(KEY_V, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_V));

    ASSERT_FALSE(key_pressed(KEY_W));
    key_event(KEY_W, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_W));

    ASSERT_FALSE(key_pressed(KEY_X));
    key_event(KEY_X, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_X));

    ASSERT_FALSE(key_pressed(KEY_Y));
    key_event(KEY_Y, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_Y));

    ASSERT_FALSE(key_pressed(KEY_Z));
    key_event(KEY_Z, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_Z));

    ASSERT_FALSE(key_pressed(KEY_LEFT_BRACKET));
    key_event(KEY_LEFT_BRACKET, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_LEFT_BRACKET));

    ASSERT_FALSE(key_pressed(KEY_BACKSLASH));
    key_event(KEY_BACKSLASH, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_BACKSLASH));

    ASSERT_FALSE(key_pressed(KEY_RIGHT_BRACKET));
    key_event(KEY_RIGHT_BRACKET, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_RIGHT_BRACKET));

    ASSERT_FALSE(key_pressed(KEY_GRAVE_ACCENT));
    key_event(KEY_GRAVE_ACCENT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_GRAVE_ACCENT));

    ASSERT_FALSE(key_pressed(KEY_WORLD_1));
    key_event(KEY_WORLD_1, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_WORLD_1));

    ASSERT_FALSE(key_pressed(KEY_WORLD_2));
    key_event(KEY_WORLD_2, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_WORLD_2));

    ASSERT_FALSE(key_pressed(KEY_ESCAPE));
    key_event(KEY_ESCAPE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_ESCAPE));

    ASSERT_FALSE(key_pressed(KEY_ENTER));
    key_event(KEY_ENTER, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_ENTER));

    ASSERT_FALSE(key_pressed(KEY_TAB));
    key_event(KEY_TAB, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_TAB));

    ASSERT_FALSE(key_pressed(KEY_BACKSPACE));
    key_event(KEY_BACKSPACE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_BACKSPACE));

    ASSERT_FALSE(key_pressed(KEY_INSERT));
    key_event(KEY_INSERT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_INSERT));

    ASSERT_FALSE(key_pressed(KEY_DELETE));
    key_event(KEY_DELETE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_DELETE));

    ASSERT_FALSE(key_pressed(KEY_RIGHT));
    key_event(KEY_RIGHT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_RIGHT));

    ASSERT_FALSE(key_pressed(KEY_LEFT));
    key_event(KEY_LEFT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_LEFT));

    ASSERT_FALSE(key_pressed(KEY_DOWN));
    key_event(KEY_DOWN, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_DOWN));

    ASSERT_FALSE(key_pressed(KEY_UP));
    key_event(KEY_UP, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_UP));

    ASSERT_FALSE(key_pressed(KEY_PAGE_UP));
    key_event(KEY_PAGE_UP, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_PAGE_UP));

    ASSERT_FALSE(key_pressed(KEY_PAGE_DOWN));
    key_event(KEY_PAGE_DOWN, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_PAGE_DOWN));

    ASSERT_FALSE(key_pressed(KEY_HOME));
    key_event(KEY_HOME, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_HOME));

    ASSERT_FALSE(key_pressed(KEY_END));
    key_event(KEY_END, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_END));

    ASSERT_FALSE(key_pressed(KEY_CAPS_LOCK));
    key_event(KEY_CAPS_LOCK, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_CAPS_LOCK));

    ASSERT_FALSE(key_pressed(KEY_SCROLL_LOCK));
    key_event(KEY_SCROLL_LOCK, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_SCROLL_LOCK));

    ASSERT_FALSE(key_pressed(KEY_NUM_LOCK));
    key_event(KEY_NUM_LOCK, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_NUM_LOCK));

    ASSERT_FALSE(key_pressed(KEY_PRINT_SCREEN));
    key_event(KEY_PRINT_SCREEN, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_PRINT_SCREEN));

    ASSERT_FALSE(key_pressed(KEY_PAUSE));
    key_event(KEY_PAUSE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_PAUSE));

    ASSERT_FALSE(key_pressed(KEY_F1));
    key_event(KEY_F1, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F1));

    ASSERT_FALSE(key_pressed(KEY_F2));
    key_event(KEY_F2, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F2));

    ASSERT_FALSE(key_pressed(KEY_F3));
    key_event(KEY_F3, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F3));

    ASSERT_FALSE(key_pressed(KEY_F4));
    key_event(KEY_F4, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F4));

    ASSERT_FALSE(key_pressed(KEY_F5));
    key_event(KEY_F5, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F5));

    ASSERT_FALSE(key_pressed(KEY_F6));
    key_event(KEY_F6, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F6));

    ASSERT_FALSE(key_pressed(KEY_F7));
    key_event(KEY_F7, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F7));

    ASSERT_FALSE(key_pressed(KEY_F8));
    key_event(KEY_F8, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F8));

    ASSERT_FALSE(key_pressed(KEY_F9));
    key_event(KEY_F9, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F9));

    ASSERT_FALSE(key_pressed(KEY_F10));
    key_event(KEY_F10, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F10));

    ASSERT_FALSE(key_pressed(KEY_F11));
    key_event(KEY_F11, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F11));

    ASSERT_FALSE(key_pressed(KEY_F12));
    key_event(KEY_F12, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F12));

    ASSERT_FALSE(key_pressed(KEY_F13));
    key_event(KEY_F13, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F13));

    ASSERT_FALSE(key_pressed(KEY_F14));
    key_event(KEY_F14, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F14));

    ASSERT_FALSE(key_pressed(KEY_F15));
    key_event(KEY_F15, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F15));

    ASSERT_FALSE(key_pressed(KEY_F16));
    key_event(KEY_F16, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F16));

    ASSERT_FALSE(key_pressed(KEY_F17));
    key_event(KEY_F17, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F17));

    ASSERT_FALSE(key_pressed(KEY_F18));
    key_event(KEY_F18, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F18));

    ASSERT_FALSE(key_pressed(KEY_F19));
    key_event(KEY_F19, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F19));

    ASSERT_FALSE(key_pressed(KEY_F20));
    key_event(KEY_F20, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F20));

    ASSERT_FALSE(key_pressed(KEY_F21));
    key_event(KEY_F21, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F21));

    ASSERT_FALSE(key_pressed(KEY_F22));
    key_event(KEY_F22, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F22));

    ASSERT_FALSE(key_pressed(KEY_F23));
    key_event(KEY_F23, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F23));

    ASSERT_FALSE(key_pressed(KEY_F24));
    key_event(KEY_F24, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F24));

    ASSERT_FALSE(key_pressed(KEY_F25));
    key_event(KEY_F25, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_F25));

    ASSERT_FALSE(key_pressed(KEY_KP_0));
    key_event(KEY_KP_0, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_0));

    ASSERT_FALSE(key_pressed(KEY_KP_1));
    key_event(KEY_KP_1, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_1));

    ASSERT_FALSE(key_pressed(KEY_KP_2));
    key_event(KEY_KP_2, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_2));

    ASSERT_FALSE(key_pressed(KEY_KP_3));
    key_event(KEY_KP_3, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_3));

    ASSERT_FALSE(key_pressed(KEY_KP_4));
    key_event(KEY_KP_4, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_4));

    ASSERT_FALSE(key_pressed(KEY_KP_5));
    key_event(KEY_KP_5, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_5));

    ASSERT_FALSE(key_pressed(KEY_KP_6));
    key_event(KEY_KP_6, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_6));

    ASSERT_FALSE(key_pressed(KEY_KP_7));
    key_event(KEY_KP_7, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_7));

    ASSERT_FALSE(key_pressed(KEY_KP_8));
    key_event(KEY_KP_8, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_8));

    ASSERT_FALSE(key_pressed(KEY_KP_9));
    key_event(KEY_KP_9, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_9));

    ASSERT_FALSE(key_pressed(KEY_KP_DECIMAL));
    key_event(KEY_KP_DECIMAL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_DECIMAL));

    ASSERT_FALSE(key_pressed(KEY_KP_DIVIDE));
    key_event(KEY_KP_DIVIDE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_DIVIDE));

    ASSERT_FALSE(key_pressed(KEY_KP_MULTIPLY));
    key_event(KEY_KP_MULTIPLY, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_MULTIPLY));

    ASSERT_FALSE(key_pressed(KEY_KP_SUBTRACT));
    key_event(KEY_KP_SUBTRACT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_SUBTRACT));

    ASSERT_FALSE(key_pressed(KEY_KP_ADD));
    key_event(KEY_KP_ADD, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_ADD));

    ASSERT_FALSE(key_pressed(KEY_KP_ENTER));
    key_event(KEY_KP_ENTER, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_ENTER));

    ASSERT_FALSE(key_pressed(KEY_KP_EQUAL));
    key_event(KEY_KP_EQUAL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_KP_EQUAL));

    ASSERT_FALSE(key_pressed(KEY_LEFT_SHIFT));
    key_event(KEY_LEFT_SHIFT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_LEFT_SHIFT));

    ASSERT_FALSE(key_pressed(KEY_LEFT_CONTROL));
    key_event(KEY_LEFT_CONTROL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_LEFT_CONTROL));

    ASSERT_FALSE(key_pressed(KEY_LEFT_ALT));
    key_event(KEY_LEFT_ALT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_LEFT_ALT));

    ASSERT_FALSE(key_pressed(KEY_LEFT_SUPER));
    key_event(KEY_LEFT_SUPER, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_LEFT_SUPER));

    ASSERT_FALSE(key_pressed(KEY_RIGHT_SHIFT));
    key_event(KEY_RIGHT_SHIFT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_RIGHT_SHIFT));

    ASSERT_FALSE(key_pressed(KEY_RIGHT_CONTROL));
    key_event(KEY_RIGHT_CONTROL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_RIGHT_CONTROL));

    ASSERT_FALSE(key_pressed(KEY_RIGHT_ALT));
    key_event(KEY_RIGHT_ALT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_RIGHT_ALT));

    ASSERT_FALSE(key_pressed(KEY_RIGHT_SUPER));
    key_event(KEY_RIGHT_SUPER, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_RIGHT_SUPER));

    ASSERT_FALSE(key_pressed(KEY_MENU));
    key_event(KEY_MENU, 0, KEY_PRESS, 0);
    ASSERT_TRUE(key_pressed(KEY_MENU));
}


TEST_F(InputTestFixture, key_released_state) {
    ASSERT_FALSE(key_released(KEY_SPACE));
    key_event(KEY_SPACE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_SPACE));

    ASSERT_FALSE(key_released(KEY_APOSTROPHE));
    key_event(KEY_APOSTROPHE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_APOSTROPHE));

    ASSERT_FALSE(key_released(KEY_COMMA));
    key_event(KEY_COMMA, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_COMMA));

    ASSERT_FALSE(key_released(KEY_MINUS));
    key_event(KEY_MINUS, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_MINUS));

    ASSERT_FALSE(key_released(KEY_PERIOD));
    key_event(KEY_PERIOD, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_PERIOD));

    ASSERT_FALSE(key_released(KEY_SLASH));
    key_event(KEY_SLASH, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_SLASH));

    ASSERT_FALSE(key_released(KEY_0));
    key_event(KEY_0, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_0));

    ASSERT_FALSE(key_released(KEY_1));
    key_event(KEY_1, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_1));

    ASSERT_FALSE(key_released(KEY_2));
    key_event(KEY_2, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_2));

    ASSERT_FALSE(key_released(KEY_3));
    key_event(KEY_3, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_3));

    ASSERT_FALSE(key_released(KEY_4));
    key_event(KEY_4, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_4));

    ASSERT_FALSE(key_released(KEY_5));
    key_event(KEY_5, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_5));

    ASSERT_FALSE(key_released(KEY_6));
    key_event(KEY_6, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_6));

    ASSERT_FALSE(key_released(KEY_7));
    key_event(KEY_7, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_7));

    ASSERT_FALSE(key_released(KEY_8));
    key_event(KEY_8, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_8));

    ASSERT_FALSE(key_released(KEY_9));
    key_event(KEY_9, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_9));

    ASSERT_FALSE(key_released(KEY_SEMICOLON));
    key_event(KEY_SEMICOLON, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_SEMICOLON));

    ASSERT_FALSE(key_released(KEY_EQUAL));
    key_event(KEY_EQUAL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_EQUAL));

    ASSERT_FALSE(key_released(KEY_A));
    key_event(KEY_A, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_A));

    ASSERT_FALSE(key_released(KEY_B));
    key_event(KEY_B, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_B));

    ASSERT_FALSE(key_released(KEY_C));
    key_event(KEY_C, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_C));

    ASSERT_FALSE(key_released(KEY_D));
    key_event(KEY_D, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_D));

    ASSERT_FALSE(key_released(KEY_E));
    key_event(KEY_E, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_E));

    ASSERT_FALSE(key_released(KEY_F));
    key_event(KEY_F, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F));

    ASSERT_FALSE(key_released(KEY_G));
    key_event(KEY_G, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_G));

    ASSERT_FALSE(key_released(KEY_H));
    key_event(KEY_H, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_H));

    ASSERT_FALSE(key_released(KEY_I));
    key_event(KEY_I, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_I));

    ASSERT_FALSE(key_released(KEY_J));
    key_event(KEY_J, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_J));

    ASSERT_FALSE(key_released(KEY_K));
    key_event(KEY_K, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_K));

    ASSERT_FALSE(key_released(KEY_L));
    key_event(KEY_L, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_L));

    ASSERT_FALSE(key_released(KEY_M));
    key_event(KEY_M, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_M));

    ASSERT_FALSE(key_released(KEY_N));
    key_event(KEY_N, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_N));

    ASSERT_FALSE(key_released(KEY_O));
    key_event(KEY_O, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_O));

    ASSERT_FALSE(key_released(KEY_P));
    key_event(KEY_P, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_P));

    ASSERT_FALSE(key_released(KEY_Q));
    key_event(KEY_Q, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_Q));

    ASSERT_FALSE(key_released(KEY_R));
    key_event(KEY_R, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_R));

    ASSERT_FALSE(key_released(KEY_S));
    key_event(KEY_S, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_S));

    ASSERT_FALSE(key_released(KEY_T));
    key_event(KEY_T, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_T));

    ASSERT_FALSE(key_released(KEY_U));
    key_event(KEY_U, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_U));

    ASSERT_FALSE(key_released(KEY_V));
    key_event(KEY_V, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_V));

    ASSERT_FALSE(key_released(KEY_W));
    key_event(KEY_W, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_W));

    ASSERT_FALSE(key_released(KEY_X));
    key_event(KEY_X, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_X));

    ASSERT_FALSE(key_released(KEY_Y));
    key_event(KEY_Y, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_Y));

    ASSERT_FALSE(key_released(KEY_Z));
    key_event(KEY_Z, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_Z));

    ASSERT_FALSE(key_released(KEY_LEFT_BRACKET));
    key_event(KEY_LEFT_BRACKET, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_LEFT_BRACKET));

    ASSERT_FALSE(key_released(KEY_BACKSLASH));
    key_event(KEY_BACKSLASH, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_BACKSLASH));

    ASSERT_FALSE(key_released(KEY_RIGHT_BRACKET));
    key_event(KEY_RIGHT_BRACKET, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_RIGHT_BRACKET));

    ASSERT_FALSE(key_released(KEY_GRAVE_ACCENT));
    key_event(KEY_GRAVE_ACCENT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_GRAVE_ACCENT));

    ASSERT_FALSE(key_released(KEY_WORLD_1));
    key_event(KEY_WORLD_1, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_WORLD_1));

    ASSERT_FALSE(key_released(KEY_WORLD_2));
    key_event(KEY_WORLD_2, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_WORLD_2));

    ASSERT_FALSE(key_released(KEY_ESCAPE));
    key_event(KEY_ESCAPE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_ESCAPE));

    ASSERT_FALSE(key_released(KEY_ENTER));
    key_event(KEY_ENTER, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_ENTER));

    ASSERT_FALSE(key_released(KEY_TAB));
    key_event(KEY_TAB, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_TAB));

    ASSERT_FALSE(key_released(KEY_BACKSPACE));
    key_event(KEY_BACKSPACE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_BACKSPACE));

    ASSERT_FALSE(key_released(KEY_INSERT));
    key_event(KEY_INSERT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_INSERT));

    ASSERT_FALSE(key_released(KEY_DELETE));
    key_event(KEY_DELETE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_DELETE));

    ASSERT_FALSE(key_released(KEY_RIGHT));
    key_event(KEY_RIGHT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_RIGHT));

    ASSERT_FALSE(key_released(KEY_LEFT));
    key_event(KEY_LEFT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_LEFT));

    ASSERT_FALSE(key_released(KEY_DOWN));
    key_event(KEY_DOWN, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_DOWN));

    ASSERT_FALSE(key_released(KEY_UP));
    key_event(KEY_UP, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_UP));

    ASSERT_FALSE(key_released(KEY_PAGE_UP));
    key_event(KEY_PAGE_UP, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_PAGE_UP));

    ASSERT_FALSE(key_released(KEY_PAGE_DOWN));
    key_event(KEY_PAGE_DOWN, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_PAGE_DOWN));

    ASSERT_FALSE(key_released(KEY_HOME));
    key_event(KEY_HOME, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_HOME));

    ASSERT_FALSE(key_released(KEY_END));
    key_event(KEY_END, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_END));

    ASSERT_FALSE(key_released(KEY_CAPS_LOCK));
    key_event(KEY_CAPS_LOCK, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_CAPS_LOCK));

    ASSERT_FALSE(key_released(KEY_SCROLL_LOCK));
    key_event(KEY_SCROLL_LOCK, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_SCROLL_LOCK));

    ASSERT_FALSE(key_released(KEY_NUM_LOCK));
    key_event(KEY_NUM_LOCK, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_NUM_LOCK));

    ASSERT_FALSE(key_released(KEY_PRINT_SCREEN));
    key_event(KEY_PRINT_SCREEN, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_PRINT_SCREEN));

    ASSERT_FALSE(key_released(KEY_PAUSE));
    key_event(KEY_PAUSE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_PAUSE));

    ASSERT_FALSE(key_released(KEY_F1));
    key_event(KEY_F1, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F1));

    ASSERT_FALSE(key_released(KEY_F2));
    key_event(KEY_F2, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F2));

    ASSERT_FALSE(key_released(KEY_F3));
    key_event(KEY_F3, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F3));

    ASSERT_FALSE(key_released(KEY_F4));
    key_event(KEY_F4, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F4));

    ASSERT_FALSE(key_released(KEY_F5));
    key_event(KEY_F5, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F5));

    ASSERT_FALSE(key_released(KEY_F6));
    key_event(KEY_F6, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F6));

    ASSERT_FALSE(key_released(KEY_F7));
    key_event(KEY_F7, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F7));

    ASSERT_FALSE(key_released(KEY_F8));
    key_event(KEY_F8, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F8));

    ASSERT_FALSE(key_released(KEY_F9));
    key_event(KEY_F9, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F9));

    ASSERT_FALSE(key_released(KEY_F10));
    key_event(KEY_F10, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F10));

    ASSERT_FALSE(key_released(KEY_F11));
    key_event(KEY_F11, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F11));

    ASSERT_FALSE(key_released(KEY_F12));
    key_event(KEY_F12, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F12));

    ASSERT_FALSE(key_released(KEY_F13));
    key_event(KEY_F13, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F13));

    ASSERT_FALSE(key_released(KEY_F14));
    key_event(KEY_F14, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F14));

    ASSERT_FALSE(key_released(KEY_F15));
    key_event(KEY_F15, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F15));

    ASSERT_FALSE(key_released(KEY_F16));
    key_event(KEY_F16, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F16));

    ASSERT_FALSE(key_released(KEY_F17));
    key_event(KEY_F17, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F17));

    ASSERT_FALSE(key_released(KEY_F18));
    key_event(KEY_F18, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F18));

    ASSERT_FALSE(key_released(KEY_F19));
    key_event(KEY_F19, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F19));

    ASSERT_FALSE(key_released(KEY_F20));
    key_event(KEY_F20, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F20));

    ASSERT_FALSE(key_released(KEY_F21));
    key_event(KEY_F21, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F21));

    ASSERT_FALSE(key_released(KEY_F22));
    key_event(KEY_F22, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F22));

    ASSERT_FALSE(key_released(KEY_F23));
    key_event(KEY_F23, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F23));

    ASSERT_FALSE(key_released(KEY_F24));
    key_event(KEY_F24, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F24));

    ASSERT_FALSE(key_released(KEY_F25));
    key_event(KEY_F25, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_F25));

    ASSERT_FALSE(key_released(KEY_KP_0));
    key_event(KEY_KP_0, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_0));

    ASSERT_FALSE(key_released(KEY_KP_1));
    key_event(KEY_KP_1, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_1));

    ASSERT_FALSE(key_released(KEY_KP_2));
    key_event(KEY_KP_2, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_2));

    ASSERT_FALSE(key_released(KEY_KP_3));
    key_event(KEY_KP_3, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_3));

    ASSERT_FALSE(key_released(KEY_KP_4));
    key_event(KEY_KP_4, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_4));

    ASSERT_FALSE(key_released(KEY_KP_5));
    key_event(KEY_KP_5, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_5));

    ASSERT_FALSE(key_released(KEY_KP_6));
    key_event(KEY_KP_6, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_6));

    ASSERT_FALSE(key_released(KEY_KP_7));
    key_event(KEY_KP_7, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_7));

    ASSERT_FALSE(key_released(KEY_KP_8));
    key_event(KEY_KP_8, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_8));

    ASSERT_FALSE(key_released(KEY_KP_9));
    key_event(KEY_KP_9, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_9));

    ASSERT_FALSE(key_released(KEY_KP_DECIMAL));
    key_event(KEY_KP_DECIMAL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_DECIMAL));

    ASSERT_FALSE(key_released(KEY_KP_DIVIDE));
    key_event(KEY_KP_DIVIDE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_DIVIDE));

    ASSERT_FALSE(key_released(KEY_KP_MULTIPLY));
    key_event(KEY_KP_MULTIPLY, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_MULTIPLY));

    ASSERT_FALSE(key_released(KEY_KP_SUBTRACT));
    key_event(KEY_KP_SUBTRACT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_SUBTRACT));

    ASSERT_FALSE(key_released(KEY_KP_ADD));
    key_event(KEY_KP_ADD, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_ADD));

    ASSERT_FALSE(key_released(KEY_KP_ENTER));
    key_event(KEY_KP_ENTER, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_ENTER));

    ASSERT_FALSE(key_released(KEY_KP_EQUAL));
    key_event(KEY_KP_EQUAL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_KP_EQUAL));

    ASSERT_FALSE(key_released(KEY_LEFT_SHIFT));
    key_event(KEY_LEFT_SHIFT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_LEFT_SHIFT));

    ASSERT_FALSE(key_released(KEY_LEFT_CONTROL));
    key_event(KEY_LEFT_CONTROL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_LEFT_CONTROL));

    ASSERT_FALSE(key_released(KEY_LEFT_ALT));
    key_event(KEY_LEFT_ALT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_LEFT_ALT));

    ASSERT_FALSE(key_released(KEY_LEFT_SUPER));
    key_event(KEY_LEFT_SUPER, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_LEFT_SUPER));

    ASSERT_FALSE(key_released(KEY_RIGHT_SHIFT));
    key_event(KEY_RIGHT_SHIFT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_RIGHT_SHIFT));

    ASSERT_FALSE(key_released(KEY_RIGHT_CONTROL));
    key_event(KEY_RIGHT_CONTROL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_RIGHT_CONTROL));

    ASSERT_FALSE(key_released(KEY_RIGHT_ALT));
    key_event(KEY_RIGHT_ALT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_RIGHT_ALT));

    ASSERT_FALSE(key_released(KEY_RIGHT_SUPER));
    key_event(KEY_RIGHT_SUPER, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_RIGHT_SUPER));

    ASSERT_FALSE(key_released(KEY_MENU));
    key_event(KEY_MENU, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(key_released(KEY_MENU));
}

TEST_F(InputTestFixture, mods) {
    ASSERT_EQ(0, mods());
    key_event(KEY_Q, 0, KEY_PRESS, 13);
    ASSERT_EQ(13, mods());
}

TEST_F(InputTestFixture, mouse_buttons) {
    ASSERT_EQ(GLFW_MOUSE_BUTTON_1, MOUSE_BUTTON_1);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_2, MOUSE_BUTTON_2);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_3, MOUSE_BUTTON_3);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_4, MOUSE_BUTTON_4);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_5, MOUSE_BUTTON_5);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_6, MOUSE_BUTTON_6);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_7, MOUSE_BUTTON_7);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_8, MOUSE_BUTTON_8);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_LAST, MOUSE_BUTTON_LAST);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_LEFT, MOUSE_BUTTON_LEFT);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_RIGHT, MOUSE_BUTTON_RIGHT);
    ASSERT_EQ(GLFW_MOUSE_BUTTON_MIDDLE, MOUSE_BUTTON_MIDDLE);
}

TEST_F(InputTestFixture, mouse_initial_state) {
    ASSERT_EQ(0, input::mouse_x());
    ASSERT_EQ(0, input::mouse_y());
    ASSERT_EQ(0, input::mouse_dx());
    ASSERT_EQ(0, input::mouse_dy());
}

TEST_F(InputTestFixture, mouse_event) {
    ASSERT_EQ(0, input::mouse_x());
    ASSERT_EQ(0, input::mouse_y());

    input::mouse_move_event(13, 21);
    ASSERT_EQ(13, input::mouse_x());
    ASSERT_EQ(21, input::mouse_y());
}

TEST_F(InputTestFixture, mouse_delta) {
    ASSERT_EQ(0, input::mouse_dx());
    ASSERT_EQ(0, input::mouse_dy());

    input::mouse_move_event(17, 27);
    ASSERT_EQ(17, input::mouse_dx());
    ASSERT_EQ(27, input::mouse_dy());

    input::mouse_move_event(12, 20);
    ASSERT_EQ(-5, input::mouse_dx());
    ASSERT_EQ(-7, input::mouse_dy());

    input::mouse_move_event(32, 13);
    ASSERT_EQ(20, input::mouse_dx());
    ASSERT_EQ(-7, input::mouse_dy());
}
