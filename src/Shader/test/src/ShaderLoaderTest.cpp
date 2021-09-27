#include "ShaderTestFixture.h"
#define private public
#include <ShaderLoader.h>

struct ShaderLoaderFixture : public ShaderTestFixture {
	const char *vertShaderSrc = "#version 330 core\n"
								"layout (location = 0) in vec3 aPos;\n"
								"void main()\n"
								"{\n"
								"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
								"}\0";
	const char *fragShaderSrc = "#version 330 core\n"
								"out vec4 FragColor;\n"
								"void main()\n"
								"{\n"
								"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
								"}\n\0";

protected:
	void TearDown() override {
		ASSERT_FALSE(glGetError());
	}

	void SetUp() override {
		ASSERT_FALSE(glGetError());
	}
};

TEST_F(ShaderLoaderFixture, doesVertexShaderCompile) {
	ASSERT_TRUE(ShaderLoader::compileShader(GL_VERTEX_SHADER, vertShaderSrc, -1));
}

TEST_F(ShaderLoaderFixture, doesVertexShaderNotCompile) {
	ASSERT_TRUE(ShaderLoader::compileShader(GL_VERTEX_SHADER,  "bad shader source", -1));
}

TEST_F(ShaderLoaderFixture, doesFragmentShaderCompile) {
	std::string src = fragShaderSrc;
	ASSERT_TRUE(ShaderLoader::compileShader(GL_FRAGMENT_SHADER, fragShaderSrc, -1));
}

TEST_F(ShaderLoaderFixture, doesFragmentShaderNotCompile) {
	ASSERT_TRUE(ShaderLoader::compileShader(GL_FRAGMENT_SHADER,  "bad shader source", -1));
}

TEST_F(ShaderLoaderFixture, doesProgramLink) {
	GLuint vertId = ShaderLoader::compileShader(GL_VERTEX_SHADER, vertShaderSrc, -1);
	GLuint fragId = ShaderLoader::compileShader(GL_FRAGMENT_SHADER, fragShaderSrc, -1);

	ASSERT_TRUE(ShaderLoader::linkProgram(vertId, fragId));
}
