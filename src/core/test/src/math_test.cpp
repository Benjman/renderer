#include <core/math.h>

#include <gtest/gtest.h>

TEST(Math, map_float_t) {
    float_t current = 1.0;
    float_t expected = 2.0;

    float_t first_start = 0.0;
    float_t first_end = 1.0;
    float_t second_start = 0.0;
    float_t second_end = 2.0;

    ASSERT_EQ(expected, math::map(current, first_start, first_end, second_start, second_end));
}

TEST(Math, map_decimal) {
    float_t current = 1.0;
    float_t expected = 1.5;

    float_t first_start = 0.0;
    float_t first_end = 2.0;
    float_t second_start = 0.0;
    float_t second_end = 3.0;

    ASSERT_EQ(expected, math::map(current, first_start, first_end, second_start, second_end));
}

TEST(Math, is_within) {
    glm::vec4 region = glm::vec4(10, 20, 30, 40);

    ASSERT_TRUE(math::is_within(glm::vec2(10, 20), region)) << "Top-left inclusive test expected pass.";
    ASSERT_TRUE(math::is_within(glm::vec2(10, 40), region)) << "Bottom-left inclusive test expected pass.";

    ASSERT_TRUE(math::is_within(glm::vec2(30, 20), region)) << "Top-right inclusive test expected pass.";
    ASSERT_TRUE(math::is_within(glm::vec2(30, 40), region)) << "Bottom-right inclusive test expected pass.";


    ASSERT_FALSE(math::is_within(glm::vec2(9, 20), region)) << "Top-left x-axis out of bounds test expected fail.";
    ASSERT_FALSE(math::is_within(glm::vec2(9, 41), region)) << "Bottom-left x-axis out of bounds test expected fail.";

    ASSERT_FALSE(math::is_within(glm::vec2(10, 19), region)) << "Top-left y-axis out of bounds test expected fail.";
    ASSERT_FALSE(math::is_within(glm::vec2(10, 41), region)) << "Bottom-left y-axis out of bounds test expected fail.";

    ASSERT_FALSE(math::is_within(glm::vec2(31, 20), region)) << "Top-right x-axis out of bounds test expected fail.";
    ASSERT_FALSE(math::is_within(glm::vec2(31, 40), region)) << "Bottom-right x-axis out of bounds test expected fail.";

    ASSERT_FALSE(math::is_within(glm::vec2(30, 19), region)) << "Top-right y-axis out of bounds test expected fail.";
    ASSERT_FALSE(math::is_within(glm::vec2(30, 41), region)) << "Bottom-right y-axis out of bounds test expected fail.";

    // test within region passes
    for (size_t x = region.x; x < region.z; x++) {
        for (size_t y = region.y; y < region.w; y++) {
            ASSERT_TRUE(math::is_within(glm::vec2(x, y), region)) << "Inner region expected to pass.";
        }
    }
}
