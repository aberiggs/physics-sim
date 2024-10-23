# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(orbital-sim VERSION 0.0)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Output directories for compiled binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories
include_directories(include)

# All source files
file (GLOB SOURCES
    src/*.cpp
    src/external/glad.c
)

# Add executable target
add_executable(orbital_simulator ${SOURCES})

# Add external dependencies
find_package(glfw3 3.3 REQUIRED)

# Link libraries
target_link_libraries(orbital_simulator glfw)

# Set compile options
target_compile_options(orbital_simulator PRIVATE -Wall -Wextra)
