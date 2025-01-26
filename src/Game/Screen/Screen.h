#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "../../utils/utils.h"

class Screen {
private:
    static GLfloat width;
    static GLfloat height;
    static glm::vec4 color;
public:
    static GLvoid update(GLint width, GLint height, const glm::vec3 &color);
    static GLvoid setColor(const glm::vec3 &color);
    static GLvoid clear();
    NODISCARD static GLfloat getWidth();
    NODISCARD static GLfloat getHeight();
    NODISCARD static glm::vec4 getColor();
    NODISCARD static GLfloat getAspectRatio();
};
