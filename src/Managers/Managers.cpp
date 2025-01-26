#include "Managers.h"

ShaderManager * Managers::shaderManager;
ResourceManager * Managers::resourceManager;

GLvoid Managers::initializeManagers() {
    shaderManager = new ShaderManager();
    resourceManager = new ResourceManager(shaderManager->getColorShader());
}

ShaderManager *Managers::getShaderManager() {
    return shaderManager;
}

ResourceManager *Managers::getResourceManager() {
    return resourceManager;
}

GLvoid Managers::shut() {
    delete shaderManager;
    delete resourceManager;
}