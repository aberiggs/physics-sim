#include "collision-sim/simulator.h" // self

#include <chrono>

Simulator::Simulator() : Application(), particles_(), bounds_(nullptr) {}

void Simulator::run() {
    camera_.SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));

    bounds_ = std::make_shared<Rect>(glm::vec2(-1.0f, -1.0f), glm::vec2(2.0f, 2.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    particles_ = Particle::GenerateRandomParticles(5000, bounds_);

    float sim_speed = 1.0f;
    float lastFrameTime = 0.0f;
    while (!window_.ShouldClose()) {
        float currentTime = glfwGetTime(); // Maybe move to window class?
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;
        deltaTime *= sim_speed;

        // std::cout << "FPS: " << 1.0f / deltaTime << std::endl;

        // Collision detection
        auto start_sim = std::chrono::high_resolution_clock::now();
        Particle::HandleParticleCollisions(particles_);

        // Update and enforce wall collisions
        for (auto particle : particles_) {
            particle->Update(deltaTime);
            particle->CheckWallCollision(bounds_);
        }
        auto end_sim = std::chrono::high_resolution_clock::now();

        renderer_.Submit(bounds_);
        renderer_.Submit(particles_);
        auto start_render = std::chrono::high_resolution_clock::now();
        renderer_.Render(camera_);
        auto end_render = std::chrono::high_resolution_clock::now();

        auto sim_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_sim - start_sim);
        auto render_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_render - start_render);
    
        std::cout << "Sim time: " << sim_duration.count() << "us | Render time: " << render_duration.count() << "us\n"; 

        window_.SwapBuffers();
        window_.PollEvents();
    }
}