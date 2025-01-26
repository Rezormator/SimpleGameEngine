#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "../GameObject/GameObject.h"
#include "../Shader/Shader.h"

class Light : public GameObject {
protected:
    static constexpr glm::vec3 DEFAULT_AMBIENT {0.2f};
    static constexpr glm::vec3 DEFAULT_DIFFUSE {0.5f};
    static constexpr glm::vec3 DEFAULT_SPECULAR {0.5f};
private:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
protected:
    std::string lightName;
public:
    Light(const std::string &lightName, GLuint &currentIndex,
        const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular,
        const glm::vec3 &position = DEFAULT_POSITION, const glm::vec3 &rotation = DEFAULT_ROTATION);
    GLvoid setAmbient(const glm::vec3 &ambient);
    GLvoid setDiffuse(const glm::vec3 &diffuse);
    GLvoid setSpecular(const glm::vec3 &specular);
    virtual GLvoid set(Shader *shader) = 0;
};
