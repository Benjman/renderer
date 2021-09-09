#ifndef SHADER_SHADER_H
#define SHADER_SHADER_H

#include <gl.h>

#include <string>

class Vao;

struct Shader {
public:
  friend class ShaderLoader;

  static Shader createShader(std::string& vert, std::string& frag);

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
