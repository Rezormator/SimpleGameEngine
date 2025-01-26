#include "Game.h"
#include "../Error/Error.h"
#include "../Managers/Managers.h"
#include "Input/Input.h"
#include "Scene/Scene.h"
#include "Screen/Screen.h"
#include "Time/Time.h"

Game::Game(const char *title, const GLboolean fullscreen) : window(nullptr) {
    createWindow(title, fullscreen);
    loadGLAD();
    setCallBacks();
    Managers::initializeManagers();
}

GLvoid Game::createWindow(const char *title, const GLboolean fullscreen) {
    const auto monitor = glfwGetPrimaryMonitor();
    const auto mode = glfwGetVideoMode(monitor);
    const auto width = mode->width;
    const auto height = mode->height;
    window = glfwCreateWindow(width, height, title, fullscreen ? monitor : nullptr, nullptr);
    if (!window) {
        Error::logMassage("WINDOW", "FAILED_TO_CREATE");
    }
    glfwMakeContextCurrent(window);
    Input::setWindow(window);
    Screen::update(width, height, DEFAULT_COLOR);
}

GLvoid Game::loadGLAD() {
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        Error::logMassage("GLAD", "FAILED_TO_LOAD");
    }
}

GLvoid Game::frameBufferSizeCallback(GLFWwindow *window, const GLint width, const GLint height) {
    glViewport(0, 0, width, height);
}

GLvoid Game::setCallBacks() const {
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
    glfwSetCursorPosCallback(window, Input::mouseCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

GLFWwindow *Game::getWindow() const {
    return window;
}

GLvoid Game::run() const {
    const auto scene = new Scene();
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        if (Input::getKeyPress(GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        Screen::clear();
        Time::update();

        scene->render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete scene;
}

GLvoid Game::shut() const {
    glfwDestroyWindow(window);
}
