#include "Material.h"

Material::Material(Shader *shader, const GLfloat shininess, const glm::vec3 &emission)
    : shader(shader), shininess(shininess), emission(emission) {
}

GLvoid Material::setShininess(const GLfloat shininess) {
    this->shininess = shininess;
}

GLvoid Material::setEmission(const glm::vec3 &emission) {
    this->emission = emission;
}

GLvoid Material::apply() {
    shader->use();
    shader->setFloat("material.shininess", shininess);
    shader->setVec3("material.emission", emission);
}
