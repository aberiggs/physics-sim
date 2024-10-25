# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(physics-sim VERSION 0.0)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add external dependencies
find_package(glfw3 3.3 REQUIRED)

# Output directories for compiled binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Configure shaders path
configure_file(${CMAKE_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/config.h @ONLY)

# Include directories
include_directories(include)
include_directories(${CMAKE_BINARY_DIR}) # Config for defines


# Graphics/Rendering Sources
file (GLOB_RECURSE GRAPHICS_SRC
    src/graphics/*.cpp
    src/external/glad.c
)

### Orbital Sim Build
# Get source files
file (GLOB ORBITAL_SRC
    src/orbital-sim/*.cpp
)
# Add executable target
add_executable(orbital_simulator ${ORBITAL_SRC} ${GRAPHICS_SRC})
# Link libraries
target_link_libraries(orbital_simulator glfw)
# Set compile options
target_compile_options(orbital_simulator PRIVATE -Wall -Wextra)
###

### Collision Sim Build
# Get source files
file (GLOB COLLISION_SRC
    src/collision-sim/*.cpp
)
# Add executable target
add_executable(collision_simulator ${COLLISION_SRC} ${GRAPHICS_SRC})
# Link libraries
target_link_libraries(collision_simulator glfw)
# Set compile options
target_compile_options(collision_simulator PRIVATE -Wall -Wextra)
###