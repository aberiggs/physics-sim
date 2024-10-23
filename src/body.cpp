#include "orbital-sim/body.h" // self

Body::Body(const glm::vec2& position, const glm::vec2& velocity, float mass) : position_ {position}, velocity_ {velocity}, mass_ {mass} {   
}

void Body::Update(float dt) {
    position_ += velocity_ * dt;
}

glm::vec2 Body::GetPosition() const {
    return position_;
}
