#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "../../utils/utils.h"

class GameObject {
protected:
    static constexpr glm::vec3 DEFAULT_POSITION {0.0f};
    static constexpr glm::vec3 DEFAULT_ROTATION {0.0f};
    static constexpr glm::vec3 DEFAULT_SCALE {1.0f};
    static constexpr glm::vec3 X_AXIS {1.0f, 0.0f, 0.0f};
    static constexpr glm::vec3 Y_AXIS {0.0f, 1.0f, 0.0f};
    static constexpr glm::vec3 Z_AXIS {0.0f, 0.0f, 1.0f};
    glm::mat4 model;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    virtual GLvoid updateTransform();
public:
    explicit GameObject(const glm::vec3 &position = DEFAULT_POSITION,
        const glm::vec3 &rotation = DEFAULT_ROTATION,
        const glm::vec3 &scale = DEFAULT_SCALE);
    virtual ~GameObject() = default;
    GLvoid setPosition(const glm::vec3 &position);
    GLvoid setRotation(const glm::vec3 &rotation);
    GLvoid setScale(const glm::vec3 &scale);
    NODISCARD glm::mat4 getModel() const;
    NODISCARD glm::vec3 getPosition() const;
    NODISCARD glm::vec3 getRotation() const;
    NODISCARD glm::vec3 getScale() const;
    GLvoid update();
};
