#pragma once

#include "glad/glad.h" // glad must be included before glfw

#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    bool Init(const std::string& window_name = "Graphics Application");
    void PollEvents();
    void SwapBuffers();
    bool ShouldClose();
private:
    GLFWwindow* window_;
};