#pragma once

#include "glm/glm.hpp"
#include "graphics/render_object.h"

#include <memory>

// The assumption is that all bodies are circular
class Body : public RenderObject {
public:
    typedef std::shared_ptr<Body> Ptr;

    Body(const glm::vec2& position, const glm::vec2& velocity, float mass, float radius);
    void Draw() override;
    void Update(float dt);
    void ApplyForce(const glm::vec2& force);
    float GetMass() const { return mass_; }
private:
    // Position is in AU
    glm::vec2 velocity_;    // Au/day
    glm::vec2 force_;       // N
    float mass_;            // kg
};