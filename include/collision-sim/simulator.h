#pragma once

#include "collision-sim/particle.h"
#include "graphics/application.h"
#include "graphics/shapes/rect.h"

class Simulator : public Application {
public:
    Simulator();
    void run() override;

private:
    std::vector<Particle::Ptr> particles_;
    Rect::Ptr bounds_;
};