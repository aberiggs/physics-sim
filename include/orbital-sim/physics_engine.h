#pragma once

#include "orbital-sim/body.h"

#include <vector>

class PhysicsEngine {
public:
    static constexpr float kAU_ = 1.496e11f; // Astronomical unit in meters

    void ApplyForces(std::vector<Body::Ptr> bodies);

private:
    void ApplyOrbitalForces(std::vector<Body::Ptr> bodies);

    static constexpr float kG_ = 6.67430e-11f;

};