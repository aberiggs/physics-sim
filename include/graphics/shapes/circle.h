#pragma once

#include "graphics/render_object.h"

#include <memory>

class Circle : public RenderObject {
public:
    typedef std::shared_ptr<Circle> Ptr;

    Circle(const glm::vec2& position, float radius, const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f));
    virtual void Draw() override;
    float GetRadius() const;
    void SetColor(const glm::vec3& color);
    glm::vec3 GetColor() const;
private: 
    float radius_;
    glm::vec3 color_;
};