#include <gtest/gtest.h>
#include <glm/vec2.hpp>

#include "text_test_fixture.h"

#include <text.h>
#include <text/internal/generator.h>

using namespace internal;

TEST_F(TextTestFixture, word_count) {
    Text text("This is a test", &font, glm::vec2(), 0);
    Context context;
    generate_structure(&text, context);

    ASSERT_EQ(1, context.lines.size()) << "Line count inaccurate.";
    ASSERT_EQ(4, context.lines.at(0)->words.size()) << "Word count inaccurate.";
    ASSERT_EQ(11, text.char_count);

    ASSERT_STREQ("This", context.lines.at(0)->words.at(0)->value.c_str());
    ASSERT_STREQ("is", context.lines.at(0)->words.at(1)->value.c_str());
    ASSERT_STREQ("a", context.lines.at(0)->words.at(2)->value.c_str());
    ASSERT_STREQ("test", context.lines.at(0)->words.at(3)->value.c_str());
}

TEST_F(TextMeshGeneratorFixture, multi_line) {
    Text text("Testing a bit", &font, glm::vec2(), 0);
    Context context;
    generate_structure(&text, context);

    ASSERT_EQ(2, context.lines.size()) << "Line count inaccurate.";
}
