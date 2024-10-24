#include "orbital-sim/renderer.h" // self

#include "glad/glad.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <iostream>

Renderer::Renderer() : vao_ {}, vbo_ {}, shaders_ {} {
}

void Renderer::Init() {
    shaders_.push_back(Shader()); // Basic shader

    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);
    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    std::vector<float> vertices = GenerateCircleVertices(0.01f, 64);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Renderer::Render(const std::vector<Body::Ptr> bodies) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    auto shader = shaders_[0]; // Basic shader
    for (const auto& body : bodies) {
        body->Draw(shader);
    }
}

std::vector<float> Renderer::GenerateCircleVertices(float radius, int numVertices) {
    std::vector<float> vertices {0.0f, 0.0f};
    for (int i = 0; i <= numVertices; i++) {
        float angle = 2 * 3.14159f * i / numVertices;
        vertices.push_back(radius * cos(angle));
        vertices.push_back(radius * sin(angle));
    }
    return vertices;
}