#include <iostream>

#include "../../utils/glfw.h"
#include "./src/pong_runner.hpp"

int main(int argc, char **argv) {
	const int width = 640;
	const int height = 480;
	try {
		GLFWwindow *window = initializeGlfw("Pong", width, height);
		PongRunner pong(window, width, height);
		return pong.run();
	} catch (const std::exception &ex) {
		std::cin.get();
		return EXIT_FAILURE;
	} catch (...) {
		std::cin.get();
		return EXIT_FAILURE;
	}
}
