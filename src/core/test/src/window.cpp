#include <gtest/gtest.h>
#include <core/window.h>

TEST(WindowTests, aspect_ratio) {
    window::set_size(3.0, 1.5);
    ASSERT_EQ(2.0, window::aspect_ratio());
    window::set_size(1920.0, 1080.0);
    ASSERT_NEAR(1.77777, window::aspect_ratio(), 0.00001);
}

TEST(WindowTests, size) {
    window::set_size(1920, 1080);
    ASSERT_EQ(1920, window::width());
    ASSERT_EQ(1080, window::height());
}

TEST(WindowTests_display_profile, width) {
    ASSERT_EQ(640, window::find_display_profile_width(DISPLAY_PROFILE_640_480));
    ASSERT_EQ(1280, window::find_display_profile_width(DISPLAY_PROFILE_1280_720));
    ASSERT_EQ(1920, window::find_display_profile_width(DISPLAY_PROFILE_1920_1080));
    ASSERT_EQ(2560, window::find_display_profile_width(DISPLAY_PROFILE_2560_1440));
    ASSERT_EQ(2048, window::find_display_profile_width(DISPLAY_PROFILE_2048_1080));
    ASSERT_EQ(3840, window::find_display_profile_width(DISPLAY_PROFILE_3840_2160));
    ASSERT_EQ(7680, window::find_display_profile_width(DISPLAY_PROFILE_7680_4320));
    ASSERT_EQ(0, window::find_display_profile_width(std::numeric_limits<size_t>::max())) << "Unrecognized display profile should return 0";
}

TEST(WindowTests_display_profile, height) {
    ASSERT_EQ(480, window::find_display_profile_height(DISPLAY_PROFILE_640_480));
    ASSERT_EQ(720, window::find_display_profile_height(DISPLAY_PROFILE_1280_720));
    ASSERT_EQ(1080, window::find_display_profile_height(DISPLAY_PROFILE_1920_1080));
    ASSERT_EQ(1440, window::find_display_profile_height(DISPLAY_PROFILE_2560_1440));
    ASSERT_EQ(1080, window::find_display_profile_height(DISPLAY_PROFILE_2048_1080));
    ASSERT_EQ(2160, window::find_display_profile_height(DISPLAY_PROFILE_3840_2160));
    ASSERT_EQ(4320, window::find_display_profile_height(DISPLAY_PROFILE_7680_4320));
    ASSERT_EQ(0, window::find_display_profile_height(std::numeric_limits<size_t>::max())) << "Unrecognized display profile should return 0";
}
