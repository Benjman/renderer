#include "shader_loader.h"

#include <shader/shader.h>

void Shader::load(const char *vert, size_t vert_size, const char *frag, size_t frag_size, bool force) {
    if (id == GL_ZERO || force) {
        id = ShaderLoader::loadShader(vert, vert_size, frag, frag_size);
    }
}

void Shader::use() const {
    glUseProgram(id);
}
