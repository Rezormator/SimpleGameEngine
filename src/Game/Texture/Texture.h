#pragma once

#include <glad/glad.h>

class Texture {
private:
    static constexpr GLint DEFAULT_WRAP = GL_REPEAT;
    static constexpr GLint DEFAULT_FILTRATION = GL_LINEAR;
    GLuint ID;
    GLint width;
    GLint height;
    GLvoid createTexture(GLint wrap, GLint filtration);
    GLvoid loadTexture(const char *texturePath);
    GLvoid deleteTexture() const;
public:
    explicit Texture(const char *texturePath, GLint wrap = DEFAULT_WRAP, GLint filtration = DEFAULT_FILTRATION);
    ~Texture();
    GLvoid bind() const;
};
