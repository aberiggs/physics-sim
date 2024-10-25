#pragma once

#include "glad/glad.h"

#include <GLFW/glfw3.h>

class Window {
public:
    bool Init();
    void PollEvents();
    void SwapBuffers();
    bool ShouldClose();
private:
    GLFWwindow* window_;
};