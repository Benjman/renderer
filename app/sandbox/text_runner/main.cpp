#include <core/glfw.h>
#include "core/window.h"
#include "src/TextRunner.hpp"

#include <iostream>

int main(int argc, char **argv) {
    display_profile_t display_profile = DISPLAY_PROFILE_640_480;
	try {
		GLFWwindow *window = initializeGlfw("Text Runner", display_profile);
		TextRunner runner(window, display_profile);
		return runner.run();
	} catch (const std::exception &ex) {
		std::cin.get();
		return EXIT_FAILURE;
	} catch (...) {
		std::cin.get();
		return EXIT_FAILURE;
	}
}


