#pragma once

#include "graphics/window.h"
#include "graphics/renderer.h"
#include "graphics/camera.h"

#include <memory>
#include <vector>

class Application {
// Maybe introduce some options?
public:
    Application(); 
    virtual void run() = 0;

protected:
    Window window_;
    Renderer renderer_;
    Camera camera_;
};