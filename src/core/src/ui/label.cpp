#include <core/ui/label.h>
#include <core/window.h>
#include <text.h>

Label::Label(std::string value, Font* font, UiElement* parent) : UiElement(parent) {
    size(window::width(), window::height());
    Text text = Text::create(m_text.value(), m_text.font())
        .alignment(Text::TEXT_ALIGN_CENTER | Text::TEXT_ALIGN_MIDDLE)
        .value(value)
        .font(font)
        .pos(pos().x, pos().y)
        .max_width(size().x)
        .max_height(size().y);
    this->text(text);
}
