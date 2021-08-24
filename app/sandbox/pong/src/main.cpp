#include "core/Game.h"
#include <iostream>

// Example of Pong within the EnTT system
// From: https://github.com/DomRe/EnttPong
int main(int argc, char **argv) {
	try {
		Game pong("Pong", 640, 480);
		return pong.run();
	} catch (const std::exception &ex) {
		std::cin.get();
		return EXIT_FAILURE;
	} catch (...) {
		std::cin.get();
		return EXIT_FAILURE;
	}
}
