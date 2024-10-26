#include "collision-sim/rigid_circle.h" // self

RigidCircle::RigidCircle(const glm::vec2& position, float radius, float mass, const glm::vec2& velocity, const glm::vec3& color) : Circle(position, radius, color), RigidBody(mass, velocity) {}

void RigidCircle::Update(float delta_time) {
    glm::vec2 position = GetPosition();
    position += velocity_ * delta_time;
    SetPosition(position);
}

void RigidCircle::CheckCollision(RigidCircle::Ptr other) {
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

glm::vec2 RigidCircle::GetPosition() const {
    return Circle::GetPosition();
}

void RigidCircle::SetPosition(const glm::vec2& position) {
    Circle::SetPosition(position);
}
