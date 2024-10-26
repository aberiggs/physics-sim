#include "graphics/shader.h" // self

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "config.h"
#include "glad/glad.h"

Shader::Shader(const std::string& vertex_path, const std::string& fragment_path) {
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

    // Read shader source from file
    std::string vertex_shader_src;
    std::string fragment_shader_src;
    std::ifstream vertex_file;
    std::ifstream fragment_file;

    vertex_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragment_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    // Read vertex shader
    try {
        vertex_file.open(std::string(SHADER_DIR) + vertex_path);
        std::stringstream vertex_stream;
        vertex_stream << vertex_file.rdbuf();
        vertex_file.close();
        vertex_shader_src = vertex_stream.str();
    } catch (std::ifstream::failure& e) {
        std::cout << "Failed to read vertex shader file: " << vertex_path << std::endl;
        std::cout << e.what() << std::endl;
    }

    // Read fragment shader
    try {
        fragment_file.open(std::string(SHADER_DIR) + fragment_path);
        std::stringstream fragment_stream;
        fragment_stream << fragment_file.rdbuf();
        fragment_file.close();
        fragment_shader_src = fragment_stream.str();
    } catch (std::ifstream::failure& e) {
        std::cout << "Failed to read fragment shader file: " << fragment_path << std::endl;
        std::cout << e.what() << std::endl;
    }

    const char* vertex_shader_src_cstr = vertex_shader_src.c_str();
    glShaderSource(vertex_shader, 1, &vertex_shader_src_cstr, nullptr);
    glCompileShader(vertex_shader);

    const char* fragment_shader_src_cstr = fragment_shader_src.c_str();
    glShaderSource(fragment_shader, 1, &fragment_shader_src_cstr, nullptr);
    glCompileShader(fragment_shader);

    id_ = glCreateProgram();
    glAttachShader(id_, vertex_shader);
    glAttachShader(id_, fragment_shader);

    glLinkProgram(id_);

    // Delete shaders since they are already linked to the program
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

Shader::~Shader() {
    glDeleteProgram(id_);
}

void Shader::Use() {
    glUseProgram(id_);
}

void Shader::SetVec3(const std::string& name, float x, float y, float z) const {
    glUniform3f(glGetUniformLocation(id_, name.c_str()), x, y, z);
}

void Shader::SetVec3(const std::string& name, const glm::vec3 vec) const {
    glUniform3f(glGetUniformLocation(id_, name.c_str()), vec.x, vec.y, vec.z);
}

void Shader::SetMat4(const std::string& name, const float* value) const {
    glUniformMatrix4fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, value);
}
