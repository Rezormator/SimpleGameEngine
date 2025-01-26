#pragma once

#include "../Shader/Shader.h"

class Material {
protected:
    static constexpr GLfloat DEFAULT_SHININESS = 0;
    static constexpr glm::vec3 DEFAULT_EMISSION {0.0f};
    Shader *shader;
    GLfloat shininess;
    glm::vec3 emission;
public:
    Material(Shader *shader, GLfloat shininess, const glm::vec3 &emission);
    virtual ~Material() = default;
    GLvoid setShininess(GLfloat shininess);
    GLvoid setEmission(const glm::vec3 &emission);
    virtual GLvoid apply();
};
