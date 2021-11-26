#include <gtest/gtest.h>
#include <cmath>
#include <GLFW/glfw3.h>

#define private public
#include <text/font.h>

class FontLoaderFixture : public ::testing::Test {
    protected:
        static void SetUpTestSuite() {
        }

        static void TearDownTestSuite() {
        }

    private:
        static GLFWwindow* window;
};

GLFWwindow* FontLoaderFixture::window = nullptr;

TEST_F(FontLoaderFixture, build_path) {
    Font font;
    Font::load_font("/home/ben/src/renderer/res/fonts/DejaVuSans.ttf", &font);

    // ASSERT_GT(font.fontinfo.numGlyphs, 0) << "Failed to initialize stb_truetype";
    ASSERT_LT(font.ascent, std::numeric_limits<int32_t>::max()) << "Failed to get stbtt_GetFontVMetrics";
    ASSERT_LT(font.descent, std::numeric_limits<int32_t>::max()) << "Failed to get stbtt_GetFontVMetrics";
    ASSERT_LT(font.line_gap, std::numeric_limits<int32_t>::max()) << "Failed to get stbtt_GetFontVMetrics";
}

