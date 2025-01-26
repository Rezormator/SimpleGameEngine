#include "Time.h"

GLdouble Time::lastTime = 0;
GLdouble Time::deltaTime;

GLvoid Time::update() {
    const auto currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
}

GLdouble Time::getDeltaTime() {
    return deltaTime;
}
