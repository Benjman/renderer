#ifndef RENDERER_SHADERTESTFIXTURE_H
#define RENDERER_SHADERTESTFIXTURE_H

#include <gtest/gtest.h>
#include <type_traits>
#include <math.h>

#include "utils/glfw.h"

// cout will output errors when testing for shader failure. Undefining SHADER_DEBUG will prevent this.
#undef SHADER_DEBUG

struct ShaderTestFixture : public ::testing::Test {
    protected:
        static void SetUpTestSuite() {
            m_window = initializeGlfw("Shader Tests", 1, 1, true);
            std::atexit([]() {
                destroyGlfw(m_window);
            });
        }

    private:
        static GLFWwindow *m_window;

};

#endif //RENDERER_SHADERTESTFIXTURE_H
