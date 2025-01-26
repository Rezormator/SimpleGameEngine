#pragma once

#include "../Light.h"

class SpotLight final : public Light {
    static constexpr GLfloat LINEAR_MULTIPLIER = 4.5f;
    static constexpr GLfloat QUADRATIC_MULTIPLIER = 86.993f;
    static constexpr GLfloat CONSTANT = 1.0f;
    static constexpr glm::vec3 DEFAULT_DIRECTION {0.0f, 1.0f, 0.0f};
    static constexpr GLfloat DEFAULT_INNER_CUT_OFF = 9.0f;
    static constexpr GLfloat DEFAULT_OUTER_CUT_OFF = 12.5f;
    static constexpr GLfloat DEFAULT_RADIUS = 100.0f;
    glm::vec3 direction;
    GLfloat innerCutOff;
    GLfloat outerCutOff;
    GLfloat radius;
    GLfloat constant;
    GLfloat linear;
    GLfloat quadratic;
    static GLuint currentIndex;
    GLvoid updateTransform() override;
public:
    explicit SpotLight(const glm::vec3 &direction = DEFAULT_DIRECTION, GLfloat innerCutOff = DEFAULT_INNER_CUT_OFF,
        GLfloat outerCutOff = DEFAULT_OUTER_CUT_OFF, GLfloat radius = DEFAULT_RADIUS,
        const glm::vec3 &ambient = DEFAULT_AMBIENT, const glm::vec3 &diffuse = DEFAULT_DIFFUSE,
        const glm::vec3 &specular = DEFAULT_SPECULAR, const glm::vec3 &position = DEFAULT_POSITION,
        const glm::vec3 &rotation = DEFAULT_ROTATION);
    GLvoid setDirection(const glm::vec3 &direction);
    GLvoid setInnerCutOff(GLfloat innerCutOff);
    GLvoid setOuterCutOff(GLfloat outerCutOff);
    GLvoid setRadius(GLfloat radius);
    GLvoid set(Shader *shader) override;
};
