#include "ResourceManager.h"
#include "../../Error/Error.h"

ResourceManager::ResourceManager(Shader *shader) {
    loadResources(shader);
}

ResourceManager::~ResourceManager() {
    delete defaultTexture;
    delete defaultMaterial;
}

GLvoid ResourceManager::loadResources(Shader *shader) {
    defaultTexture = new Texture(DEFAULT_TEXTURE);
    defaultMaterial = new ColorMaterial(shader);
}

Texture *ResourceManager::getDefaultTexture() const {
    return defaultTexture;
}

ColorMaterial *ResourceManager::getDefaultMaterial() const {
    return defaultMaterial;
}
