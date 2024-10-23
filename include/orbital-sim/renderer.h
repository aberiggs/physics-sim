#pragma once

#include "orbital-sim/body.h"
#include <vector>

class Renderer {
public:
    Renderer();

    void Init();

    void Render(const std::vector<Body>& bodies);

    std::vector<float> GenerateCircleVertices(float radius, int numVertices);

private:
    unsigned int vao_;
    unsigned int vbo_;
    unsigned int shader_;
};