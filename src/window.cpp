#include "orbital-sim/window.h" // self


#include <iostream>

bool Window::Init() {
    if (!glfwInit()) {
        return false;
    }

    window_ = glfwCreateWindow(800, 600, "Orbital Simulator", NULL, NULL);
    if (!window_) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window_);
    glfwSetFramebufferSizeCallback(window_, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });
     
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return false;
    } 
    
    // glfwSwapInterval(0); // disable vsync

    return true;
}

void Window::PollEvents() {
    glfwPollEvents();
}

void Window::SwapBuffers() {
    glfwSwapBuffers(window_);
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(window_);
}