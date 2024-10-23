#pragma once

#include <string>

class Shader {
public:
    Shader(); // Basic default shader
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void Use();
    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetVec2(const std::string& name, float x, float y) const;
    void SetVec3(const std::string& name, float x, float y, float z) const;
    void SetVec4(const std::string& name, float x, float y, float z, float w) const;
    void SetMat4(const std::string& name, const float* value) const;
private:
    unsigned int id_;
};