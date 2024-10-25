#include "collision-sim/simulator.h" // self

void Simulator::run() {
    camera_.SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));

    while (!window_.ShouldClose()) {
        renderer_.Render(camera_); 

        window_.SwapBuffers();
        window_.PollEvents();
    }
}