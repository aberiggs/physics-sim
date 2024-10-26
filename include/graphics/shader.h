#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "glm/glm.hpp"

class Shader {
public:
    typedef std::shared_ptr<Shader> Ptr; // Ref count - prevent destructor from deleting shader program

    Shader() = delete; // Must provide vertex and fragment shader paths
    Shader(const Shader&) = delete; // id_ is unique
    Shader(const std::string& vertexPath, const std::string& fragmentPath); // TODO: Improve error handling
    ~Shader();

    void Use();

    void SetBool(const std::string& name, bool value) const;

    void SetInt(const std::string& name, int value) const;

    void SetFloat(const std::string& name, float value) const;

    void SetVec2(const std::string& name, float x, float y) const;

    void SetVec3(const std::string& name, float x, float y, float z) const;
    void SetVec3(const std::string& name, const glm::vec3 vec) const;

    void SetVec4(const std::string& name, float x, float y, float z, float w) const;

    void SetMat4(const std::string& name, const float* value) const;
    
private:
    uint32_t id_;
};