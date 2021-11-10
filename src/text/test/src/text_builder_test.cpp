#include <gtest/gtest.h>

#include "text_test_fixture.h"

#define private public
#include <text/text_builder.h>

TEST_F(TextTestFixture, initial_state) {
    TextBuilder builder("Testing", &font);
    ASSERT_EQ("Testing", builder.m_root.m_value);
    ASSERT_EQ(&font, builder.m_root.m_font);
}

TEST_F(TextTestFixture, alignment) {
    TextBuilder builder("Testing", &font);
    builder.alignment(TEXT_ALIGN_LEFT);
    ASSERT_EQ(TEXT_ALIGN_LEFT, builder.m_root.m_alignment);
}

TEST_F(TextTestFixture, pos) {
    TextBuilder builder("Testing", &font);
    ASSERT_EQ(0, builder.m_root.m_pos_x);
    ASSERT_EQ(0, builder.m_root.m_pos_y);
    builder.pos(7, 13);
    ASSERT_EQ(7, builder.m_root.m_pos_x);
    ASSERT_EQ(13, builder.m_root.m_pos_y);
}

TEST_F(TextTestFixture, line_gap) {
    TextBuilder builder("Testing", &font);
    ASSERT_EQ(0, builder.m_root.m_line_gap);
    builder.line_gap(1.25);
    ASSERT_EQ(1.25, builder.m_root.m_line_gap);
}

TEST_F(TextTestFixture, line_height) {
    TextBuilder builder("Testing", &font);
    ASSERT_EQ(32, builder.m_root.m_line_height); // default
    builder.line_height(1.5);
    ASSERT_EQ(1.5, builder.m_root.m_line_height);
}

TEST_F(TextTestFixture, max_sizes) {
    TextBuilder builder("Testing", &font);
    ASSERT_EQ(std::numeric_limits<int16_t>::max(), builder.m_root.m_max_width); // default
    ASSERT_EQ(std::numeric_limits<int16_t>::max(), builder.m_root.m_max_height); // default
    builder.max_width(200);
    ASSERT_EQ(200, builder.m_root.m_max_width); // default
    ASSERT_EQ(std::numeric_limits<int16_t>::max(), builder.m_root.m_max_height); // default
    builder.max_height(300);
    ASSERT_EQ(200, builder.m_root.m_max_width); // default
    ASSERT_EQ(300, builder.m_root.m_max_height); // default
}
