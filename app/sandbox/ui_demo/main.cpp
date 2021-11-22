#include <core/glfw.h>

#include "core/window.h"
#include "src/ui_demo.h"

#include <iostream>


int main(int argc, char **argv) {
    try {
        GLFWwindow *window = initializeGlfw("Text Runner", DISPLAY_PROFILE_1280_720);
        UiDemo runner(window);
        return runner.run();
    } catch (const std::exception &ex) {
        std::cin.get();
        return EXIT_FAILURE;
    } catch (...) {
        std::cin.get();
        return EXIT_FAILURE;
    }
}



