#include <gtest/gtest.h>

#include <Text.h>
#include <Text/internal/TextMeshGenerator.h>
#include <glm/vec2.hpp>

class TextMeshFixture : public ::testing::Test {
	protected:
		static void SetUpTestSuite() {
			load_font(font, "/home/ben/src/renderer/res/fonts/DejaVuSans.ttf", false);
		}

		static void TearDownTestSuite() {
		}

		static Font font;
};

Font TextMeshFixture::font = Font();

using namespace internal;

TEST_F(TextMeshFixture, word_count) {
	Text text("This is a test", &font, glm::vec2(), 0);
	generate_text_mesh(&text);
}

TEST_F(TextMeshFixture, multi_line) {
	Text text("Testing a bit", &font, glm::vec2(), 250, 0);
	TextStructure structure;
	generate_text_structure(&text, structure);

	ASSERT_EQ(2, structure.lines.size()) << "Line count inaccurate.";
	ASSERT_EQ(11, structure.char_count);
}
