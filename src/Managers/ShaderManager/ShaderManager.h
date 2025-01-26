#pragma once

#include "../../Game/Shader/Shader.h"
#include "../../utils/Utils.h"

class ShaderManager {
    static constexpr auto COLOR_VERT_SHADER = "../resources/shaders/colorShader.vert";
    static constexpr auto COLOR_FRAG_SHADER = "../resources/shaders/colorShader.frag";
    static constexpr auto TEXTURE_VERT_SHADER = "../resources/shaders/textureShader.vert";
    static constexpr auto TEXTURE_FRAG_SHADER = "../resources/shaders/textureShader.frag";
    Shader *colorShader;
    Shader *textureShader;
    GLvoid loadShaders();
public:
    ShaderManager();
    ~ShaderManager();
    NODISCARD Shader *getColorShader() const;
    NODISCARD Shader *getTextureShader() const;
};
