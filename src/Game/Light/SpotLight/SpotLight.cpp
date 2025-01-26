#include "SpotLight.h"

GLuint SpotLight::currentIndex = 0;

SpotLight::SpotLight(const glm::vec3 &direction, const GLfloat innerCutOff, const GLfloat outerCutOff, const GLfloat radius,
    const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular,
    const glm::vec3 &position, const glm::vec3 &rotation)
        : Light("spotLights", currentIndex, ambient, diffuse, specular, position, rotation),
        direction(direction), innerCutOff(glm::cos(glm::radians(innerCutOff))),
        outerCutOff(glm::cos(glm::radians(outerCutOff))), radius(radius) {
    updateTransform();
}

GLvoid SpotLight::setDirection(const glm::vec3 &direction) {
    this->direction = direction;
}

GLvoid SpotLight::setInnerCutOff(const GLfloat innerCutOff) {
    this->innerCutOff = glm::cos(glm::radians(innerCutOff));
}

GLvoid SpotLight::setOuterCutOff(const GLfloat outerCutOff) {
    this->outerCutOff = glm::cos(glm::radians(outerCutOff));
}

GLvoid SpotLight::setRadius(const GLfloat radius) {
    this->radius = radius;
    updateTransform();
}

GLvoid SpotLight::updateTransform() {
    GameObject::updateTransform();
    constant = CONSTANT;
    linear = LINEAR_MULTIPLIER / radius;
    quadratic = QUADRATIC_MULTIPLIER / (radius * radius);
}

GLvoid SpotLight::set(Shader *shader) {
    Light::set(shader);
    shader->setVec3((lightName + ".position").c_str(), position);
    shader->setFloat((lightName + ".constant").c_str(), constant);
    shader->setFloat((lightName + ".linear").c_str(), linear);
    shader->setFloat((lightName + ".quadratic").c_str(), quadratic);
    shader->setFloat((lightName + ".innerCutOff").c_str(), innerCutOff);
    shader->setFloat((lightName + ".outerCutOff").c_str(), outerCutOff);
    shader->setVec3((lightName + ".direction").c_str(), direction);
}
