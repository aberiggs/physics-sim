#pragma once

#include "orbital-sim/window.h"
#include "orbital-sim/renderer.h"
#include "orbital-sim/body.h"
#include "orbital-sim/physics_engine.h"
#include "orbital-sim/camera.h"

#include <memory>
#include <vector>

class Simulator {
// Maybe introduce some options?
public:
    Simulator();
    void run();

private:
    Window window_;
    Renderer renderer_;
    std::vector<Body::Ptr> bodies_;
    PhysicsEngine physics_engine_;
    Camera camera_;
};