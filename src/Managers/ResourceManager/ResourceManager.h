#pragma once

#include <glad/glad.h>
#include "../../Game/Texture/Texture.h"
#include "../../Game/Material/ColorMaterial/ColorMaterial.h"
#include "../../utils/utils.h"

class ResourceManager {
private:
    static constexpr auto DEFAULT_TEXTURE = "../resources/textures/default.png";
    Texture *defaultTexture;
    ColorMaterial *defaultMaterial;
    GLvoid loadResources(Shader *shader);
public:
    explicit ResourceManager(Shader *shader);
    ~ResourceManager();
    NODISCARD Texture *getDefaultTexture() const;
    NODISCARD ColorMaterial *getDefaultMaterial() const;
};
