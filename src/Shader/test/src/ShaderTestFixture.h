#ifndef RENDERER_SHADERTESTFIXTURE_H
#define RENDERER_SHADERTESTFIXTURE_H

#include <gtest/gtest.h>
#include <type_traits>
#include <math.h>
#include <gl.h>

#ifndef GLFW_HEADLESS
static bool IS_HEADLESS = true;
#else
static bool IS_HEADLESS = GLFW_HEADLESS;
#endif

struct ShaderTestFixture : public ::testing::Test {
	protected:
		static void SetUpTestSuite() {
			m_window = initializeGlfw("", 0, 0, IS_HEADLESS);
		}

		static void TearDownTestSuite() {
			std::atexit([]() {
					destroyGlfw(m_window);
			});
		}

	private:
		static GLFWwindow *m_window;
};

void testBoundVertexBuffer(GLuint id);

#endif //RENDERER_SHADERTESTFIXTURE_H
