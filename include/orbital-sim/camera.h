#pragma once

#include "glm/glm.hpp"

class Camera {
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix() const;
    void Update(float dt);

private:
    glm::vec3 position_;
    glm::vec3 front_;
    glm::vec3 up_;
    glm::vec3 right_;
    glm::vec3 world_up_;

    float yaw_;
    float pitch_;

    void UpdateCameraVectors();

};