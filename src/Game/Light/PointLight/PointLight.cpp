#include "PointLight.h"
#include <iostream>

GLuint PointLight::currentIndex = 0;

PointLight::PointLight(const GLfloat radius, const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular,
    const glm::vec3 &position, const glm::vec3 &rotation)
        : Light("pointLights", currentIndex, ambient, diffuse, specular, position, rotation), radius(radius) {
    PointLight::updateTransform();
}

GLvoid PointLight::setRadius(const GLfloat radius) {
    this->radius = radius;
    PointLight::updateTransform();
}

GLvoid PointLight::updateTransform() {
    GameObject::updateTransform();
    constant = CONSTANT;
    linear = LINEAR_MULTIPLIER / radius;
    quadratic = QUADRATIC_MULTIPLIER / (radius * radius);
}

GLvoid PointLight::set(Shader *shader) {
    Light::set(shader);
    shader->setVec3((lightName + ".position").c_str(), position);
    shader->setFloat((lightName + ".constant").c_str(), constant);
    shader->setFloat((lightName + ".linear").c_str(), linear);
    shader->setFloat((lightName + ".quadratic").c_str(), quadratic);
}
