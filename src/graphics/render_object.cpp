#include "graphics/render_object.h" // self

RenderObject::RenderObject(const glm::vec2& position, Type type) : position_ {position}, type_ {type} {
}

glm::vec2 RenderObject::GetPosition() const {
    return position_;
}
