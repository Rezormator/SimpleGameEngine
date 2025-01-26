#include "ColorMaterial.h"

ColorMaterial::ColorMaterial(Shader *shader, const glm::vec3 &diffuse, const glm::vec3 &specular,
    const GLfloat shininess, const glm::vec3 &emission)
        : Material(shader, shininess, emission), diffuse(diffuse), specular(specular) {
}

GLvoid ColorMaterial::setDiffuse(const glm::vec3 &diffuse) {
    this->diffuse = diffuse;
}

GLvoid ColorMaterial::setSpecular(const glm::vec3 &specular) {
    this->specular = specular;
}

GLvoid ColorMaterial::apply() {
    Material::apply();
    shader->setVec3("material.diffuse", diffuse);
    shader->setVec3("material.specular", specular);
}
