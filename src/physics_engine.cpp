#include "orbital-sim/physics_engine.h" // self


void PhysicsEngine::ApplyForces(std::vector<Body>& bodies, float dt) {
    ApplyOrbitalForces(bodies, dt);
}

void PhysicsEngine::ApplyOrbitalForces(std::vector<Body>& bodies, float dt) {

    float earth_sun_distance = 148.79e9f; // Temp value for testing

    for (auto &body : bodies) {
        for (auto &other : bodies) {
            if (&body == &other) {
                continue;
            }
            glm::vec2 direction = other.GetPosition() - body.GetPosition();
            float distance = glm::length(direction) * earth_sun_distance;
            float force = kG_ * body.GetMass() * other.GetMass() / (distance * distance);
            glm::vec2 forceVector = force * glm::normalize(direction);
            body.ApplyForce(forceVector);
        }
    }

}