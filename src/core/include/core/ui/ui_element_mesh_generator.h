#ifndef CORE_UI_UI_ELEMENT_MESH_GENERATOR_H
#define CORE_UI_UI_ELEMENT_MESH_GENERATOR_H

#include <core/ui/ui_element.h>
#include <core/window.h>
#include <core/math.h>

#include <text/text.h>
#include <text/generator.h>

class UiElementMeshGenerator {
    public:
        /**
         * Describes the number of floats each vertex contains.
         * Currently the following elements are in a vertex, and in this order:
         *  1) position.xy
         *  2) color.rgb
         *  3) uv.st
         */
        static const size_t ELEMENTS_PER_VERTEX = 7;

        static size_t generate(UiElement* el, float_t* vert_buf, uint32_t* idx_buf, size_t idx_pointer) {
            glm::vec2 pos = el->screen_pos();
            // TODO anchoring

            if (!el->text().value().empty()) {
                TextMeshContext context(&el->text());
                context.display_height = window::height();
                context.display_width = window::width();
                context.idx_buffer = idx_buf;
                context.idx_offset = idx_pointer * 4;
                context.vertex_buffer = vert_buf;
                context.color = glm::vec3(el->background_color());

                context.add_attrib(TextAttribPosition, TextAttribute(2, 7, 0));
                context.add_attrib(TextAttribUV, TextAttribute(2, 7, 2));
                context.add_attrib(TextAttribColor, TextAttribute(3, 7, 4));

                size_t quad_count = el->text().generate_mesh(context);
                el->text().update_metadata();

                return quad_count;
            }


            float_t pos_x_min = pos.x;
            float_t pos_x_max = pos.x + el->size().x;
            float_t pos_y_min = pos.y;
            float_t pos_y_max = pos.y + el->size().y;

            // scale to screen
            pos_x_min /= window::width();
            pos_x_max /= window::width();
            pos_y_min /= window::height();
            pos_y_max /= window::height();

            // convert to ndc
            pos_x_min =  math::map(pos_x_min, 0.0f, 1.0f, -1.0f, 1.0f);
            pos_x_max =  math::map(pos_x_max, 0.0f, 1.0f, -1.0f, 1.0f);
            pos_y_min = -math::map(pos_y_min, 0.0f, 1.0f, -1.0f, 1.0f);
            pos_y_max = -math::map(pos_y_max, 0.0f, 1.0f, -1.0f, 1.0f);

            vert_buf[0]  = pos_x_min;                   /* vertex 1     position.x   */
            vert_buf[1]  = pos_y_min;                   /*              position.y   */
            vert_buf[2]  = -1.0;                        /*              uv.x         */
            vert_buf[3]  = -1.0;                        /*              uv.y         */
            vert_buf[4]  = el->background_color().r;    /*              color.r      */
            vert_buf[5]  = el->background_color().g;    /*              color.g      */
            vert_buf[6]  = el->background_color().b;    /*              color.b      */
            vert_buf[7]  = pos_x_min;                   /* vertex 2     position.x   */
            vert_buf[8]  = pos_y_max;                   /*              position.y   */
            vert_buf[9]  = -1.0;                        /*              uv.x         */
            vert_buf[10] = -1.0;                        /*              uv.y         */
            vert_buf[11] = el->background_color().r;    /*              color.r      */
            vert_buf[12] = el->background_color().g;    /*              color.g      */
            vert_buf[13] = el->background_color().b;    /*              color.b      */
            vert_buf[14] = pos_x_max;                   /* vertex 3     position.x   */
            vert_buf[15] = pos_y_max;                   /*              position.y   */
            vert_buf[16] = -1.0;                        /*              uv.x         */
            vert_buf[17] = -1.0;                        /*              uv.y         */
            vert_buf[18] = el->background_color().r;    /*              color.r      */
            vert_buf[19] = el->background_color().g;    /*              color.g      */
            vert_buf[20] = el->background_color().b;    /*              color.b      */
            vert_buf[21] = pos_x_max;                   /* vertex 4     position.x   */
            vert_buf[22] = pos_y_min;                   /*              position.y   */
            vert_buf[23] = -1.0;                        /*              uv.x         */
            vert_buf[24] = -1.0;                        /*              uv.y         */
            vert_buf[25] = el->background_color().r;    /*              color.r      */
            vert_buf[26] = el->background_color().g;    /*              color.g      */
            vert_buf[27] = el->background_color().b;    /*              color.b      */

            idx_buf[0] = 0 + idx_pointer * 4;
            idx_buf[1] = 1 + idx_pointer * 4;
            idx_buf[2] = 3 + idx_pointer * 4;
            idx_buf[3] = 1 + idx_pointer * 4;
            idx_buf[4] = 2 + idx_pointer * 4;
            idx_buf[5] = 3 + idx_pointer * 4;

            return 1;
        }

    private:
        const UiElement* element;

};

#endif // CORE_UI_UI_ELEMENT_MESH_GENERATOR_H
