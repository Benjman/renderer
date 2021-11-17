#include <core/glfw.h>
#include "./src/pong_runner.hpp"
#include "core/window.h"

#include <iostream>

int main(int argc, char **argv) {
    display_profile_t display_profile = DISPLAY_PROFILE_640_480;
    try {
        GLFWwindow *window = initializeGlfw("Pong", display_profile);
        PongRunner pong(window, display_profile);
        return pong.run();
    } catch (const std::exception &ex) {
        std::cin.get();
        return EXIT_FAILURE;
    } catch (...) {
        std::cin.get();
        return EXIT_FAILURE;
    }
}
