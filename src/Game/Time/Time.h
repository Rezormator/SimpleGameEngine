#pragma once

#include <GLFW/glfw3.h>
#include "../../utils/utils.h"

class Time {
private:
    static GLdouble lastTime;
    static GLdouble deltaTime;
public:
    static GLvoid update();
    NODISCARD static GLdouble getDeltaTime();
};
