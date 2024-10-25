#include "graphics/renderer.h" // self

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

Renderer::Renderer() : render_queue_(), shaders_() {
}

void Renderer::Init() {
    shaders_.push_back(std::make_shared<Shader>("basic2d.vert", "basic2d.frag")); 
}

void Renderer::Render(const Camera& camera) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    auto shader = shaders_[0]; // Basic shader
    for (const auto& obj : render_queue_) {
        shader->Use();
        // Set uniforms
        shader->SetMat4("view", glm::value_ptr(camera.GetViewMatrix()));
        shader->SetMat4("projection", glm::value_ptr(camera.GetProjectionMatrix()));
        shader->SetMat4("model", glm::value_ptr(obj->GetModelMatrix()));

        obj->Draw();
    }
    
    render_queue_.clear();
}

void Renderer::Submit(const RenderObject::Ptr obj) {
    render_queue_.push_back(obj);
}