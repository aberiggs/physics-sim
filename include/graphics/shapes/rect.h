#pragma once

#include "graphics/render_object.h"

class Rect : public RenderObject {
public:
    typedef std::shared_ptr<Rect> Ptr;

    Rect(const glm::vec2& tl, const glm::vec2& size, const glm::vec3& color = glm::vec3(1.0f, 1.0f, 1.0f));

    void Draw() override;

    // Gets the top left corner of the rect
    glm::vec2 GetTl() const;
    // Gets the bottom right corner of the rect
    glm::vec2 GetBr() const;

    void CenterAt(const glm::vec2& center);

    glm::vec2 GetSize() const;
    // Set size would possibly involve changing the VBO data? - implement later

private:
    glm::vec2 size_;
    glm::vec3 color_;
};
