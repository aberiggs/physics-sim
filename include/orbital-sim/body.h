#pragma once

#include "glm/glm.hpp"

class Body {
public:
    Body(const glm::vec2& position, const glm::vec2& velocity, float mass);
    void Update(float dt);
    glm::vec2 GetPosition() const;
private:
    glm::vec2 position_;
    glm::vec2 velocity_;
    float mass_;
};