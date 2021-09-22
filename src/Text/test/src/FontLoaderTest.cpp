#include "utils/glfw.h"

#include <gtest/gtest.h>
#include <cmath>
#include <GLFW/glfw3.h>

#define private public
#include <Text/Font.h>

class FontLoaderFixture : public ::testing::Test {
	protected:
		static void SetUpTestSuite() {
			window = initializeGlfw("Font Tests", 1, 1, true);
		}

		static void TearDownTestSuite() {
			std::atexit([]() {
				destroyGlfw(window);
			});
		}

	private:
		static GLFWwindow* window;
};

GLFWwindow* FontLoaderFixture::window = nullptr;

TEST_F(FontLoaderFixture, build_path) {
	Font font;
	GLuint texture_id = load_font(font, "/home/ben/src/renderer/res/fonts/DejaVuSans.ttf");

	ASSERT_TRUE(texture_id) << "Texture ID not generated";
	ASSERT_GT(font.fontinfo.numGlyphs, 0) << "Failed to initialize stb_truetype";
	ASSERT_LT(font.ascent, std::numeric_limits<int32_t>::max()) << "Failed to get stbtt_GetFontVMetrics";
	ASSERT_LT(font.descent, std::numeric_limits<int32_t>::max()) << "Failed to get stbtt_GetFontVMetrics";
	ASSERT_LT(font.line_gap, std::numeric_limits<int32_t>::max()) << "Failed to get stbtt_GetFontVMetrics";
	ASSERT_LT(font.scale_factor, std::numeric_limits<float_t>::max()) << "Failed to get stbtt_ScaleForPixelHeight";
}

