#include "Model.h"

#include <iostream>
#include <ostream>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include "../../../Managers/Managers.h"
#include "../../../Error/Error.h"
#include "../../Material/TextureMaterial/TextureMaterial.h"
#include <stb/stb_image.h>

Model::Model(const char *path) {
    loadModel(path);
}

GLvoid Model::loadModel(const std::string &path) {
    Assimp::Importer importer;
    const auto scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        Error::logMassage("ERROR", importer.GetErrorString());
    }
    directory = path.substr(0, path.find_last_of('/'));
    loadMaterials(scene);
}

GLvoid Model::loadMaterials(const aiScene *scene) {
    for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
        const auto materialIndex = scene->mMeshes[i]->mMaterialIndex;

        if (materials[materialIndex] != nullptr) {
            continue;
        }

        const auto mat = scene->mMaterials[scene->mMeshes[i]->mMaterialIndex];

        aiColor3D emission = {0.0f, 0.0f, 0.0f};
        float shininess = 0.0f;
        mat->Get(AI_MATKEY_COLOR_EMISSIVE, emission);
        mat->Get(AI_MATKEY_SHININESS, shininess);

        if (mat->GetTextureCount(aiTextureType_DIFFUSE) == 0) {
            aiColor3D diffuse = {0.0f, 0.0f, 0.0f};
            mat->Get(AI_MATKEY_COLOR_DIFFUSE, diffuse);
            aiColor3D specular = {0.0f, 0.0f, 0.0f};
            mat->Get(AI_MATKEY_COLOR_SPECULAR, specular);
            materials[materialIndex] = new ColorMaterial(
                Managers::getShaderManager()->getColorShader(),
                {diffuse.r, diffuse.g, diffuse.b},
                {specular.r, specular.g, specular.b},
                shininess,
                {emission.r, emission.g, emission.b});
        }
        else {
            const auto diffuse = loadMaterialTextures(mat, aiTextureType_DIFFUSE, directory);
            const auto specular = loadMaterialTextures(mat, aiTextureType_SPECULAR, directory);
            materials[materialIndex] = new TextureMaterial(
                Managers::getShaderManager()->getTextureShader(),
                diffuse, specular, shininess,
                {emission.r, emission.g, emission.b});
        }
    }
    processNode(scene->mRootNode, scene);
}

Texture *Model::loadMaterialTextures(const aiMaterial *mat, const aiTextureType type, const std::string &directory) {
    stbi_set_flip_vertically_on_load(true);
    aiString texName;
    mat->GetTexture(type, 0, &texName);
    const auto texPath = directory + "/" + texName.C_Str();
    return new Texture(texPath.c_str());
}

GLvoid Model::processNode(const aiNode *node, const aiScene *scene) {
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        const auto mesh = scene->mMeshes[node->mMeshes[i]];
        const auto materialIndex = mesh->mMaterialIndex;
        meshes.push_back(new Mesh(mesh, materials[materialIndex]));
    }
    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

GLvoid Model::updateTransform() {
    GameObject::updateTransform();
    for (const auto& mesh : meshes) {
        mesh->setModel(model);
    }
}

GLvoid Model::render() const {
    for (const auto& mesh : meshes) {
        mesh->render();
    }
}

