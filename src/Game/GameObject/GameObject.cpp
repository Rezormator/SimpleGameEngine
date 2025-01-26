#include "GameObject.h"
#include <glm/gtc/matrix_transform.hpp>

GameObject::GameObject(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale)
    : position(position), rotation(rotation), scale(scale) {
    GameObject::updateTransform();
}

GLvoid GameObject::setPosition(const glm::vec3 &position) {
    this->position = position;
    updateTransform();
}

GLvoid GameObject::setRotation(const glm::vec3 &rotation) {
    this->rotation = rotation;
    updateTransform();
}

GLvoid GameObject::setScale(const glm::vec3 &scale) {
    this->scale = scale;
    updateTransform();
}

glm::mat4 GameObject::getModel() const {
    return model;
}

glm::vec3 GameObject::getPosition() const {
    return position;
}

glm::vec3 GameObject::getRotation() const {
    return rotation;
}

glm::vec3 GameObject::getScale() const {
    return scale;
}

GLvoid GameObject::updateTransform() {
    model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation.x), X_AXIS);
    model = glm::rotate(model, glm::radians(rotation.y), Y_AXIS);
    model = glm::rotate(model, glm::radians(rotation.z), Z_AXIS);
    model = glm::scale(model, scale);
}

GLvoid GameObject::update() {
    updateTransform();
}
