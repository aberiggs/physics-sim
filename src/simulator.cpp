#include "orbital-sim/simulator.h" // self

#include <iostream>

Simulator::Simulator() : window_ {}, renderer_ {}, bodies_ {}, physics_engine_ {}, camera_ {} {
    window_.Init();
    renderer_.Init();
    bodies_.push_back(std::make_shared<Body>(glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 0.0f), 1.986e30f));
    bodies_.push_back(std::make_shared<Body>(glm::vec2(0.4f, 0.0f), glm::vec2(0.0f, 0.10f), 5.9722e10f));
}

void Simulator::run() {
    float lastFrameTime = 0.0f;
    while (!window_.ShouldClose()) {
        float currentTime = glfwGetTime(); // Maybe move to window class?
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        // std::cout << "FPS: " << 1.0f / deltaTime << std::endl;

        // Simulate
        physics_engine_.ApplyForces(bodies_);
        for (auto& body : bodies_) {
            body->Update(deltaTime);
        }

        // Render
        std::vector<RenderObject::Ptr> render_queue; // Objects we'd like to render
        for (auto& body : bodies_) {
            render_queue.push_back(body);
        }
        renderer_.Render(render_queue);
        window_.SwapBuffers();
        window_.PollEvents();
    }
}
