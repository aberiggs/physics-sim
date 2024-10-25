#include "graphics/window.h" // self

#include <iostream>

bool Window::Init() {
    if (!glfwInit()) {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For MacOS 
#endif

    window_ = glfwCreateWindow(800, 800, "Orbital Simulator", NULL, NULL);
    if (!window_) {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window_);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return false;
    } 

    glfwSetFramebufferSizeCallback(window_, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

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
