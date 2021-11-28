#version 410 core

layout (location = 0) in vec2 in_pos;
layout (location = 1) in vec2 in_uv;
layout (location = 2) in vec3 in_color;

out vec4 pass_color;
out vec2 pass_uv;

void main() {
    pass_uv = in_uv;
    pass_color = vec4(in_color, 1.0);
    gl_Position = vec4(in_pos, 0.0, 1.0);
}

