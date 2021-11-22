#include <gtest/gtest.h>
#include "core/memory/element_buffer.h"

#include <text.h>
#include <shader/texture.h>
#include <core/file.h>

#define private public
#define protected public
#include <core/ui/text_element.h>
#include <core/ui/text_element_builder.h>

TEST(TextElementBuilder, text) {
    Text text = Text::create("Hello there", nullptr);
    TextElementBuilder builder(text);
    ASSERT_STREQ(text.value().c_str(), builder.root.text().value().c_str());
}
