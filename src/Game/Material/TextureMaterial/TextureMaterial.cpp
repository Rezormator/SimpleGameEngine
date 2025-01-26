#include "TextureMaterial.h"

TextureMaterial::TextureMaterial(Shader *shader, Texture *diffuse, Texture *specular,
    const GLfloat shininess, const glm::vec3 &emission)
        : Material(shader, shininess, emission), diffuse(diffuse), specular(specular) {
}

GLvoid TextureMaterial::setDiffuse(Texture *diffuse) {
    this->diffuse = diffuse;
}

GLvoid TextureMaterial::setSpecular(Texture *specular) {
    this->specular = specular;
}

GLvoid TextureMaterial::apply() {
    Material::apply();
    shader->setInt("material.diffuse", 0);
    glActiveTexture(GL_TEXTURE0);
    diffuse->bind();
    shader->setInt("material.specular", 1);
    glActiveTexture(GL_TEXTURE1);
    specular->bind();
}
