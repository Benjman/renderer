#ifndef CORE_UI_UI_CONTROLLER_H
#define CORE_UI_UI_CONTROLLER_H

#include "ui_element.h"
#include "label.h"

#include <core/controller.h>

class UiController : public Controller {
    public:
        explicit UiController(UiElement* element = nullptr, Controller* parent = nullptr, bool active = true) : Controller(parent, active), m_element(element) {
        }

        void render(const RunnerContext &context) override;

        void element(UiElement* element) {
            m_element = element;
        }

        inline UiElement* element() {
            return m_element;
        }

        [[nodiscard]] std::vector<UiController*>* ui_children() {
            return &m_ui_children;
        }

        size_t generate_meshes(float_t *vert_buf, uint32_t *idx_bu, size_t quad_count = 0);

        void render();

    protected:
        void child_added(Controller *child) override;

        void child_removed(Controller *child) override;

    private:
        static inline constexpr size_t UI_ELEMENTS_PER_VERT = 7;
        static inline constexpr size_t UI_ELEMENTS_PER_INDEX = 6;

        UiElement* m_element = nullptr;
        std::vector<UiController*> m_ui_children;

};

class LabelController : public UiController {
    public:
        explicit LabelController(Label* label, Controller* parent = nullptr) : UiController(label, parent) {}

};

#endif // CORE_UI_UI_CONTROLLER_H
