#include <gtest/gtest.h>
#include "shader_test_fixture.h"

GLFWwindow *ShaderTestFixture::m_window = nullptr;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
