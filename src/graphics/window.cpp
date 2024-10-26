#include "graphics/window.h" // self

#include <iostream>

bool Window::Init(const std::string& window_name) {
    if (!glfwInit()) {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For MacOS 
#endif

    window_ = glfwCreateWindow(800, 800, window_name.c_str(), NULL, NULL);
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
        window = window; // Unused
        // Get aspect ratio - TODO: come back to this
        // int old_width, old_height;
        // glfwGetWindowSize(window, &old_width, &old_height);
        // float aspect_ratio = static_cast<float>(old_width) / old_height;

        auto min_dim = std::min(width, height);
        // min_dim x min_dim viewport centered in the window
        glViewport((width - min_dim) / 2, (height - min_dim) / 2, min_dim, min_dim);
    });

    // Other options
    glfwSwapInterval(0); // disable vsync

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
