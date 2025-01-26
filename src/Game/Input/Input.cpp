#include "Input.h"

GLFWwindow* Input::window;
GLboolean Input::firstMove;
GLfloat Input::prevXPos;
GLfloat Input::prevYPos;
GLfloat Input::xOffset;
GLfloat Input::yOffset;

GLvoid Input::setWindow(GLFWwindow *window) {
    Input::window = window;
}

GLboolean Input::getKeyPress(const GLint key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

GLfloat Input::getXOffset() {
    return xOffset;
}

GLfloat Input::getYOffset() {
    return yOffset;
}

GLvoid Input::mouseCallback(GLFWwindow *window, const GLdouble xPos, const GLdouble yPos) {
    const auto currentXPos = static_cast<GLfloat>(xPos);
    const auto currentYPos = static_cast<GLfloat>(yPos);
    if (firstMove) {
        prevXPos = currentXPos;
        prevYPos = currentYPos;
        firstMove = false;
    }
    xOffset = currentXPos - prevXPos;
    yOffset = prevYPos - currentYPos;
}
