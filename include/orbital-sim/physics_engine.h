#pragma once

#include "orbital-sim/body.h"

#include <vector>

class PhysicsEngine {
public:
    void ApplyForces(std::vector<Body::Ptr> bodies);
private:
    void ApplyOrbitalForces(std::vector<Body::Ptr> bodies);

    const float kG_ = 6.67430e-11f;

};