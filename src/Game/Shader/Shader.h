#pragma once

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader {
private:
    GLuint ID;
    static std::string loadShaderCode(const char *path);
    static GLuint compileShader(const char *code, GLuint shaderType);
    GLvoid createProgram(GLuint vertShader, GLuint fragShader);
public:
    Shader(const char *vertPath, const char *fragPath);
    GLvoid use() const;
    GLvoid setBool(const char *name, GLboolean value) const;
    GLvoid setInt(const char *name, GLint value) const;
    GLvoid setFloat(const char *name, GLfloat value) const;
    GLvoid setVec3(const char *name, const glm::vec3 &value) const;
    GLvoid setMat3(const char *name, const glm::mat3 &value) const;
    GLvoid setMat4(const char *name, const glm::mat4 &value) const;
    GLvoid deleteShader() const;
};
