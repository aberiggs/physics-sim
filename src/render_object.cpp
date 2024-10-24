#include "orbital-sim/render_object.h"

#include "glad/glad.h"
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>

std::vector<float> GenerateCircleVertices(float radius, int numVertices) {
    std::vector<float> vertices {0.0f, 0.0f};
    for (int i = 0; i <= numVertices; i++) {
        float angle = 2 * 3.14159f * i / numVertices;
        vertices.push_back(radius * cos(angle));
        vertices.push_back(radius * sin(angle));
    }
    return vertices;
}

RenderObject::RenderObject(const glm::vec2& position, Type type) : position_ {position}, type_ {type} {
    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);
    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    if (type_ == Type::kCircle) {
        std::cout << "Found circle\n";
        std::vector<float> vertices = GenerateCircleVertices(0.01f, 64);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        num_vertices_ = vertices.size() / 2;
    }

    // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

glm::vec2 RenderObject::GetPosition() const {
    return position_;
}