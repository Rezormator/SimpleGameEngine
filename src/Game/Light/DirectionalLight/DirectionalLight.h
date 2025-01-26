#pragma once

#include "../Light.h"

class DirectionalLight final : public Light {
    static constexpr glm::vec3 DEFAULT_DIRECTION = {-0.2f, -1.0f, -0.3f};
    glm::vec3 direction;
    static GLuint currentIndex;
public:
    explicit DirectionalLight(const glm::vec3 &direction = DEFAULT_DIRECTION, const glm::vec3 &ambient = DEFAULT_AMBIENT,
        const glm::vec3 &diffuse = DEFAULT_DIFFUSE, const glm::vec3 &specular = DEFAULT_SPECULAR);
    GLvoid setDirection(const glm::vec3 &direction);
    GLvoid set(Shader *shader) override;
};
