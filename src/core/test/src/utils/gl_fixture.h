#ifndef CORE_TEST_GL_FIXTURE
#define CORE_TEST_GL_FIXTURE

#include <gtest/gtest.h>
#include "utils/glfw.h"

struct GLFixture : public ::testing::Test {
	protected:
		static void SetUpTestSuite() {
			m_window = initializeGlfw("Shader Tests", 1, 1, true);
		}

		static void TearDownTestSuite() {
			std::atexit([]() {
                    destroyGlfw(m_window);
			});
		}

	private:
		static GLFWwindow *m_window;
};


#endif // CORE_TEST_GL_FIXTURE
