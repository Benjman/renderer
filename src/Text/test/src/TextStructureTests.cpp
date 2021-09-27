#include <gtest/gtest.h>

#include <Text.h>
#include <Text/internal/TextMeshGenerator.h>
#include <glm/vec2.hpp>

class TextStructureFixture : public ::testing::Test {
	protected:
		static void SetUpTestSuite() {
			load_font(font, "/home/ben/src/renderer/res/fonts/DejaVuSans.ttf", false);
		}

		static void TearDownTestSuite() {
		}

		static Font font;
};

Font TextStructureFixture::font = Font();

using namespace internal;

TEST_F(TextStructureFixture, word_count) {
	Text text("This is a test", &font, glm::vec2(), 0);
	TextStructure structure;
	generate_text_structure(&text, structure);

	ASSERT_EQ(1, structure.lines.size()) << "Line count inaccurate.";
	ASSERT_EQ(4, structure.lines.at(0)->words.size()) << "Word count inaccurate.";
	ASSERT_EQ(11, text.char_count);

	ASSERT_STREQ("This", structure.lines.at(0)->words.at(0)->value.c_str());
	ASSERT_STREQ("is", structure.lines.at(0)->words.at(1)->value.c_str());
	ASSERT_STREQ("a", structure.lines.at(0)->words.at(2)->value.c_str());
	ASSERT_STREQ("test", structure.lines.at(0)->words.at(3)->value.c_str());
}

TEST_F(TextStructureFixture, multi_line) {
	Text text("Testing a bit", &font, glm::vec2(), 250, 0);
	TextStructure structure;
	generate_text_structure(&text, structure);

	ASSERT_EQ(2, structure.lines.size()) << "Line count inaccurate.";
}
