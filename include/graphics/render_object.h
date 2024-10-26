#pragma once

#include "glm/glm.hpp"
#include "graphics/shader.h" 

#include <cstdint>
#include <memory>
#include <iostream>


class RenderObject {
public:
    typedef std::shared_ptr<RenderObject> Ptr; 

    RenderObject() = delete; // No default constructor
    virtual ~RenderObject() = default; // TODO: Clean up VAO and VBO

    virtual void Draw(Shader::Ptr shader) = 0; // TODO: Reconsider passing shader as a parameter

    glm::mat4 GetModelMatrix() const;

    glm::vec2 GetPosition() const;
    void SetPosition(const glm::vec2& position);

protected:
    RenderObject(const glm::vec2& position);

    glm::vec2 position_; // World position

    uint32_t vao_;
    uint32_t vbo_;
    uint32_t num_vertices_;
};
