#include "./src/Pong.hpp"

#include <iostream>

int main(int argc, char **argv) {
	const char *title = "Pong";
	const int width = 640;
	const int height = 480;
	try {
		GLFWwindow *window = initializeGlfw(title, width, height);
		Pong pong(window, width, height);
		return pong.run();
	} catch (const std::exception &ex) {
		std::cin.get();
		return EXIT_FAILURE;
	} catch (...) {
		std::cin.get();
		return EXIT_FAILURE;
	}
}
