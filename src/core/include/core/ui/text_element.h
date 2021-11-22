#ifndef CORE_UI_TEXT_ELEMENT_H
#define CORE_UI_TEXT_ELEMENT_H

#include "ui_element.h"
#include <text/text.h>

class TextElementBuilder;

class TextElement : public UiElement {
    public:
        static TextElementBuilder create(Text& text, UiElement* parent = nullptr);

        TextElement(Text text, UiElement* parent = nullptr);

        [[nodiscard]] Text& text() {
            return m_text;
        }

        void text(Text text) {
            m_text = text;
        }

    protected:
        Text m_text;

    private:
        friend class TextElementBuilder;

};

#endif // CORE_UI_TEXT_ELEMENT_H
