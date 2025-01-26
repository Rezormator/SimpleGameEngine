#pragma once

#include "../Game/Game.h"

class Application {
private:
    static constexpr GLint DEFAULT_MAJOR_VERSION = 3;
    static constexpr GLint DEFAULT_MINOR_VERSION = 3;
    static Game *game;
    static GLvoid initializeGLFW();
public:
    static GLvoid initialize();
    static GLvoid run();
    static GLvoid shut();
};
