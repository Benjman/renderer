#include "core/window.h"
#include "text/text.h"
#include <core/ui/text_element.h>
#include <core/ui/ui_element.h>
#include <core/ui/text_element_builder.h>
#include <text.h>

TextElement::TextElement(Text text, UiElement* parent) : UiElement(parent), m_text(text) {
}

TextElementBuilder TextElement::create(Text& text, UiElement* parent) {
    return TextElementBuilder(text, parent);
}
