#include <gtest/gtest.h>
#include <Text/internal/gl.hpp>
#include "TextTestFixture.h"

//GLFWwindow *TextTestFixture::m_window = nullptr;

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
