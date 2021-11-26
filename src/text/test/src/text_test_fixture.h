#ifndef TEXT_TEXT_TEST_FIXTURE
#define TEXT_TEXT_TEST_FIXTURE

#include <gtest/gtest.h>
#include <text/font.h>

class TextTestFixture : public ::testing::Test {
    protected:
        static void SetUpTestSuite() {
            Font::load_font("/home/ben/src/renderer/res/fonts/DejaVuSans.ttf", &font);
        }

        static void TearDownTestSuite() {
        }

        static Font font;
};

#endif // TEXT_TEXT_TEST_FIXTURE
