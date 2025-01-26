#pragma once

#include <glad/glad.h>
// #include "../../Game/Texture2D/Texture2D.h"
#include "../../utils/utils.h"

class ResourceManager {
private:
    static constexpr auto DEFAULT_TEXTURE = "../resources/textures/white.png";
public:
    ResourceManager();
    ~ResourceManager();
    GLvoid loadResources();
    // NODISCARD Texture2D *getDefaultTexture();
    // NODISCARD ColorMaterial
};
