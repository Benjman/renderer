#include <gtest/gtest.h>
#include <core/window.h>

TEST(WindowTests, aspect_ratio) {
    window::update(3.0, 1.5);
    ASSERT_EQ(2.0, window::aspect_ratio());
    window::update(1920.0, 1080.0);
    ASSERT_NEAR(1.77777, window::aspect_ratio(), 0.00001);
}

TEST(WindowTests, size) {
    window::update(1920, 1080);
    ASSERT_EQ(1920, window::width());
    ASSERT_EQ(1080, window::height());
}
