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
