#ifndef UI_DEMO_ELEMENTS_H
#define UI_DEMO_ELEMENTS_H

#include "core/ui/ui_fonts.h"
#include <core/colors.h>
#include <core/ui.h>

struct UiDemoElements {
    UiElement top_bar = UiElement::create()
        .background_color(BlueGray300)
        .pos(0, 0)
        .size(window::width(), 30);

    UiElement bottom_bar = UiElement::create()
        .background_color(BlueGray300)
        .pos(0, window::height() - 230)
        .size(window::width(), 200);

    /*
     * Button
     */
    UiElement button_base = UiElement::create()
        .pos(100, 100)
        .renderable(false);

    UiElement button_bg = UiElement::create(&button_base)
        .size(120, 30)
        .background_color(GreenA700);


    Label label = Label("T", fonts::DejaVuSans());

};

#endif // UI_DEMO_ELEMENTS_H
