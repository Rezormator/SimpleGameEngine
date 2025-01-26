#include "Screen.h"

GLfloat Screen::width;
GLfloat Screen::height;
glm::vec4 Screen::color;

GLvoid Screen::update(const GLint width, const GLint height, const glm::vec3 &color) {
    Screen::width = static_cast<GLfloat>(width);
    Screen::height = static_cast<GLfloat>(height);
    setColor(color);
}

GLvoid Screen::setColor(const glm::vec3 &color) {
    Screen::color = glm::vec4(color, 1.0f);
}

GLvoid Screen::clear() {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GLfloat Screen::getWidth() {
    return width;
}

GLfloat Screen::getHeight() {
    return height;
}

glm::vec4 Screen::getColor() {
    return color;
}

GLfloat Screen::getAspectRatio() {
    return width / height;
}
