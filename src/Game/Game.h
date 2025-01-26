#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../utils/utils.h"

class Game {
private:
    static constexpr auto DEFAULT_TITLE = "SimpleGameEngine";
    static constexpr GLboolean DEFAULT_FULLSCREEN = false;
    static constexpr glm::vec3 DEFAULT_COLOR = {0.1f, 0.1f, 0.1f};
    GLFWwindow *window;
    GLvoid createWindow(const char *title, GLboolean fullscreen);
    static GLvoid loadGLAD();
    static GLvoid frameBufferSizeCallback(GLFWwindow *window, GLint width, GLint height);
    GLvoid setCallBacks() const;
public:
    explicit Game(const char *title = DEFAULT_TITLE, GLboolean fullscreen = DEFAULT_FULLSCREEN);
    NODISCARD GLFWwindow *getWindow() const;
    GLvoid run() const;
    GLvoid shut() const;
};
