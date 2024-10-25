#include "graphics/application.h" // self

Application::Application() : window_ {}, renderer_ {}, camera_ {} {
    window_.Init();
    renderer_.Init();
}