#pragma once

#include <vector>

#include "graphics/shapes/circle.h"
#include "graphics/shapes/rect.h"

class Particle : public Circle {
public:
    typedef std::shared_ptr<Particle> Ptr;

    Particle(const glm::vec2& position, float radius, float mass = INFINITY, const glm::vec2& velocity = glm::vec2(0.0f, 0.0f), const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f));
    void Update(float delta_time);
    void CheckParticleCollision(Particle::Ptr other);
    // Wall collisions are assumed to be purely elastic
    void CheckWallCollision(const Rect::Ptr wall);

    // Maybe make a static func to take a vector of particles and check for collisions
    
    glm::vec2 GetPosition() const;
    void SetPosition(const glm::vec2& position);

    static std::vector<Particle::Ptr> GenerateRandomParticles(int num_particles, const Rect::Ptr bounds);

private: 
    float mass_;
    glm::vec2 velocity_;
};