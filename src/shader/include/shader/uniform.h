#ifndef SHADER_UNIFORM_H
#define SHADER_UNIFORM_H

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader;

static const GLint INVALID_UNIFORM_ID = -1;

class IUniform {
    protected:
        bool _loaded = false;
        const char *_name;

        GLint _id = INVALID_UNIFORM_ID;

    public:
        explicit IUniform(const char *name) : _name(name) { }

        void storeLocation(GLuint programId);

        void storeLocation(Shader& shader);

};

template<typename T>
class Uniform : public IUniform {
    public:
        virtual void load(T value) {
            if (_loaded && _value == value) return;
            _value = value;
            doLoad();
        }

    protected:
        T _value;

        explicit Uniform(const char *name) : IUniform(name) {}

        virtual void doLoad() = 0;

};

template<typename T>
class Uniformv : public IUniform {
    public:
        virtual void load(T value) = 0;

    protected:
        explicit Uniformv(const char *name) : IUniform(name) {}

}; // class Uniformv

class Uniform1f : public Uniform<GLfloat> {
    protected:
        void doLoad() override;

}; // class Uniform1f

class Uniform2f : public Uniform<glm::vec2> {
    protected:
        void doLoad() override;

}; // class Uniform2f

class Uniform3f : public Uniform<glm::vec3> {
    protected:
        void doLoad() override;

}; // class Uniform3f

class Uniform4f : public Uniform<glm::vec4> {
    protected:
        void doLoad() override;

}; // class Uniform4f

class Uniform1i : public Uniform<int32_t> {
    protected:
        void doLoad() override;

}; // class Uniform1i

class Uniform2i : public Uniform<glm::ivec2> {
    protected:
        void doLoad() override;

}; // class Uniform2i

class Uniform3i : public Uniform<glm::ivec3> {
    protected:
        void doLoad() override;

}; // class Uniform3i

class Uniform4i : public Uniform<glm::ivec4> {
    protected:
        void doLoad() override;

}; // class Uniform4i

class Uniform1ui : public Uniform<uint32_t> {
    protected:
        void doLoad() override;

}; // class Uniform1ui

class Uniform2ui : public Uniform<glm::uvec2> {
    protected:
        void doLoad() override;

}; // class Uniform2ui

class Uniform3ui : public Uniform<glm::uvec3> {
    protected:
        void doLoad() override;

}; // class Uniform3ui

class Uniform4ui : public Uniform<glm::uvec4> {
    protected:
        void doLoad() override;

}; // class Uniform4ui

class UniformMatrix2f : public Uniformv<glm::mat2> {
    public:
        explicit UniformMatrix2f(const char *name) : Uniformv<glm::mat2>(name) {}

        void load(glm::mat2) override;

}; // class UniformMatrix2f

class UniformMatrix3f : public Uniformv<glm::mat3> {
    public:
        explicit UniformMatrix3f(const char *name) : Uniformv<glm::mat3>(name) {}

        void load(glm::mat3) override;

}; // class UniformMatrix3f

class UniformMatrix4f : public Uniformv<glm::mat4> {
    public:
        explicit UniformMatrix4f(const char *name) : Uniformv<glm::mat4>(name) {}

        void load(glm::mat4) override;

}; // class UniformMatrix4f

#endif //SHADER_UNIFORM_H

