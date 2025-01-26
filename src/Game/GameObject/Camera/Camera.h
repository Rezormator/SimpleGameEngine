#pragma once

#include "../GameObject.h"
#include "../../Shader/Shader.h"

class Camera final : public GameObject {
    static constexpr glm::vec3 WORLD_UP {0.0f, 1.0f, 0.0f};
    static constexpr GLfloat DEFAULT_FOV = 45.0f;
    static constexpr GLfloat DEFAULT_NEAR_CLIP = 0.1f;
    static constexpr GLfloat DEFAULT_FAR_CLIP = 100.0f;
    static constexpr GLdouble MOVEMENT_SPEED = 1.0;
    static constexpr GLfloat SENSITIVITY = 0.001f;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    GLfloat fov;
    glm::mat4 view;
    glm::mat4 projection;
    GLdouble movementSpeed;
    GLvoid updateTransform() override;
    GLvoid processInput();
    GLvoid processMouseInput();
public:
    explicit Camera(GLfloat fov = DEFAULT_FOV, const glm::vec3 &position = DEFAULT_POSITION,
        const glm::vec3 &rotation = DEFAULT_ROTATION, GLfloat movementSpeed = MOVEMENT_SPEED);
    ~Camera() override = default;
    GLvoid setFov(GLfloat fov);
    GLvoid setMovementSpeed(GLfloat movementSpeed);
    NODISCARD glm::mat4 getViewMat() const;
    NODISCARD glm::mat4 getProjectionMat() const;
    NODISCARD glm::mat3 getNormalMat() const;
    NODISCARD glm::vec3 getFront() const;
    GLvoid set(const Shader *shader) const;
};

