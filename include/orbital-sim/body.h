#pragma once

#include "glm/glm.hpp"

class Body {
public:
    Body(const glm::vec2& position, const glm::vec2& velocity, float mass);
    void Update(float dt);
    void ApplyForce(const glm::vec2& force);
    glm::vec2 GetPosition() const;
    float GetMass() const { return mass_; }
private:
    glm::vec2 position_;
    glm::vec2 velocity_;
    glm::vec2 force_;
    float mass_;
};