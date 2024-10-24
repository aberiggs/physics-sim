#include "orbital-sim/body.h" // self

#include <iostream>

Body::Body(const glm::vec2& position, const glm::vec2& velocity, float mass) : position_ {position}, velocity_ {velocity}, force_ {glm::vec2(0.0f, 0.0f)}, mass_ {mass} {
}

void Body::Update(float dt) {
    // F = ma
    // a = F / m
    // dv = at
    // v = v0 + dv
    velocity_ += (force_ / mass_) * dt;
    position_ += velocity_ * dt;

    force_ = glm::vec2(0.0f, 0.0f);
}

void Body::ApplyForce(const glm::vec2& force) {
    force_ += force;
}

glm::vec2 Body::GetPosition() const {
    return position_;
}
