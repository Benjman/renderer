#ifndef TEXT_TEXT_H
#define TEXT_TEXT_H

#include <Core/Font.h>
#include <Core/Game.h>
#include <Shader.h>

class TextRunner : public Game {
	public:
		TextRunner(GLFWwindow *window, const int width, const int height) : Game(window, width, height) {
			std::string test = "Hello";
			Font font(test);
		}

	protected:
		void update(const double time) override {
		}

		void render() override {
		}

		void keyEvent(int key, int mode) override {
		}

		void windowSizeChanged(int width, int height) override {
		}


	private:

};

#endif // TEXT_TEXT_H

