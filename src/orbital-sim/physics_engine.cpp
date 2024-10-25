#include "orbital-sim/physics_engine.h" // self

void PhysicsEngine::ApplyForces(std::vector<Body::Ptr> bodies) {
    ApplyOrbitalForces(bodies);
}

void PhysicsEngine::ApplyOrbitalForces(std::vector<Body::Ptr> bodies) {
    for (auto body : bodies) {
        for (auto other : bodies) {
            if (body == other) {
                continue;
            }
            glm::vec2 direction = other->GetPosition() - body->GetPosition();
            float distance = glm::length(direction) * kAU_; // Convert to meters
            float force = (kG_ * body->GetMass()) * (other->GetMass() / (distance * distance));
            glm::vec2 forceVector = force * glm::normalize(direction);
            body->ApplyForce(forceVector);
        }
    }
}
