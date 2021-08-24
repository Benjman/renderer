#ifndef RENDERER_SHADERTESTFIXTURE_H
#define RENDERER_SHADERTESTFIXTURE_H

#include <gtest/gtest.h>
#include <gl.h>
#include <type_traits>

#ifndef GLFW_HEADLESS
static bool IS_HEADLESS = true;
#else
static bool IS_HEADLESS = GLFW_HEADLESS;
#endif

struct ShaderTestFixture : public ::testing::Test {
protected:
static void SetUpTestSuite() {
		initializeGlfw("", 0, 0, IS_HEADLESS);
	}

	static void TearDownTestSuite() {
		destroyGlfw();
	}
};

void testBoundVertexBuffer(GLuint id);

#endif //RENDERER_SHADERTESTFIXTURE_H
