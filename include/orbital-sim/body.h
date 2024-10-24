#pragma once

#include "orbital-sim/render_object.h"
#include "glm/glm.hpp"

#include <memory>

class Body : public RenderObject {
public:
    typedef std::shared_ptr<Body> Ptr;

    Body(const glm::vec2& position, const glm::vec2& velocity, float mass);
    void Draw() override;
    void Update(float dt);
    void ApplyForce(const glm::vec2& force);
    float GetMass() const { return mass_; }
private:
    glm::vec2 velocity_;
    glm::vec2 force_;
    float mass_;
};