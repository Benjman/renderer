#ifndef CORE_UI_BUILDERS_H
#define CORE_UI_BUILDERS_H

#include "ui_element.h"
#include "text_element.h"

class TextElementBuilder {
    public:
        TextElementBuilder(Text& text, UiElement* parent = nullptr) : root(text, parent) {
        }

        TextElementBuilder(TextElement& root) : root(root) {
        }

        operator TextElement() const {
            return std::move(root);
        }


    private:
        TextElement root;

};

#endif // CORE_UI_BUILDERS_H
