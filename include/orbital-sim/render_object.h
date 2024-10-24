#pragma once

#include "glm/glm.hpp"
#include "orbital-sim/shader.h" 

#include <memory>


class RenderObject {
public:
    typedef std::shared_ptr<RenderObject> Ptr; 

    enum class Type {
        kNone,
        kCircle,
        kRectangle
    };

    RenderObject() = delete; // No default constructor
    virtual void Draw(Shader shader) = 0;

    glm::vec2 GetPosition() const;

protected:
    RenderObject(const glm::vec2& position, Type type);
    glm::vec2 position_;
    Type type_;

    uint vao_;
    uint vbo_;
    int num_vertices_;
    
};
