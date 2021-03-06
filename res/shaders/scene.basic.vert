#version 410 core

layout (location = 0) in vec3 in_pos;

uniform mat4 mvp_matrix;

void main() {
    gl_Position = mvp_matrix * vec4(in_pos, 1.0);
}

