#include "src/TextRunner.hpp"
#include <iostream>
#include <gl.h>

int main(int argc, char **argv) {
	const int width = 640;
	const int height = 480;
	try {
		GLFWwindow *window = initializeGlfw("Text Runner", width, height);
		TextRunner runner(window, width, height);
		return runner.run();
	} catch (const std::exception &ex) {
		std::cin.get();
		return EXIT_FAILURE;
	} catch (...) {
		std::cin.get();
		return EXIT_FAILURE;
	}
}

