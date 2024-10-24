#pragma once

#include "orbital-sim/body.h"
#include "orbital-sim/shader.h"
#include <vector>


class Renderer {
// Could introduce an enum for shader types & a map for their storage
// Along with this, we could have enum for the different types of bodies (e.g. planet, asteroid, etc.) 
// and a map for vbos/vaos for each type of body
public:
    Renderer();

    void Init();

    void Render(const std::vector<Body>& bodies);

    std::vector<float> GenerateCircleVertices(float radius, int numVertices);

private:
    unsigned int vao_;
    unsigned int vbo_;
    std::vector<Shader> shaders_;
};