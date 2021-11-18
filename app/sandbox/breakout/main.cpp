#include <core/glfw.h>
#include <core/window.h>

#include "src/breakout_runner.hpp"

#include <iostream>

int main(int argc, char **argv) {
    try {
        GLFWwindow *window = initializeGlfw("Breakout", DISPLAY_PROFILE_640_480);
        BreakoutRunner runner(window);
        return runner.run();
    } catch (const std::exception&) {
        std::cin.get();
        return EXIT_FAILURE;
    } catch (...) {
        std::cin.get();
        return EXIT_FAILURE;
    }
}


