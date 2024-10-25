#include "orbital-sim/render_object.h" // self

#include "glad/glad.h"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <vector>


RenderObject::RenderObject(const glm::vec2& position, Type type) : position_ {position}, type_ {type} {
}

glm::vec2 RenderObject::GetPosition() const {
    return position_;
}
