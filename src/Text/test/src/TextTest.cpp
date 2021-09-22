#include "utils/glfw.h"

#include <gtest/gtest.h>
#include <cmath>
#include <GLFW/glfw3.h>

#include <Text/Font.h>

#define private public
#include <Text/Text.h>

class TextFixture : public ::testing::Test {
	protected:
		static void SetUpTestSuite() {
			window = initializeGlfw("Text Tests", 1, 1, true);
			load_font(font, "/home/ben/src/renderer/res/fonts/DejaVuSans.ttf");
		}

		static void TearDownTestSuite() {
			std::atexit([]() {
				destroyGlfw(window);
			});
		}

		static Font font;

	private:
		static GLFWwindow* window;
};

Font TextFixture::font = Font();
GLFWwindow* TextFixture::window = nullptr;

TEST_F(TextFixture, flags_test) {
	Text text("Testing", font, glm::vec2(125, 20), LINE_GAP_2_0 | TEXT_ALIGN_JUSTIFY);
}

