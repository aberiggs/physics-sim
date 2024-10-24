#include "orbital-sim/body.h" // self

#include "glad/glad.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Body::Body(const glm::vec2& position, const glm::vec2& velocity, float mass) : RenderObject(position, Type::kCircle), velocity_ {velocity}, force_ {glm::vec2(0.0f, 0.0f)}, mass_ {mass} {
}

void Body::Draw() {
    glBindVertexArray(vao_); // Could make this conditional for batching
    glDrawArrays(GL_TRIANGLE_FAN, 0, num_vertices_); 
    glBindVertexArray(0); // Unbind VAO
}

void Body::Update(float dt) {
    // F = ma
    // a = F / m
    // dv = at
    // v = v0 + dv
    velocity_ += (force_ / mass_) * dt;
    position_ += velocity_ * dt;
    force_ = glm::vec2(0.0f, 0.0f); // Reset force for next frame
}

void Body::ApplyForce(const glm::vec2& force) {
    force_ += force;
}
