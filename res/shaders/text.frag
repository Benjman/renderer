#version 410 core

in vec2 pass_texCoord;
out vec4 out_color;

uniform sampler2D u_tex;

void main() {
    out_color = vec4(texture(u_tex, vec2(pass_texCoord.x, -pass_texCoord.y)).r);
}
