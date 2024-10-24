#pragma once

#include "glm/glm.hpp"
#include "orbital-sim/shader.h" 

#include <cstdint>
#include <memory>
#include <iostream>


class RenderObject {
public:
    typedef std::shared_ptr<RenderObject> Ptr; 

    enum class Type {
        kOther,
        kCircle,
        kRectangle
    };

    RenderObject() = delete; // No default constructor
    virtual ~RenderObject() = default;
    virtual void Draw() = 0;

    glm::vec2 GetPosition() const;

protected:
    RenderObject(const glm::vec2& position, Type type);

    glm::vec2 position_;
    Type type_;

    uint32_t vao_;
    uint32_t vbo_;
    int num_vertices_;
};
