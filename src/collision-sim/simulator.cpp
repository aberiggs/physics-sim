#include "collision-sim/simulator.h" // self

void Simulator::run() {
    camera_.SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));

    RigidCircle::Ptr circle1 = std::make_shared<RigidCircle>(glm::vec2(-0.5f, 0.1f), 0.1f, 1.0f, glm::vec2(0.3f, 0.0f));
    RigidCircle::Ptr circle2 = std::make_shared<RigidCircle>(glm::vec2(0.5f, 0.0f), 0.075f, 1.00f, glm::vec2(-0.3f, 0.0f));

    circles_.push_back(circle1);
    circles_.push_back(circle2);

    float speed = 1.0f;
    float lastFrameTime = 0.0f;
    while (!window_.ShouldClose()) {
        float currentTime = glfwGetTime(); // Maybe move to window class?
        float deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;
        deltaTime *= speed;

        for (int i = 0; i < circles_.size(); i++) {
            for (int j = i + 1; j < circles_.size(); j++) {
                circles_[i]->CheckCollision(circles_[j]);
            }
        }

        for (auto& circle : circles_) {
            circle->Update(deltaTime);
        }


        renderer_.Submit(circles_);
        renderer_.Render(camera_);


        window_.SwapBuffers();
        window_.PollEvents();
    }
}