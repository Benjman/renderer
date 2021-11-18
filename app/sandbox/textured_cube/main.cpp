#include <core/glfw.h>
#include <core/window.h>
#include "src/textured_cube.hpp"

#include <iostream>

int main(int argc, char **argv) {
    try {
        GLFWwindow *window = initializeGlfw("Text Runner", DISPLAY_PROFILE_640_480);
        SandboxRunner runner(window);
        return runner.run();
    } catch (const std::exception &ex) {
        std::cin.get();
        return EXIT_FAILURE;
    } catch (...) {
        std::cin.get();
        return EXIT_FAILURE;
    }
}


