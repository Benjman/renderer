#include "src/BreakoutRunner.hpp"

#include <iostream>
#include <gl.h>

#include <Core/File.h>

int main(int argc, char **argv) {
	const int width = 640;
	const int height = 480;
	try {
		GLFWwindow *window = initializeGlfw("Breakout", width, height);
		BreakoutRunner runner(window, width, height);
		return runner.run();
	} catch (const std::exception &ex) {
		std::cin.get();
		return EXIT_FAILURE;
	} catch (...) {
		std::cin.get();
		return EXIT_FAILURE;
	}
}


