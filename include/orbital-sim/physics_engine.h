#pragma once

#include "orbital-sim/body.h"

#include <vector>

class PhysicsEngine {
public:
    void ApplyForces(std::vector<Body>& bodies, float dt);
};