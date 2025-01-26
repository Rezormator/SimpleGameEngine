#pragma once

#include <vector>
#include <map>
#include <string>
#include <assimp/scene.h>
#include "../GameObject.h"
#include "Mesh/Mesh.h"
#include "../../Material/Material.h"
#include "../../Texture/Texture.h"

class Model final : public GameObject {
private:
    std::vector<Mesh *> meshes;
    std::map<GLuint, Material *> materials;
    std::string directory;
    GLvoid loadModel(const std::string &path);
    GLvoid loadMaterials(const aiScene *scene);
    GLvoid processNode(const aiNode* node, const aiScene* scene);
    static Texture *loadMaterialTextures(const aiMaterial *mat, aiTextureType type, const std::string &directory);
    GLvoid updateTransform() override;
public:
    explicit Model(const char* path);
    GLvoid render() const;
};
