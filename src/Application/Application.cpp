#include "Application.h"
#include "../Error/Error.h"

Game *Application::game;

GLvoid Application::initializeGLFW() {
    if (!glfwInit()) {
        Error::logMassage("GLFW", "FAILED_TO_INITIALIZE");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, DEFAULT_MAJOR_VERSION);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, DEFAULT_MINOR_VERSION);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLvoid Application::initialize() {
    initializeGLFW();
    game = new Game();
}

GLvoid Application::run() {
    game->run();
}

GLvoid Application::shut() {
    game->shut();
    delete game;
    glfwTerminate();
}
