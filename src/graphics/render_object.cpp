#include "graphics/render_object.h" // self

#include "glm/gtc/matrix_transform.hpp"

RenderObject::RenderObject(const glm::vec2& position) : position_ {position} {
}

glm::mat4 RenderObject::GetModelMatrix() const {
    auto model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position_, 0.0f));
    return model;
}

glm::vec2 RenderObject::GetPosition() const {
    return position_;
}
