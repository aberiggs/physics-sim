#pragma once

#include "glm/glm.hpp"

class Camera {
public:
    glm::mat4 GetViewMatrix();
    void Update(float dt);
};