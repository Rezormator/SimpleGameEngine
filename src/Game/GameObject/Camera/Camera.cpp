#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/matrix_inverse.hpp>
#include "../../Screen/Screen.h"
#include "../../Input/Input.h"
#include "../../Time/Time.h"

Camera::Camera(const GLfloat fov, const glm::vec3 &position, const glm::vec3 &rotation, const GLfloat movementSpeed)
    : GameObject(position, rotation), front(0.0f, 0.0f, -1.0f), up(WORLD_UP), worldUp(WORLD_UP), fov(0.0),
    view(1.0f), projection(1.0f), movementSpeed(movementSpeed) {
    setFov(fov);
}

GLvoid Camera::updateTransform() {
    processInput();
    processMouseInput();
    GameObject::updateTransform();
    front.x = glm::sin(rotation.y) * glm::cos(rotation.x);
    front.y = glm::sin(rotation.x);
    front.z = glm::cos(rotation.y) * glm::cos(rotation.x);
    front = glm::normalize(front);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
    view = glm::lookAt(position, position + front, up);
    projection = glm::perspective(fov, Screen::getAspectRatio(), DEFAULT_NEAR_CLIP, DEFAULT_FAR_CLIP);
}

GLvoid Camera::processInput() {
    auto movementSpeed = static_cast<GLfloat>(this->movementSpeed * Time::getDeltaTime());

    if (Input::getKeyPress(GLFW_KEY_LEFT_CONTROL))
        movementSpeed *= 2.0f;
    if (Input::getKeyPress(GLFW_KEY_W))
        position += front * movementSpeed;
    if (Input::getKeyPress(GLFW_KEY_S))
        position -= front * movementSpeed;
    if (Input::getKeyPress(GLFW_KEY_A))
        position -= right * movementSpeed;
    if (Input::getKeyPress(GLFW_KEY_D))
        position += right * movementSpeed;
    if (Input::getKeyPress(GLFW_KEY_SPACE))
        position = glm::vec3(position.x, position.y + movementSpeed, position.z);
    if (Input::getKeyPress(GLFW_KEY_LEFT_SHIFT))
        position = glm::vec3(position.x, position.y - movementSpeed, position.z);
}

GLvoid Camera::processMouseInput() {
    rotation.x = Input::getYOffset() * SENSITIVITY;
    rotation.y = Input::getXOffset() * -SENSITIVITY;
    if (rotation.x > 1.5533f) {
        rotation.x = 1.5533f;
    }
    if (rotation.x < -1.5533f) {
        rotation.x = -1.5533f;
    }
}


GLvoid Camera::setFov(const GLfloat fov) {
    this->fov = glm::radians(fov);
}

GLvoid Camera::setMovementSpeed(const GLfloat movementSpeed) {
    this->movementSpeed = movementSpeed;
}

glm::mat4 Camera::getViewMat() const {
    return view;
}

glm::mat4 Camera::getProjectionMat() const {
    return projection;
}

glm::mat3 Camera::getNormalMat() const {
    return glm::inverseTranspose(glm::mat3(model));
}

glm::vec3 Camera::getFront() const {
    return front;
}

GLvoid Camera::set(const Shader *shader) const {
    shader->use();
    shader->setMat3("matNormal", getNormalMat());
    shader->setVec3("viewPos", getPosition());
    shader->setMat4("view", getViewMat());
    shader->setMat4("projection", getProjectionMat());
}
