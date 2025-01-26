#include "Light.h"

#include "../../Managers/Managers.h"

Light::Light(const std::string &lightName, GLuint &currentIndex,
             const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular,
             const glm::vec3 &position, const glm::vec3 &rotation)
        : GameObject(position, rotation), ambient(ambient), diffuse(diffuse), specular(specular) {
    this->lightName = lightName + "[" + std::to_string(currentIndex) + "]";
    currentIndex++;
}

GLvoid Light::setAmbient(const glm::vec3 &ambient) {
    this->ambient = ambient;
}

GLvoid Light::setDiffuse(const glm::vec3 &diffuse) {
    this->diffuse = diffuse;
}

GLvoid Light::setSpecular(const glm::vec3 &specular) {
    this->specular = specular;
}

GLvoid Light::set(Shader *shader) {
    shader->use();
    shader->setVec3((lightName + ".ambient").c_str(), ambient);
    shader->setVec3((lightName + ".diffuse").c_str(), diffuse);
    shader->setVec3((lightName + ".specular").c_str(), specular);
}
