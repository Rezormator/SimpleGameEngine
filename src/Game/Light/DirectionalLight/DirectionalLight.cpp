#include "DirectionalLight.h"
#include <iostream>

GLuint DirectionalLight::currentIndex = 0;

DirectionalLight::DirectionalLight(const glm::vec3 &direction, const glm::vec3 &ambient, const glm::vec3 &diffuse,
    const glm::vec3 &specular)
        : Light("directionalLights", currentIndex, ambient, diffuse, specular), direction(direction){
}

GLvoid DirectionalLight::setDirection(const glm::vec3 &direction) {
    this->direction = direction;
}

GLvoid DirectionalLight::set(Shader *shader) {
    Light::set(shader);
    shader->setVec3((lightName + ".direction").c_str(), direction);
}
