#include "collision-sim/particle.h" // self

Particle::Particle(const glm::vec2& position, float radius, float mass, const glm::vec2& velocity, const glm::vec3& color) : Circle(position, radius, color), mass_(mass), velocity_(velocity) {}

void Particle::Update(float delta_time) {
    glm::vec2 position = GetPosition();
    position += velocity_ * delta_time;
    SetPosition(position);
}

void Particle::CheckParticleCollision(Particle::Ptr other) {
    glm::vec2 position = GetPosition();
    glm::vec2 other_position = other->GetPosition();
    float distance = glm::distance(position, other_position);
    float radius_sum = GetRadius() + other->GetRadius();
    if (distance < radius_sum) {
        glm::vec2 normal = glm::normalize(position - other_position);
        glm::vec2 relative_velocity = velocity_ - other->velocity_;
        float velocity_along_normal = glm::dot(relative_velocity, normal);
        if (velocity_along_normal > 0) {
            return;
        }
        float e = 1.0f;
        float j = -(1 + e) * velocity_along_normal;
        j /= 1 / mass_ + 1 / other->mass_;
        glm::vec2 impulse = j * normal;
        velocity_ += impulse / mass_;
        other->velocity_ -= impulse / other->mass_;
    }
}

void Particle::CheckWallCollision(const Rect::Ptr wall) {
    glm::vec2 position = GetPosition();
    glm::vec2 tl = wall->GetTl();
    glm::vec2 br = wall->GetBr();
    if (position.x - GetRadius() < tl.x) {
        velocity_.x = -velocity_.x;
        position.x = tl.x + GetRadius();
    }
    if (position.x + GetRadius() > br.x) {
        velocity_.x = -velocity_.x;
        position.x = br.x - GetRadius();
    }
    if (position.y - GetRadius() < tl.y) {
        velocity_.y = -velocity_.y;
        position.y = tl.y + GetRadius();
    }
    if (position.y + GetRadius() > br.y) {
        velocity_.y = -velocity_.y;
        position.y = br.y - GetRadius();
    }
    SetPosition(position);
}

glm::vec2 Particle::GetPosition() const {
    return Circle::GetPosition();
}

void Particle::SetPosition(const glm::vec2& position) {
    Circle::SetPosition(position);
}

std::vector<Particle::Ptr> Particle::GenerateRandomParticles(int num_particles, const Rect::Ptr bounds) {
    std::vector<Particle::Ptr> particles;
    for (int i = 0; i < num_particles; i++) {
        float radius = 0.005f;
        float mass = 1.0f;
        glm::vec2 position = glm::vec2(
            bounds->GetTl().x + radius + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (bounds->GetSize().x - 2 * radius))),
            bounds->GetTl().y + radius + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (bounds->GetSize().y - 2 * radius)))
        );
        glm::vec2 velocity = glm::vec2(
            static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
            static_cast <float> (rand()) / static_cast <float> (RAND_MAX)
        );
        glm::vec3 color = glm::vec3(
            static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
            static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
            static_cast <float> (rand()) / static_cast <float> (RAND_MAX)
        );
        particles.push_back(std::make_shared<Particle>(position, radius, mass, velocity, color));
    }
    return particles;
}