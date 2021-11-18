#include <core/glfw.h>
#include "./src/pong_runner.hpp"
#include "core/window.h"

#include <iostream>

int main(int argc, char **argv) {
    try {
        GLFWwindow *window = initializeGlfw("Pong", DISPLAY_PROFILE_640_480);
        PongRunner pong(window);
        return pong.run();
    } catch (const std::exception &ex) {
        std::cin.get();
        return EXIT_FAILURE;
    } catch (...) {
        std::cin.get();
        return EXIT_FAILURE;
    }
}
