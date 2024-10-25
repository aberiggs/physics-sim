#pragma once

#include "graphics/application.h"
#include "orbital-sim/body.h"
#include "orbital-sim/physics_engine.h"

#include <vector>

class Simulator : public Application {
// Maybe introduce some options?
public:
    Simulator();
    void run() override;

private:
    std::vector<Body::Ptr> bodies_;
    PhysicsEngine physics_engine_;
};