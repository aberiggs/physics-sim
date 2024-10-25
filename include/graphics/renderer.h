#pragma once

#include "graphics/render_object.h"
#include "graphics/camera.h"
#include "graphics/shader.h"

#include <vector>


class Renderer {
public:
    Renderer();

    void Init();
    void Render(const std::vector<RenderObject::Ptr> render_queue, const Camera& camera);

private:
    std::vector<Shader::Ptr> shaders_;
};