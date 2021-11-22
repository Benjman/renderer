#version 410 core

in vec4 pass_color;
in vec2 pass_uv;

out vec4 out_color;

uniform sampler2D u_text_atlas;

const vec2 NO_UV = vec2(-1.0);

void main() {
    if (NO_UV != pass_uv) {
        // text based
        out_color = vec4(texture(u_text_atlas, vec2(pass_uv.x, -pass_uv.y)).r) * pass_color;
    } else  {
        // solid color
        out_color = pass_color;
    }
}

