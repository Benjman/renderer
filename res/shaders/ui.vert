#version 410 core

layout (location = 0) in vec2 in_pos;
layout (location = 1) in vec4 in_color;
layout (location = 2) in vec2 in_uv;

out vec4 pass_color;
out vec2 pass_uv;

void main() {
    pass_color = in_color;
    pass_uv = in_uv;
    gl_Position = vec4(in_pos, 0.0, 1.0);
}

