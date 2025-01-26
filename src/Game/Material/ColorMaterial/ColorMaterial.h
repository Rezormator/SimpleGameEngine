#pragma once

#include "../Material.h"

class ColorMaterial final : public  Material {
private:
    static constexpr glm::vec3 DEFAULT_DIFFUSE {0.8f};
    static constexpr glm::vec3 DEFAULT_SPECULAR {0.8f};
    glm::vec3 diffuse;
    glm::vec3 specular;
public:
    ColorMaterial(Shader *shader,
        const glm::vec3 &diffuse = DEFAULT_DIFFUSE, const glm::vec3 &specular = DEFAULT_SPECULAR,
        GLfloat shininess = DEFAULT_SHININESS, const glm::vec3 &emission = DEFAULT_EMISSION);
    GLvoid setDiffuse(const glm::vec3 &diffuse);
    GLvoid setSpecular(const glm::vec3 &specular);
    GLvoid apply() override;
};
