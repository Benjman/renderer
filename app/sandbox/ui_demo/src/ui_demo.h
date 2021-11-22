#include "core/colors.h"
#include "demo_ui_controller.h"

#include <core/runner.h>

class UiDemo : public Runner {
    public:
        UiDemo(GLFWwindow *window) : Runner(window) {
            clear_color(glm::vec3(.93));
        }

        void init(const RunnerContext& context) override {
            ui_controller.init(context);
        }

        void pre_update(const RunnerContext &context) override {
            ui_controller.pre_update(context);
        }

        void update(const RunnerContext& context) override {
            ui_controller.update(context);
        }

        void post_update(const RunnerContext &context) override {
            ui_controller.post_update(context);
        }

        void render() override {
            glClear(GL_COLOR_BUFFER_BIT);
            ui_controller.render();
        }

    private:
        DemoUiController ui_controller;

};
