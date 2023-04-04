#include <rendering/window.h>

#pragma once

namespace info {

struct ParticleInfo {
    /// The position of the particle. The screen coordinates range from [-1, -1] in the
    /// lower left corner to [1, 1] in the upper right corner
    glm::vec2 position = {0, 0};

    /// The size of the particle. This size is expressed roughly in pixels
    float radius = 2.f;

    /// The color of the particle. Each color component has to be in the range [0, 1]
    glm::vec4 color = {1.0f, 0.5f, 0.31f, 0};

    /// The remaining lifetime of the particle in seconds
    float lifetime = 60.f;
};

/// The struct that represents an individual emitter location that is to be rendered. Note
/// that some emitters might not have a physical location and might not require a
/// corresponding EmitterInfo struct
struct EmitterInfo {
    /// The position of the emitter. The screen coordinates range from [-1, -1] in the
    /// lower left corner to [1, 1] in the upper right corner
    glm::vec2 position = {0, 0};

    /// The size of the rectangle that is used to represent the emitter in pixels
    float size = 12.5f;

    /// The color of the emitter. Each color component has to be in the range [0, 1]
    glm::vec4 color = {1.0f, 0.5f, 0.31f, 0};
};

/// The struct that represents an individual force location that is to be rendered. Note
/// that some forces might not have a physical location and might not require a
/// corresponding ForceInfo struct
struct ForceInfo {
    /// The position of the force. The screen coordinates range from [-1, -1] in the
    /// lower left corner to [1, 1] in the upper right corner
    glm::vec2 position = {0, 0};

    // Size of the triangle that is used to represent the force in pixels
    float size = 12.5f;

    // The color for the force. Each color component has to be in the range [0, 1]
    glm::vec4 color = {1.0f, 0.5f, 0.31f, 0};
};

}  // namespace info