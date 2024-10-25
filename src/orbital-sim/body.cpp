#include "orbital-sim/body.h" // self

#include <iostream>
#include <vector>

#include "glad/glad.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "orbital-sim/physics_engine.h"


Body::Body(const glm::vec2& position, const glm::vec2& velocity, float mass, float radius) : Circle(position, radius), velocity_ {velocity}, force_ {glm::vec2(0.0f, 0.0f)}, mass_ {mass} {
}

void Body::Update(float dt) {
    // F = ma
    // a = F / m
    // dv = at
    // v = v0 + dv
    glm::vec2 dv = (force_ / mass_) * dt; // m/s^2 * s = m/s
    dv = dv / PhysicsEngine::kAU_; // Convert to AU/s
    dv = dv * 86400.0f; // Convert to AU/day
    
    velocity_ += dv;
    position_ += velocity_ * dt;
    force_ = glm::vec2(0.0f, 0.0f); // Reset force for next frame
}

void Body::ApplyForce(const glm::vec2& force) {
    force_ += force;
}
