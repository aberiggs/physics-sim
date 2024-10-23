#include "orbital-sim/renderer.h" // self

#include "glad/glad.h"
#include <iostream>

Renderer::Renderer() : vao_ {}, vbo_ {}, shader_ {} {
}

void Renderer::Init() {
    glGenBuffers(1, &vbo_);
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    std::vector<float> vertices = GenerateCircleVertices(0.6f, 64);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_DYNAMIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Renderer::Render(const std::vector<Body>& bodies) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (const auto& body : bodies) {
        glUseProgram(shader_);
        glBindVertexArray(vao_);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_);

        glDrawArrays(GL_TRIANGLE_FAN, 0, 66); // TODO: Fix magic #
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