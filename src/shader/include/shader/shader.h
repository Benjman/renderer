#ifndef SHADER_SHADER_H
#define SHADER_SHADER_H

#include <GL/gl.h>
#include <cstddef> // size_t

class Vao;

struct Shader {
    public:
        Shader() = default;

        void load(const char* vert, size_t vert_size, const char* frag, size_t frag_size, bool force = false);

        void use() const;

        void initialize() {
            use();
            loadUniforms();
        }

        GLuint getId() const { return id; }

    protected:
        friend class ShaderLoader;

        GLuint id = GL_ZERO;

        virtual void loadUniforms() {}
};

#endif // SHADER_SHADER_H
