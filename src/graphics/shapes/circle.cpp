#include "graphics/shapes/circle.h" // self

#include <vector>

#include "glad/glad.h"

std::vector<float> GenerateCircleVertices(float radius, int num_vertices) {
    std::vector<float> vertices {0.0f, 0.0f};
    for (int i = 0; i <= num_vertices; i++) {
        float angle = 2 * 3.14159f * i / num_vertices;
        vertices.push_back(radius * cos(angle));
        vertices.push_back(radius * sin(angle));
    }
    return vertices;
}

Circle::Circle(const glm::vec2& position, float radius, const glm::vec3& color) : RenderObject(position), radius_(radius), color_(color) {
    // Generate VAO & VBO
    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);

    // Bind VAO
    glBindVertexArray(vao_);

    // Bind VBO 
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    // Generate vertices
    std::vector<float> vertices = GenerateCircleVertices(radius, 360);
    num_vertices_ = vertices.size() / 2; // Each vertex is (x, y)

    // Set VBO data
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VAO
    glBindVertexArray(0);
}

void Circle::Draw() {
    glBindVertexArray(vao_); // Could make this conditional for batching?
    glDrawArrays(GL_TRIANGLE_FAN, 0, num_vertices_); 
    glBindVertexArray(0); // Unbind VAO
}

float Circle::GetRadius() const {
    return radius_;
}

glm::vec3 Circle::GetColor() const {
    return color_;
}

void Circle::SetColor(const glm::vec3& color) {
    color_ = color;
}
