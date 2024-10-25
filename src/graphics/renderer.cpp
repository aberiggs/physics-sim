#include "graphics/renderer.h" // self

#include "glad/glad.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

Renderer::Renderer() : shaders_ {} {
}

void Renderer::Init() {
    shaders_.push_back(std::make_shared<Shader>("basic2d.vert",
                                                "basic2d.frag")); // Basic shader
    // In future, we could compile every shader found in the shaders folder
}

void Renderer::Render(const std::vector<RenderObject::Ptr> render_queue, const Camera& camera) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Could sort render_queue based on vao to minimize state changes?

    auto shader = shaders_[0]; // Basic shader
    for (const auto& obj : render_queue) {
        shader->Use();
        
        // Apply transformations
        shader->SetMat4("view", glm::value_ptr(camera.GetViewMatrix()));
        shader->SetMat4("projection", glm::value_ptr(camera.GetProjectionMatrix()));
        auto model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(obj->GetPosition(), 0.0f));
        shader->SetMat4("model", glm::value_ptr(model));

        obj->Draw();
    }
}
