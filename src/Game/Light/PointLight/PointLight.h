#pragma once

#include "../Light.h"

class PointLight final : public Light {
    static constexpr GLfloat LINEAR_MULTIPLIER = 4.5f;
    static constexpr GLfloat QUADRATIC_MULTIPLIER = 86.993f;
    static constexpr GLfloat CONSTANT = 1.0f;
    static constexpr GLfloat DEFAULT_RADIUS = 100.0f;
    GLfloat radius;
    GLfloat constant;
    GLfloat linear;
    GLfloat quadratic;
    static GLuint currentIndex;
    GLvoid updateTransform() override;
public:
    explicit PointLight(GLfloat radius = DEFAULT_RADIUS, const glm::vec3 &ambient = DEFAULT_AMBIENT,
        const glm::vec3 &diffuse = DEFAULT_DIFFUSE, const glm::vec3 &specular = DEFAULT_SPECULAR,
        const glm::vec3 &position = DEFAULT_POSITION, const glm::vec3 &rotation = DEFAULT_ROTATION);
    GLvoid setRadius(GLfloat radius);
    GLvoid set(Shader *shader) override;
};
