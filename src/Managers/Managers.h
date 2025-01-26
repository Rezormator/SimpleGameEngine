#pragma once

#include "ShaderManager/ShaderManager.h"
#include "ResourceManager/ResourceManager.h"

class Managers {
private:
    static ShaderManager *shaderManager;
    static ResourceManager *resourceManager;
public:
    static GLvoid initializeManagers();
    NODISCARD static ShaderManager *getShaderManager();
    NODISCARD static ResourceManager *getResourceManager();
    static GLvoid shut();
};
