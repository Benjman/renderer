#version 410 core

layout (location = 0) in vec3 in_pos;
layout (location = 1) in vec2 in_texCoord;

out vec2 pass_texCoord;

uniform mat4 u_mvp;

void main() {
    pass_texCoord = in_texCoord;
    gl_Position = u_mvp * vec4(in_pos, 1.0);
}
