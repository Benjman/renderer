#version 410 core

layout (location = 0) in vec2 in_pos;
layout (location = 1) in vec2 in_texCoord;

out vec2 pass_texCoord;

void main() {
    pass_texCoord = in_texCoord;
    gl_Position = vec4(in_pos, 0.0, 1.0);
}
