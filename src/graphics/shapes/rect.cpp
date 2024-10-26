#include "graphics/shapes/rect.h" // self

#include "glad/glad.h"

Rect::Rect(const glm::vec2& tl, const glm::vec2& size, const glm::vec3& color) : RenderObject(tl), size_(size), color_(color) {
    float vertices[] = {
        0.0f, 0.0f,
        size_.x, 0.0f,
        size_.x, size_.y,
        0.0f, size_.y
    };

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    num_vertices_ = 4;
}

void Rect::Draw(Shader::Ptr shader) {
    glBindVertexArray(vao_);
    // Set specific shader uniforms
    shader->SetVec3("color", color_);
    // Draw the rect
    glDrawArrays(GL_LINE_LOOP, 0, num_vertices_);
    glBindVertexArray(0);
}

glm::vec2 Rect::GetTl() const {
    return position_;
}

glm::vec2 Rect::GetBr() const {
    return position_ + size_;
}

void Rect::CenterAt(const glm::vec2& center) {
    position_ = center - size_ / 2.0f;
}

glm::vec2 Rect::GetSize() const {
    return size_;
}