#pragma once

#include "../Material.h"
#include "../../Texture/Texture.h"

class TextureMaterial final : public Material {
private:
    Texture* diffuse;
    Texture* specular;
public:
    TextureMaterial(Shader *shader, Texture* diffuse, Texture* specular,
        GLfloat shininess = DEFAULT_SHININESS, const glm::vec3 &emission = DEFAULT_EMISSION);
    GLvoid setDiffuse(Texture* diffuse);
    GLvoid setSpecular(Texture* specular);
    GLvoid apply() override;
};
