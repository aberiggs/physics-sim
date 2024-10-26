#include "collision-sim/simulator.h" // self

Simulator::Simulator() : Application(), particles_(), bounds_(nullptr) {}

void Simulator::run() {
    camera_.SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));

    bounds_ = std::make_shared<Rect>(glm::vec2(-1.0f, -1.0f), glm::vec2(2.0f, 2.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    particles_ = Particle::GenerateRandomParticles(1000, bounds_);

    float sim_speed = 1.0f;
    float lastFrameTime = 0.0f;
    while (!window_.ShouldClose()) {
        float currentTime = glfwGetTime(); // Maybe move to window class?
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;
        deltaTime *= sim_speed;

        std::cout << "FPS: " << 1.0f / deltaTime << std::endl;

        // Collision detection
        for (int i = 0; i < particles_.size(); i++) {
            for (int j = i + 1; j < particles_.size(); j++) {
                particles_[i]->CheckParticleCollision(particles_[j]);
            }
            particles_[i]->Update(deltaTime);
            particles_[i]->CheckWallCollision(bounds_);
        }

        renderer_.Submit(bounds_);
        renderer_.Submit(particles_);
        renderer_.Render(camera_);


        window_.SwapBuffers();
        window_.PollEvents();
    }
}