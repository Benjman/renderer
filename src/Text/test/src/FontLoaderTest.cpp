#include "utils/glfw.hpp"

#include <gtest/gtest.h>
#include <cmath>
#include <GLFW/glfw3.h>

#define private public
#include <Text/Font.h>

class Fixture : public ::testing::Test {
	protected:
		static void SetUpTestSuite() {
			window = initializeGlfw("Text Tests", 1, 1, true);

			FILE* font_file = fopen("/home/ben/src/renderer/res/fonts/DejaVuSans.ttf", "rb");
			fseek(font_file, 0, SEEK_END);
			size_t size = ftell(font_file); /* how long is the file ? */
			fseek(font_file, 0, SEEK_SET); /* reset */
			fread(ttf_buffer, size, 1, font_file);
			fclose(font_file);
		}

		static void TearDownTestSuite() {
			delete[] ttf_buffer;

			std::atexit([]() {
				destroyGlfw(window);
			});
		}

	private:
		static u_char* ttf_buffer;
		static GLFWwindow* window;
};

u_char* Fixture::ttf_buffer = new u_char[1024 * 1024 * 5]{0};
GLFWwindow* Fixture::window = nullptr;

TEST_F(Fixture, build_path) {
	Font font;
	load_font(font, Fixture::ttf_buffer);

	ASSERT_GT(font.fontinfo.numGlyphs, 0) << "Failed to initialize stb_truetype";

	ASSERT_LT(font.ascent, std::numeric_limits<int32_t>::max()) << "Failed to get stbtt_GetFontVMetrics";
	ASSERT_LT(font.descent, std::numeric_limits<int32_t>::max()) << "Failed to get stbtt_GetFontVMetrics";
	ASSERT_LT(font.line_gap, std::numeric_limits<int32_t>::max()) << "Failed to get stbtt_GetFontVMetrics";
	ASSERT_LT(font.scale_factor, std::numeric_limits<float_t>::max()) << "Failed to get stbtt_ScaleForPixelHeight";
}

