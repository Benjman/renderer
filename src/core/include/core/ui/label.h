#ifndef CORE_UI_LABEL_H
#define CORE_UI_LABEL_H

#include "ui_element.h"

class Font;

class Label : public UiElement {
    public:
        Label(std::string value, Font* font, UiElement* parent = nullptr);

};

#endif // CORE_UI_LABEL_H
