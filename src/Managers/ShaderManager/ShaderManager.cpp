#include "ShaderManager.h"
#include <ranges>
#include "../../Error/Error.h"

ShaderManager::ShaderManager() {
    loadShaders();
}

ShaderManager::~ShaderManager() {
    delete colorShader;
    delete textureShader;
}

GLvoid ShaderManager::loadShaders() {
    colorShader = new Shader(COLOR_VERT_SHADER, COLOR_FRAG_SHADER);
    textureShader = new Shader(TEXTURE_VERT_SHADER, TEXTURE_FRAG_SHADER);
}

Shader *ShaderManager::getColorShader() const {
    if (colorShader == nullptr) {
        Error::logMassage("COLOR_SHADER_MANAGER", "NULLPTR");
    }
    return this->colorShader;
}

Shader *ShaderManager::getTextureShader() const {
    if (textureShader == nullptr) {
        Error::logMassage("TEXTURE_SHADER_MANAGER", "NULLPTR");
    }
    return this->textureShader;
}
