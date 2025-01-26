#pragma once

#include <vector>
#include <assimp/scene.h>
#include "../../GameObject.h"
#include "../../../Material/Material.h"
#include "../Vertex/Vertex.h"

class Mesh final : public GameObject {
private:
    GLuint VBO;
    GLuint EBO;
    GLuint VAO;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    Material *material;
    GLvoid copyVertices(const aiMesh *mesh);
    GLvoid copyIndices(const aiMesh *mesh);
    GLvoid setupMesh();
public:
    Mesh(const aiMesh *mesh, Material *material);
    GLvoid render() const;
};
