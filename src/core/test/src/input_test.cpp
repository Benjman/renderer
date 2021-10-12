#include <gtest/gtest.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define private public
#include <core/input.h>

TEST(InputTest, initial_state) {
    InputState input;

    // array sizes
    ASSERT_EQ(sizeof(bool) * (KEY_LAST + 1), sizeof(input.m_keys_down));
    ASSERT_EQ(sizeof(bool) * (KEY_LAST + 2), sizeof(input.m_keys_pressed));
    ASSERT_EQ(sizeof(bool) * (KEY_LAST + 2), sizeof(input.m_keys_released));

    // initial states
    for (int i = 0; i <= KEY_LAST; i++) {
        ASSERT_FALSE(input.m_keys_down[i]);
        ASSERT_FALSE(input.m_keys_pressed[i]);
        ASSERT_FALSE(input.m_keys_released[i]);
    }

    ASSERT_FALSE(input.m_keys_pressed[KEY_LAST + 1]);
    ASSERT_FALSE(input.m_keys_released[KEY_LAST + 1]);
    ASSERT_EQ(0, input.m_mods);
}

TEST(InputTest, glfw_mirroring) {
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

TEST(InputTest, any_pressed_flag) {
    InputState state;
    ASSERT_FALSE(state.m_keys_pressed[KEY_LAST + 1]);
    state.key_event(KEY_Q, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_LAST + 1]);
}

TEST(InputTest, any_released_flag) {
    InputState state;
    ASSERT_FALSE(state.m_keys_released[KEY_LAST + 1]);
    state.key_event(KEY_Q, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_LAST + 1]);
}

TEST(InputTest, key_pressed_state) {
    InputState state;

    ASSERT_FALSE(state.m_keys_pressed[KEY_SPACE]);
    state.key_event(KEY_SPACE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_SPACE]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_APOSTROPHE]);
    state.key_event(KEY_APOSTROPHE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_APOSTROPHE]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_COMMA]);
    state.key_event(KEY_COMMA, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_COMMA]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_MINUS]);
    state.key_event(KEY_MINUS, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_MINUS]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_PERIOD]);
    state.key_event(KEY_PERIOD, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_PERIOD]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_SLASH]);
    state.key_event(KEY_SLASH, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_SLASH]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_0]);
    state.key_event(KEY_0, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_0]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_1]);
    state.key_event(KEY_1, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_1]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_2]);
    state.key_event(KEY_2, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_2]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_3]);
    state.key_event(KEY_3, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_3]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_4]);
    state.key_event(KEY_4, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_4]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_5]);
    state.key_event(KEY_5, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_5]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_6]);
    state.key_event(KEY_6, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_6]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_7]);
    state.key_event(KEY_7, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_7]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_8]);
    state.key_event(KEY_8, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_8]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_9]);
    state.key_event(KEY_9, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_9]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_SEMICOLON]);
    state.key_event(KEY_SEMICOLON, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_SEMICOLON]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_EQUAL]);
    state.key_event(KEY_EQUAL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_EQUAL]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_A]);
    state.key_event(KEY_A, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_A]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_B]);
    state.key_event(KEY_B, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_B]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_C]);
    state.key_event(KEY_C, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_C]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_D]);
    state.key_event(KEY_D, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_D]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_E]);
    state.key_event(KEY_E, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_E]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F]);
    state.key_event(KEY_F, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_G]);
    state.key_event(KEY_G, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_G]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_H]);
    state.key_event(KEY_H, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_H]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_I]);
    state.key_event(KEY_I, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_I]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_J]);
    state.key_event(KEY_J, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_J]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_K]);
    state.key_event(KEY_K, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_K]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_L]);
    state.key_event(KEY_L, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_L]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_M]);
    state.key_event(KEY_M, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_M]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_N]);
    state.key_event(KEY_N, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_N]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_O]);
    state.key_event(KEY_O, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_O]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_P]);
    state.key_event(KEY_P, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_P]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_Q]);
    state.key_event(KEY_Q, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_Q]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_R]);
    state.key_event(KEY_R, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_R]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_S]);
    state.key_event(KEY_S, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_S]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_T]);
    state.key_event(KEY_T, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_T]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_U]);
    state.key_event(KEY_U, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_U]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_V]);
    state.key_event(KEY_V, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_V]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_W]);
    state.key_event(KEY_W, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_W]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_X]);
    state.key_event(KEY_X, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_X]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_Y]);
    state.key_event(KEY_Y, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_Y]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_Z]);
    state.key_event(KEY_Z, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_Z]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_LEFT_BRACKET]);
    state.key_event(KEY_LEFT_BRACKET, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_LEFT_BRACKET]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_BACKSLASH]);
    state.key_event(KEY_BACKSLASH, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_BACKSLASH]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_RIGHT_BRACKET]);
    state.key_event(KEY_RIGHT_BRACKET, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_RIGHT_BRACKET]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_GRAVE_ACCENT]);
    state.key_event(KEY_GRAVE_ACCENT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_GRAVE_ACCENT]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_WORLD_1]);
    state.key_event(KEY_WORLD_1, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_WORLD_1]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_WORLD_2]);
    state.key_event(KEY_WORLD_2, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_WORLD_2]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_ESCAPE]);
    state.key_event(KEY_ESCAPE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_ESCAPE]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_ENTER]);
    state.key_event(KEY_ENTER, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_ENTER]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_TAB]);
    state.key_event(KEY_TAB, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_TAB]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_BACKSPACE]);
    state.key_event(KEY_BACKSPACE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_BACKSPACE]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_INSERT]);
    state.key_event(KEY_INSERT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_INSERT]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_DELETE]);
    state.key_event(KEY_DELETE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_DELETE]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_RIGHT]);
    state.key_event(KEY_RIGHT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_RIGHT]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_LEFT]);
    state.key_event(KEY_LEFT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_LEFT]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_DOWN]);
    state.key_event(KEY_DOWN, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_DOWN]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_UP]);
    state.key_event(KEY_UP, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_UP]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_PAGE_UP]);
    state.key_event(KEY_PAGE_UP, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_PAGE_UP]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_PAGE_DOWN]);
    state.key_event(KEY_PAGE_DOWN, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_PAGE_DOWN]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_HOME]);
    state.key_event(KEY_HOME, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_HOME]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_END]);
    state.key_event(KEY_END, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_END]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_CAPS_LOCK]);
    state.key_event(KEY_CAPS_LOCK, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_CAPS_LOCK]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_SCROLL_LOCK]);
    state.key_event(KEY_SCROLL_LOCK, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_SCROLL_LOCK]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_NUM_LOCK]);
    state.key_event(KEY_NUM_LOCK, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_NUM_LOCK]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_PRINT_SCREEN]);
    state.key_event(KEY_PRINT_SCREEN, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_PRINT_SCREEN]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_PAUSE]);
    state.key_event(KEY_PAUSE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_PAUSE]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F1]);
    state.key_event(KEY_F1, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F1]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F2]);
    state.key_event(KEY_F2, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F2]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F3]);
    state.key_event(KEY_F3, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F3]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F4]);
    state.key_event(KEY_F4, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F4]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F5]);
    state.key_event(KEY_F5, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F5]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F6]);
    state.key_event(KEY_F6, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F6]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F7]);
    state.key_event(KEY_F7, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F7]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F8]);
    state.key_event(KEY_F8, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F8]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F9]);
    state.key_event(KEY_F9, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F9]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F10]);
    state.key_event(KEY_F10, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F10]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F11]);
    state.key_event(KEY_F11, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F11]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F12]);
    state.key_event(KEY_F12, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F12]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F13]);
    state.key_event(KEY_F13, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F13]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F14]);
    state.key_event(KEY_F14, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F14]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F15]);
    state.key_event(KEY_F15, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F15]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F16]);
    state.key_event(KEY_F16, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F16]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F17]);
    state.key_event(KEY_F17, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F17]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F18]);
    state.key_event(KEY_F18, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F18]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F19]);
    state.key_event(KEY_F19, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F19]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F20]);
    state.key_event(KEY_F20, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F20]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F21]);
    state.key_event(KEY_F21, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F21]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F22]);
    state.key_event(KEY_F22, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F22]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F23]);
    state.key_event(KEY_F23, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F23]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F24]);
    state.key_event(KEY_F24, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F24]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_F25]);
    state.key_event(KEY_F25, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_F25]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_0]);
    state.key_event(KEY_KP_0, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_0]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_1]);
    state.key_event(KEY_KP_1, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_1]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_2]);
    state.key_event(KEY_KP_2, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_2]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_3]);
    state.key_event(KEY_KP_3, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_3]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_4]);
    state.key_event(KEY_KP_4, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_4]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_5]);
    state.key_event(KEY_KP_5, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_5]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_6]);
    state.key_event(KEY_KP_6, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_6]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_7]);
    state.key_event(KEY_KP_7, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_7]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_8]);
    state.key_event(KEY_KP_8, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_8]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_9]);
    state.key_event(KEY_KP_9, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_9]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_DECIMAL]);
    state.key_event(KEY_KP_DECIMAL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_DECIMAL]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_DIVIDE]);
    state.key_event(KEY_KP_DIVIDE, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_DIVIDE]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_MULTIPLY]);
    state.key_event(KEY_KP_MULTIPLY, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_MULTIPLY]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_SUBTRACT]);
    state.key_event(KEY_KP_SUBTRACT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_SUBTRACT]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_ADD]);
    state.key_event(KEY_KP_ADD, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_ADD]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_ENTER]);
    state.key_event(KEY_KP_ENTER, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_ENTER]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_KP_EQUAL]);
    state.key_event(KEY_KP_EQUAL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_KP_EQUAL]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_LEFT_SHIFT]);
    state.key_event(KEY_LEFT_SHIFT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_LEFT_SHIFT]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_LEFT_CONTROL]);
    state.key_event(KEY_LEFT_CONTROL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_LEFT_CONTROL]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_LEFT_ALT]);
    state.key_event(KEY_LEFT_ALT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_LEFT_ALT]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_LEFT_SUPER]);
    state.key_event(KEY_LEFT_SUPER, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_LEFT_SUPER]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_RIGHT_SHIFT]);
    state.key_event(KEY_RIGHT_SHIFT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_RIGHT_SHIFT]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_RIGHT_CONTROL]);
    state.key_event(KEY_RIGHT_CONTROL, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_RIGHT_CONTROL]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_RIGHT_ALT]);
    state.key_event(KEY_RIGHT_ALT, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_RIGHT_ALT]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_RIGHT_SUPER]);
    state.key_event(KEY_RIGHT_SUPER, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_RIGHT_SUPER]);

    ASSERT_FALSE(state.m_keys_pressed[KEY_MENU]);
    state.key_event(KEY_MENU, 0, KEY_PRESS, 0);
    ASSERT_TRUE(state.m_keys_pressed[KEY_MENU]);
}


TEST(InputTest, key_released_state) {
    InputState state;

    ASSERT_FALSE(state.m_keys_released[KEY_SPACE]);
    state.key_event(KEY_SPACE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_SPACE]);

    ASSERT_FALSE(state.m_keys_released[KEY_APOSTROPHE]);
    state.key_event(KEY_APOSTROPHE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_APOSTROPHE]);

    ASSERT_FALSE(state.m_keys_released[KEY_COMMA]);
    state.key_event(KEY_COMMA, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_COMMA]);

    ASSERT_FALSE(state.m_keys_released[KEY_MINUS]);
    state.key_event(KEY_MINUS, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_MINUS]);

    ASSERT_FALSE(state.m_keys_released[KEY_PERIOD]);
    state.key_event(KEY_PERIOD, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_PERIOD]);

    ASSERT_FALSE(state.m_keys_released[KEY_SLASH]);
    state.key_event(KEY_SLASH, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_SLASH]);

    ASSERT_FALSE(state.m_keys_released[KEY_0]);
    state.key_event(KEY_0, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_0]);

    ASSERT_FALSE(state.m_keys_released[KEY_1]);
    state.key_event(KEY_1, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_1]);

    ASSERT_FALSE(state.m_keys_released[KEY_2]);
    state.key_event(KEY_2, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_2]);

    ASSERT_FALSE(state.m_keys_released[KEY_3]);
    state.key_event(KEY_3, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_3]);

    ASSERT_FALSE(state.m_keys_released[KEY_4]);
    state.key_event(KEY_4, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_4]);

    ASSERT_FALSE(state.m_keys_released[KEY_5]);
    state.key_event(KEY_5, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_5]);

    ASSERT_FALSE(state.m_keys_released[KEY_6]);
    state.key_event(KEY_6, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_6]);

    ASSERT_FALSE(state.m_keys_released[KEY_7]);
    state.key_event(KEY_7, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_7]);

    ASSERT_FALSE(state.m_keys_released[KEY_8]);
    state.key_event(KEY_8, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_8]);

    ASSERT_FALSE(state.m_keys_released[KEY_9]);
    state.key_event(KEY_9, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_9]);

    ASSERT_FALSE(state.m_keys_released[KEY_SEMICOLON]);
    state.key_event(KEY_SEMICOLON, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_SEMICOLON]);

    ASSERT_FALSE(state.m_keys_released[KEY_EQUAL]);
    state.key_event(KEY_EQUAL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_EQUAL]);

    ASSERT_FALSE(state.m_keys_released[KEY_A]);
    state.key_event(KEY_A, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_A]);

    ASSERT_FALSE(state.m_keys_released[KEY_B]);
    state.key_event(KEY_B, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_B]);

    ASSERT_FALSE(state.m_keys_released[KEY_C]);
    state.key_event(KEY_C, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_C]);

    ASSERT_FALSE(state.m_keys_released[KEY_D]);
    state.key_event(KEY_D, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_D]);

    ASSERT_FALSE(state.m_keys_released[KEY_E]);
    state.key_event(KEY_E, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_E]);

    ASSERT_FALSE(state.m_keys_released[KEY_F]);
    state.key_event(KEY_F, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F]);

    ASSERT_FALSE(state.m_keys_released[KEY_G]);
    state.key_event(KEY_G, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_G]);

    ASSERT_FALSE(state.m_keys_released[KEY_H]);
    state.key_event(KEY_H, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_H]);

    ASSERT_FALSE(state.m_keys_released[KEY_I]);
    state.key_event(KEY_I, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_I]);

    ASSERT_FALSE(state.m_keys_released[KEY_J]);
    state.key_event(KEY_J, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_J]);

    ASSERT_FALSE(state.m_keys_released[KEY_K]);
    state.key_event(KEY_K, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_K]);

    ASSERT_FALSE(state.m_keys_released[KEY_L]);
    state.key_event(KEY_L, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_L]);

    ASSERT_FALSE(state.m_keys_released[KEY_M]);
    state.key_event(KEY_M, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_M]);

    ASSERT_FALSE(state.m_keys_released[KEY_N]);
    state.key_event(KEY_N, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_N]);

    ASSERT_FALSE(state.m_keys_released[KEY_O]);
    state.key_event(KEY_O, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_O]);

    ASSERT_FALSE(state.m_keys_released[KEY_P]);
    state.key_event(KEY_P, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_P]);

    ASSERT_FALSE(state.m_keys_released[KEY_Q]);
    state.key_event(KEY_Q, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_Q]);

    ASSERT_FALSE(state.m_keys_released[KEY_R]);
    state.key_event(KEY_R, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_R]);

    ASSERT_FALSE(state.m_keys_released[KEY_S]);
    state.key_event(KEY_S, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_S]);

    ASSERT_FALSE(state.m_keys_released[KEY_T]);
    state.key_event(KEY_T, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_T]);

    ASSERT_FALSE(state.m_keys_released[KEY_U]);
    state.key_event(KEY_U, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_U]);

    ASSERT_FALSE(state.m_keys_released[KEY_V]);
    state.key_event(KEY_V, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_V]);

    ASSERT_FALSE(state.m_keys_released[KEY_W]);
    state.key_event(KEY_W, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_W]);

    ASSERT_FALSE(state.m_keys_released[KEY_X]);
    state.key_event(KEY_X, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_X]);

    ASSERT_FALSE(state.m_keys_released[KEY_Y]);
    state.key_event(KEY_Y, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_Y]);

    ASSERT_FALSE(state.m_keys_released[KEY_Z]);
    state.key_event(KEY_Z, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_Z]);

    ASSERT_FALSE(state.m_keys_released[KEY_LEFT_BRACKET]);
    state.key_event(KEY_LEFT_BRACKET, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_LEFT_BRACKET]);

    ASSERT_FALSE(state.m_keys_released[KEY_BACKSLASH]);
    state.key_event(KEY_BACKSLASH, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_BACKSLASH]);

    ASSERT_FALSE(state.m_keys_released[KEY_RIGHT_BRACKET]);
    state.key_event(KEY_RIGHT_BRACKET, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_RIGHT_BRACKET]);

    ASSERT_FALSE(state.m_keys_released[KEY_GRAVE_ACCENT]);
    state.key_event(KEY_GRAVE_ACCENT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_GRAVE_ACCENT]);

    ASSERT_FALSE(state.m_keys_released[KEY_WORLD_1]);
    state.key_event(KEY_WORLD_1, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_WORLD_1]);

    ASSERT_FALSE(state.m_keys_released[KEY_WORLD_2]);
    state.key_event(KEY_WORLD_2, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_WORLD_2]);

    ASSERT_FALSE(state.m_keys_released[KEY_ESCAPE]);
    state.key_event(KEY_ESCAPE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_ESCAPE]);

    ASSERT_FALSE(state.m_keys_released[KEY_ENTER]);
    state.key_event(KEY_ENTER, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_ENTER]);

    ASSERT_FALSE(state.m_keys_released[KEY_TAB]);
    state.key_event(KEY_TAB, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_TAB]);

    ASSERT_FALSE(state.m_keys_released[KEY_BACKSPACE]);
    state.key_event(KEY_BACKSPACE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_BACKSPACE]);

    ASSERT_FALSE(state.m_keys_released[KEY_INSERT]);
    state.key_event(KEY_INSERT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_INSERT]);

    ASSERT_FALSE(state.m_keys_released[KEY_DELETE]);
    state.key_event(KEY_DELETE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_DELETE]);

    ASSERT_FALSE(state.m_keys_released[KEY_RIGHT]);
    state.key_event(KEY_RIGHT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_RIGHT]);

    ASSERT_FALSE(state.m_keys_released[KEY_LEFT]);
    state.key_event(KEY_LEFT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_LEFT]);

    ASSERT_FALSE(state.m_keys_released[KEY_DOWN]);
    state.key_event(KEY_DOWN, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_DOWN]);

    ASSERT_FALSE(state.m_keys_released[KEY_UP]);
    state.key_event(KEY_UP, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_UP]);

    ASSERT_FALSE(state.m_keys_released[KEY_PAGE_UP]);
    state.key_event(KEY_PAGE_UP, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_PAGE_UP]);

    ASSERT_FALSE(state.m_keys_released[KEY_PAGE_DOWN]);
    state.key_event(KEY_PAGE_DOWN, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_PAGE_DOWN]);

    ASSERT_FALSE(state.m_keys_released[KEY_HOME]);
    state.key_event(KEY_HOME, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_HOME]);

    ASSERT_FALSE(state.m_keys_released[KEY_END]);
    state.key_event(KEY_END, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_END]);

    ASSERT_FALSE(state.m_keys_released[KEY_CAPS_LOCK]);
    state.key_event(KEY_CAPS_LOCK, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_CAPS_LOCK]);

    ASSERT_FALSE(state.m_keys_released[KEY_SCROLL_LOCK]);
    state.key_event(KEY_SCROLL_LOCK, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_SCROLL_LOCK]);

    ASSERT_FALSE(state.m_keys_released[KEY_NUM_LOCK]);
    state.key_event(KEY_NUM_LOCK, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_NUM_LOCK]);

    ASSERT_FALSE(state.m_keys_released[KEY_PRINT_SCREEN]);
    state.key_event(KEY_PRINT_SCREEN, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_PRINT_SCREEN]);

    ASSERT_FALSE(state.m_keys_released[KEY_PAUSE]);
    state.key_event(KEY_PAUSE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_PAUSE]);

    ASSERT_FALSE(state.m_keys_released[KEY_F1]);
    state.key_event(KEY_F1, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F1]);

    ASSERT_FALSE(state.m_keys_released[KEY_F2]);
    state.key_event(KEY_F2, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F2]);

    ASSERT_FALSE(state.m_keys_released[KEY_F3]);
    state.key_event(KEY_F3, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F3]);

    ASSERT_FALSE(state.m_keys_released[KEY_F4]);
    state.key_event(KEY_F4, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F4]);

    ASSERT_FALSE(state.m_keys_released[KEY_F5]);
    state.key_event(KEY_F5, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F5]);

    ASSERT_FALSE(state.m_keys_released[KEY_F6]);
    state.key_event(KEY_F6, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F6]);

    ASSERT_FALSE(state.m_keys_released[KEY_F7]);
    state.key_event(KEY_F7, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F7]);

    ASSERT_FALSE(state.m_keys_released[KEY_F8]);
    state.key_event(KEY_F8, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F8]);

    ASSERT_FALSE(state.m_keys_released[KEY_F9]);
    state.key_event(KEY_F9, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F9]);

    ASSERT_FALSE(state.m_keys_released[KEY_F10]);
    state.key_event(KEY_F10, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F10]);

    ASSERT_FALSE(state.m_keys_released[KEY_F11]);
    state.key_event(KEY_F11, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F11]);

    ASSERT_FALSE(state.m_keys_released[KEY_F12]);
    state.key_event(KEY_F12, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F12]);

    ASSERT_FALSE(state.m_keys_released[KEY_F13]);
    state.key_event(KEY_F13, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F13]);

    ASSERT_FALSE(state.m_keys_released[KEY_F14]);
    state.key_event(KEY_F14, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F14]);

    ASSERT_FALSE(state.m_keys_released[KEY_F15]);
    state.key_event(KEY_F15, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F15]);

    ASSERT_FALSE(state.m_keys_released[KEY_F16]);
    state.key_event(KEY_F16, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F16]);

    ASSERT_FALSE(state.m_keys_released[KEY_F17]);
    state.key_event(KEY_F17, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F17]);

    ASSERT_FALSE(state.m_keys_released[KEY_F18]);
    state.key_event(KEY_F18, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F18]);

    ASSERT_FALSE(state.m_keys_released[KEY_F19]);
    state.key_event(KEY_F19, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F19]);

    ASSERT_FALSE(state.m_keys_released[KEY_F20]);
    state.key_event(KEY_F20, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F20]);

    ASSERT_FALSE(state.m_keys_released[KEY_F21]);
    state.key_event(KEY_F21, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F21]);

    ASSERT_FALSE(state.m_keys_released[KEY_F22]);
    state.key_event(KEY_F22, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F22]);

    ASSERT_FALSE(state.m_keys_released[KEY_F23]);
    state.key_event(KEY_F23, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F23]);

    ASSERT_FALSE(state.m_keys_released[KEY_F24]);
    state.key_event(KEY_F24, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F24]);

    ASSERT_FALSE(state.m_keys_released[KEY_F25]);
    state.key_event(KEY_F25, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_F25]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_0]);
    state.key_event(KEY_KP_0, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_0]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_1]);
    state.key_event(KEY_KP_1, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_1]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_2]);
    state.key_event(KEY_KP_2, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_2]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_3]);
    state.key_event(KEY_KP_3, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_3]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_4]);
    state.key_event(KEY_KP_4, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_4]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_5]);
    state.key_event(KEY_KP_5, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_5]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_6]);
    state.key_event(KEY_KP_6, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_6]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_7]);
    state.key_event(KEY_KP_7, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_7]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_8]);
    state.key_event(KEY_KP_8, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_8]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_9]);
    state.key_event(KEY_KP_9, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_9]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_DECIMAL]);
    state.key_event(KEY_KP_DECIMAL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_DECIMAL]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_DIVIDE]);
    state.key_event(KEY_KP_DIVIDE, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_DIVIDE]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_MULTIPLY]);
    state.key_event(KEY_KP_MULTIPLY, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_MULTIPLY]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_SUBTRACT]);
    state.key_event(KEY_KP_SUBTRACT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_SUBTRACT]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_ADD]);
    state.key_event(KEY_KP_ADD, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_ADD]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_ENTER]);
    state.key_event(KEY_KP_ENTER, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_ENTER]);

    ASSERT_FALSE(state.m_keys_released[KEY_KP_EQUAL]);
    state.key_event(KEY_KP_EQUAL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_KP_EQUAL]);

    ASSERT_FALSE(state.m_keys_released[KEY_LEFT_SHIFT]);
    state.key_event(KEY_LEFT_SHIFT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_LEFT_SHIFT]);

    ASSERT_FALSE(state.m_keys_released[KEY_LEFT_CONTROL]);
    state.key_event(KEY_LEFT_CONTROL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_LEFT_CONTROL]);

    ASSERT_FALSE(state.m_keys_released[KEY_LEFT_ALT]);
    state.key_event(KEY_LEFT_ALT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_LEFT_ALT]);

    ASSERT_FALSE(state.m_keys_released[KEY_LEFT_SUPER]);
    state.key_event(KEY_LEFT_SUPER, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_LEFT_SUPER]);

    ASSERT_FALSE(state.m_keys_released[KEY_RIGHT_SHIFT]);
    state.key_event(KEY_RIGHT_SHIFT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_RIGHT_SHIFT]);

    ASSERT_FALSE(state.m_keys_released[KEY_RIGHT_CONTROL]);
    state.key_event(KEY_RIGHT_CONTROL, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_RIGHT_CONTROL]);

    ASSERT_FALSE(state.m_keys_released[KEY_RIGHT_ALT]);
    state.key_event(KEY_RIGHT_ALT, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_RIGHT_ALT]);

    ASSERT_FALSE(state.m_keys_released[KEY_RIGHT_SUPER]);
    state.key_event(KEY_RIGHT_SUPER, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_RIGHT_SUPER]);

    ASSERT_FALSE(state.m_keys_released[KEY_MENU]);
    state.key_event(KEY_MENU, 0, KEY_RELEASE, 0);
    ASSERT_TRUE(state.m_keys_released[KEY_MENU]);
}

TEST(InputTest, mods) {
    InputState state;
    ASSERT_EQ(0, state.m_mods);
    state.key_event(KEY_Q, 0, KEY_PRESS, 13);
    ASSERT_EQ(13, state.m_mods);
}
