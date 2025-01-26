#include "Shader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>
#include "../../Error/Error.h"

Shader::Shader(const char *vertPath, const char *fragPath) {
    const std::string vertCodeStr = loadShaderCode(vertPath);
    const std::string fragCodeStr = loadShaderCode(fragPath);
    const char *vertCode = vertCodeStr.c_str();
    const char *fragCode = fragCodeStr.c_str();
    const GLuint vertShader = compileShader(vertCode, GL_VERTEX_SHADER);
    const GLuint fragShader = compileShader(fragCode, GL_FRAGMENT_SHADER);
    createProgram(vertShader, fragShader);
}

std::string Shader::loadShaderCode(const char *path) {
    std::ifstream codeStream;
    std::stringstream shaderCode;
    codeStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        codeStream.open(path);
        shaderCode << codeStream.rdbuf();
        codeStream.close();
    } catch (std::ifstream::failure &e) {
        Error::logMassage("SHADER", e.what());
    }
    return shaderCode.str();
}

GLuint Shader::compileShader(const char *code, const GLuint shaderType) {
    const GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &code, nullptr);
    glCompileShader(shader);
    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        char infoLog[BUFSIZ];
        glGetShaderInfoLog(shader, BUFSIZ, nullptr, infoLog);
        Error::logMassage(code, infoLog);
    }
    return shader;
}

GLvoid Shader::createProgram(const GLuint vertShader, const GLuint fragShader) {
    ID = glCreateProgram();
    glAttachShader(ID, vertShader);
    glAttachShader(ID, fragShader);
    glLinkProgram(ID);
    GLint linked;
    glGetProgramiv(ID, GL_LINK_STATUS, &linked);
    if (!linked) {
        char infoLog[BUFSIZ];
        glGetProgramInfoLog(ID, BUFSIZ, nullptr, infoLog);
        Error::logMassage("SHADER_PROGRAM", "LINKED_FAILED");
    }
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
}

GLvoid Shader::use() const {
    glUseProgram(ID);
}

GLvoid Shader::setBool(const char *name, const GLboolean value) const {
    glUniform1i(glGetUniformLocation(ID, name), value);
}

GLvoid Shader::setInt(const char *name, const GLint value) const {
    glUniform1i(glGetUniformLocation(ID, name), value);
}

GLvoid Shader::setFloat(const char *name, const GLfloat value) const {
    glUniform1f(glGetUniformLocation(ID, name), value);
}

GLvoid Shader::setVec3(const char *name, const glm::vec3 &value) const {
    glUniform3fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));
}

GLvoid Shader::setMat3(const char *name, const glm::mat3 &value) const {
    glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(value));
}

GLvoid Shader::setMat4(const char *name, const glm::mat4 &value) const {
    glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(value));
}

GLvoid Shader::deleteShader() const {
    glDeleteProgram(ID);
}