#pragma once

#include <memory>

#include "glm/glm.hpp"

class RigidBody {
public:
    typedef std::shared_ptr<RigidBody> Ptr;

    RigidBody(float mass = INFINITY, const glm::vec2& velocity = glm::vec2(0.0f, 0.0f)) : mass_(mass), velocity_(velocity) {}; // TODO - move to .cpp file

    virtual void Update(float delta_time) = 0;

    virtual glm::vec2 GetPosition() const = 0;
    virtual void SetPosition(const glm::vec2& position) = 0;
    
protected:
    float mass_;
    glm::vec2 velocity_;
};