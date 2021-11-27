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

        void generate_meshes(float_t *vert_buf, uint32_t *idx_buf, size_t *vert_cursor, size_t *idx_cursor, size_t* idx_pointer);

        void render();

    protected:
        void child_added(Controller *child) override {
            if (auto* ui_child = dynamic_cast<UiController*>(child)) {
                m_ui_children.emplace_back(ui_child);
            }
        }

        void child_removed(Controller *child) override {
            if (auto* ui_child = dynamic_cast<UiController*>(child)) {
                auto it = std::find(m_ui_children.begin(), m_ui_children.end(), ui_child);
                if (it == m_ui_children.end())
                    // TODO warning log
                    return;

                m_ui_children.erase(it);
                m_ui_children.emplace_back(ui_child);
            }
        }

    private:
        UiElement* m_element = nullptr;
        std::vector<UiController*> m_ui_children;

};

class LabelController : public UiController {
    public:
        explicit LabelController(Label* label, Controller* parent = nullptr) : UiController(label, parent) {}

};

#endif // CORE_UI_UI_CONTROLLER_H
