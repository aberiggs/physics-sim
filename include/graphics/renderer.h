#pragma once

#include "graphics/camera.h"
#include "graphics/render_object.h"
#include "graphics/shader.h"

#include <vector>


class Renderer {
public:
    Renderer();

    void Init();
    void Render(const Camera& camera);

    void Submit(const RenderObject::Ptr obj);

    template <typename T>
    void Submit(const std::vector<T>& objects) {
        for (const auto& obj : objects) {
            Submit(obj);
        }
    }


private:
    // Could sort render_queue based on vao to minimize state changes?
    std::vector<RenderObject::Ptr> render_queue_;
    std::vector<Shader::Ptr> shaders_;
};