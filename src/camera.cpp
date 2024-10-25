#include "orbital-sim/camera.h" // self

#include "glm/gtc/matrix_transform.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 up) : position_ {position}, front_ {glm::vec3(0.0f, 0.0f, -1.0f)}, world_up_ {up}, yaw_ {-90.0f}, pitch_ {0.0f} {
    UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() const {
    return glm::lookAt(position_, position_ + front_, up_);
}

glm::mat4 Camera::GetProjectionMatrix() const {
    return glm::perspective(glm::radians(45.0f), 800.0f / 800.0f, 0.1f, 100.0f); // TODO: Make this dynamic?
}

void Camera::Update(float dt) {
    // Not necessary right now 
}

void Camera::UpdateCameraVectors() {
    glm::vec3 front; // Shouldn't change - but adding in case we go 3D at some point
    front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front.y = sin(glm::radians(pitch_));
    front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front_ = glm::normalize(front);

    right_ = glm::normalize(glm::cross(front_, world_up_));
    up_ = glm::normalize(glm::cross(right_, front_));
}