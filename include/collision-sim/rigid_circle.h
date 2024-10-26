#pragma once

#include "collision-sim/rigid_body.h"
#include "graphics/shapes/circle.h"

class RigidCircle : public Circle, public RigidBody {
public:
    typedef std::shared_ptr<RigidCircle> Ptr;

    RigidCircle(const glm::vec2& position, float radius, float mass = INFINITY, const glm::vec2& velocity = glm::vec2(0.0f, 0.0f), const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f));
    void Update(float delta_time) override;
    void CheckCollision(RigidCircle::Ptr other);
    glm::vec2 GetPosition() const override;
    void SetPosition(const glm::vec2& position) override;

private: 
};