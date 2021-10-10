#include <gtest/gtest.h>

#include <text.h>
#include <text/internal/generator.h>
#include <glm/vec2.hpp>

class TextMeshFixture : public ::testing::Test {
	protected:
		static void SetUpTestSuite() {
			load_font(font, "/home/ben/src/renderer/res/fonts/DejaVuSans.ttf");
		}

		static void TearDownTestSuite() {
		}

		static Font font;
};

Font TextMeshFixture::font = Font();

using namespace internal::text;

TEST_F(TextMeshFixture, word_count) {
	Text text("This is a test", &font, glm::vec2(), 0);
	generate_mesh(&text);
}

TEST_F(TextMeshFixture, multi_line) {
	Text text("Testing a bit", &font, glm::vec2(), 0);
	Context context;
	generate_structure(&text, context);

	ASSERT_EQ(2, context.lines.size()) << "Line count inaccurate.";
	ASSERT_EQ(11, context.text->char_count);
}

