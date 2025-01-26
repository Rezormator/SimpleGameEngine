#include "Texture.h"
#include "../../Error/Error.h"
#include <stb/stb_image.h>

Texture::Texture(const char *texturePath, const GLint wrap, const GLint filtration) : ID(0), width(0), height(0) {
    createTexture(wrap, filtration);
    loadTexture(texturePath);
}

Texture::~Texture() {
    deleteTexture();
}

GLvoid Texture::createTexture(const GLint wrap, const GLint filtration) {
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtration);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtration);
}

GLvoid Texture::loadTexture(const char *texturePath) {
    GLint numChannels;
    const auto data = stbi_load(texturePath, &width, &height, &numChannels, 0);
    if (!data) {
        Error::logMassage("TEXTURE", "FAILED_TO_LOAD", false);
    }
    const auto format = numChannels == 1 ? GL_RED : numChannels == 3 ? GL_RGB : GL_RGBA;
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

GLvoid Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, ID);
}

GLvoid Texture::deleteTexture() const {
    glDeleteTextures(1, &ID);
}