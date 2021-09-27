#ifndef SHADER_SHADER_H
#define SHADER_SHADER_H

#include <gl.h>

class Vao;

struct Shader {
public:
  friend class ShaderLoader;

  static Shader createShader(const char* vert, size_t vert_size, const char* frag, size_t frag_size);

  void use() const;

  void initialize() {
    use();
    loadUniforms();
  }

protected:
  const GLuint id;

  virtual void loadUniforms() {}

private:
  Shader(const GLuint id) : id(id) {}
};

#endif // SHADER_SHADER_H
