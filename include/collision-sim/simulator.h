#pragma once

#include "collision-sim/rigid_circle.h"
#include "graphics/application.h"

class Simulator : public Application {
public:
    void run() override;

private:
    std::vector<RigidCircle::Ptr> circles_;
};