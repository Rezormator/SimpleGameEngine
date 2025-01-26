#pragma once

#include <GLFW/glfw3.h>
#include "../../utils/utils.h"

class Input {
private:
    static GLFWwindow *window;
    static GLboolean firstMove;
    static GLfloat prevXPos;
    static GLfloat prevYPos;
    static GLfloat xOffset;
    static GLfloat yOffset;
public:
    static GLvoid setWindow(GLFWwindow *window);
    NODISCARD static GLboolean getKeyPress(GLint key);
    NODISCARD static GLfloat getXOffset();
    NODISCARD static GLfloat getYOffset();
    static GLvoid mouseCallback(GLFWwindow *window, GLdouble xPos, GLdouble yPos);
};
