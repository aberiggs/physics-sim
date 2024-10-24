#pragma once

#include "orbital-sim/body.h"
#include "orbital-sim/shader.h"
#include <vector>


class Renderer {
public:
    Renderer();

    void Init();
    void Render(std::vector<RenderObject::Ptr> render_queue);

private:
    std::vector<Shader> shaders_;
};