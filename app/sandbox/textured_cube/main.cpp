#include <iostream>

#include "../../utils/glfw.h"
#include "src/textured_cube.hpp"

int main(int argc, char **argv) {
	const int width = 640;
	const int height = 480;
	try {
		GLFWwindow *window = initializeGlfw("Text Runner", width, height);
		SandboxRunner runner(window, width, height);
		return runner.run();
	} catch (const std::exception &ex) {
		std::cin.get();
		return EXIT_FAILURE;
	} catch (...) {
		std::cin.get();
		return EXIT_FAILURE;
	}
}


