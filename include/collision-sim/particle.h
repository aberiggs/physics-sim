#pragma once

#include <vector>

#include "graphics/shapes/circle.h"
#include "graphics/shapes/rect.h"

class Particle : public Circle {
public:
    typedef std::shared_ptr<Particle> Ptr;

    Particle(const glm::vec2& position, float radius, float mass = INFINITY, const glm::vec2& velocity = glm::vec2(0.0f, 0.0f), const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f));
    void Update(float delta_time);
    
    // Check if particle collides with another particle, and update velocities accordingly.
    // Returns true if a collision occurred, false otherwise.
    bool CheckParticleCollision(Particle::Ptr other);
    // Notes:
    // - Should be called after updating the particle's position.
    // - Wall collisions are assumed to be purely elastic.
    void CheckWallCollision(const Rect::Ptr wall);

    // Handle collisions between all particles in the vector.
    static void HandleParticleCollisions(std::vector<Particle::Ptr>& particles);
    static std::vector<Particle::Ptr> GenerateRandomParticles(int num_particles, const Rect::Ptr bounds, float max_speed = 1.0f);

private: 
    float mass_;
    glm::vec2 velocity_;
};