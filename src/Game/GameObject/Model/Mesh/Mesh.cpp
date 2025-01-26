#include "Mesh.h"

Mesh::Mesh(const aiMesh *mesh, Material *material) {
    copyVertices(mesh);
    copyIndices(mesh);
    this->material = material;
    setupMesh();
}

void Mesh::copyVertices(const aiMesh *mesh) {
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        vertex.setPosition(mesh->mVertices[i]);
        if (mesh->mNormals) {
            vertex.setNormal(mesh->mNormals[i]);
        }
        if (mesh->mTextureCoords[0]) {
            vertex.setTexCoords(mesh->mTextureCoords[0][i]);
        }
        vertices.push_back(vertex);
    }
}

void Mesh::copyIndices(const aiMesh *mesh) {
    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        const auto face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }
}

GLvoid Mesh::setupMesh() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)),
        &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(indices.size() * sizeof(unsigned int)),
        &indices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
        reinterpret_cast<void *>(0));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
        reinterpret_cast<void *>(offsetof(Vertex, normal)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
        reinterpret_cast<void *>(offsetof(Vertex, texCoords)));
    glBindVertexArray(0);
}

GLvoid Mesh::render() const {
    material->apply();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}