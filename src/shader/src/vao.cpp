#define GLFW_INCLUDE_NONE
#include <glad/glad.h>

#include <shader/vao.h>
#include <shader/vertex_attribute.h>

Vao::Vao() {
    glGenVertexArrays(1, &id);
}

GLuint Vao::findBoundVertexArray() {
    GLint id = GL_ZERO;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &id);
    return id;
}

Vao::~Vao() {
    if (Vao::findBoundVertexArray() == id)
        unbind();

    for (auto attribute : attributes) {
        attribute->disable();
        delete attribute;
    }

    glDeleteVertexArrays(1, &id);
}

void Vao::bind() {
    glBindVertexArray(id);
}

void Vao::unbind() {
    glBindVertexArray(0);
}

VertexAttribute *Vao::createAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *offset) {
    bind();
    auto *attrib = new VertexAttribute(index, size, type, normalized, stride, offset);
    attributes.emplace_back(attrib);
    return attrib;
}

