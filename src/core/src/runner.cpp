#include <core/glfw.h>

#include <core/input.h>
#include <core/runner.h>
#include <core/ui/ui_fonts.h>
#include <core/window.h>

#include <GLFW/glfw3.h>

#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <unistd.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

inline void keyHandler(GLFWwindow*,int32_t,int32_t,int32_t,int32_t);
inline void windowSizeChangeHandler(GLFWwindow*,int32_t,int32_t);

inline static Runner *INSTANCE; // TODO refactor so there is a global map of GLFWwindows and Runners

Runner::Runner(GLFWwindow *glfw_window) : m_glfw_window(glfw_window), m_clear_color(glm::vec4(0.2, 0.3, 0.3, 1.0)) {
    INSTANCE = this;
    glfwGetWindowSize(glfw_window, &m_width, &m_height);
    glfwSetKeyCallback(m_glfw_window, keyHandler);
    glfwSetWindowSizeCallback(m_glfw_window, windowSizeChangeHandler);
    glfwSetCursorPosCallback(m_glfw_window, [](GLFWwindow*, double_t x, double_t y) { input::mouse_move_event(x, y); });
    glfwSetMouseButtonCallback(glfw_window, [](GLFWwindow*, int32_t button, int32_t action, int32_t mods) { input::mouse_button_event(button, action, mods); });

    window::display_profile(window::find_display_profile(m_width, m_height));

    spdlog::set_level(spdlog::level::info);
}

Runner::~Runner() noexcept {
    fonts::cleanup();
    glfwTerminate();
}

int Runner::run() {
    const constexpr double_t dt = 1.0 / 60.0;

    RunnerContext context{};
    init(context);

    double_t time = 0.0;
    double_t accumulator = 0.0;
    double_t current_time = getRuntimeSeconds();
    double_t new_time = 0.0;
    double_t frame_time = 0.0;

    while (!glfwWindowShouldClose(m_glfw_window)) {
        input::reset();
        glfwPollEvents();

        new_time = getRuntimeSeconds();
        frame_time = new_time - current_time;
        current_time = new_time;

        accumulator += frame_time;
        context.running = new_time;

        while (accumulator >= dt) {
            context.delta = accumulator;
            update(context);

            accumulator -= dt;
            time += dt;
        }

        doRender();
    }

    return EXIT_SUCCESS;
}

void Runner::doRender() {
    glClearColor(m_clear_color.r, m_clear_color.g, m_clear_color.b, m_clear_color.a);
    render();
    glfwSwapBuffers(m_glfw_window);
}

inline void keyHandler(GLFWwindow*, int32_t key, int32_t scancode, int32_t action, int32_t mods) {
    if (action == GLFW_REPEAT) return;
    input::key_event(key, scancode, action, mods);
}

// TODO this needs to be removed because we have static display sizes
inline void windowSizeChangeHandler(GLFWwindow*, int32_t w, int32_t h) {
    window::set_size(w, h);
    INSTANCE->windowSizeChanged(w, h);
}

void Runner::clear_color(glm::vec3 color) {
    clear_color(glm::vec4(color, 1.0));
}

void Runner::clear_color(glm::vec4 color) {
    m_clear_color = color;
}
