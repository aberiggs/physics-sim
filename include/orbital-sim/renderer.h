#pragma once

#include "orbital-sim/body.h"
#include "orbital-sim/camera.h"
#include "orbital-sim/shader.h"
#include <vector>


class Renderer {
public:
    Renderer();

    void Init();
    void Render(const std::vector<RenderObject::Ptr> render_queue, const Camera& camera);

private:
    std::vector<Shader> shaders_;
};