#include "orbital-sim/body.h" // self

#include "glad/glad.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "orbital-sim/physics_engine.h"

#include <iostream>
#include <vector>

std::vector<float> GenerateCircleVertices(float radius, int numVertices) {
    constexpr float scale = 2e1f;

    std::vector<float> vertices {0.0f, 0.0f};
    for (int i = 0; i <= numVertices; i++) {
        float angle = 2 * 3.14159f * i / numVertices;
        vertices.push_back(radius * scale * cos(angle));
        vertices.push_back(radius * scale * sin(angle));
    }
    return vertices;
}

Body::Body(const glm::vec2& position, const glm::vec2& velocity, float mass, float radius) : RenderObject(position, Type::kCircle), velocity_ {velocity}, force_ {glm::vec2(0.0f, 0.0f)}, mass_ {mass} {
    // Maybe move this to be done in each derived class?
    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);
    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    std::vector<float> vertices = GenerateCircleVertices(radius, 64);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    num_vertices_ = vertices.size() / 2;

    // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Body::Draw() {
    glBindVertexArray(vao_); // Could make this conditional for batching?
    glDrawArrays(GL_TRIANGLE_FAN, 0, num_vertices_); 
    glBindVertexArray(0); // Unbind VAO
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
