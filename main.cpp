#include <tracy/Tracy.hpp>
#include <rendering/window.h>
#include <particlesystem/particlesystem.h>
#include <cmath>
#include <cstdlib>
#include <vector>

#include <fmt/format.h>

// Simple random functions to get started
// Random float (0,1)
float rnd() { return rand() / static_cast<float>(RAND_MAX); }

// Random float (-1,1)
float srnd() { return rnd() * 2.0f - 1.0f; }

int main(int, char**) try {
    rendering::Window window("Particle System v0.0.1 pre-release alpha", 2000, 1300);

    Particlesystem ps;

    std::vector<glm::vec2> positions;
    std::vector<float> radiuses;
    std::vector<glm::vec4> colors;


    double prevTime = 0.0;
    bool running = true;

    while (running) {
        window.beginFrame();

        const double t = window.time();
        float dt = t - prevTime;
        prevTime = t;

        // Clear screen with color
        window.clear({0, 0, 0, 1});

        {
            ZoneScopedN("Update particles");

            ps.update(dt);

            for (size_t i = 0; i < ps.particles.size(); i++) {
                positions.push_back(ps.particles[i].position);
                radiuses.push_back(ps.particles[i].radius);
                colors.push_back(ps.particles[i].color);
            }

            window.drawPoints(positions, radiuses, colors);

        /*    for (size_t i = 0; i < ps.particles.size(); i++) {
                window.drawPoint(ps.particles[i].position, ps.particles[i].radius,
                                 ps.particles[i].color);
            }*/

            positions.clear();
            radiuses.clear();
            colors.clear();

           
        }


        // UI
        {
            {
                window.beginGuiWindow("Particle System");

                if (window.button("Close application")) {
                    running = false;
                }

                // ------------ EMITTERS ------------

                // Directional
                if (window.button("Directional emitter")) {
                    ps.emitters.push_back(new Directional(2.14));
                }
                
                // Uniform
                if (window.button("Uniform emitter")) {
                    ps.emitters.push_back(new Uniform(20));
                }


                // ------------ EFFECTS ------------

                // Gravity effect

                if (window.button("Gravity well")) {
                    ps.effects.push_back(new GravityWell(50));
                }

                if (window.button("Wind")) {
                    ps.effects.push_back(new Wind(10));
                }

                window.endGuiWindow();
            }
        }

        window.endFrame();
        running = running && !window.shouldClose();
    }

    return EXIT_SUCCESS;
} catch (const std::exception& e) {
    fmt::print("{}", e.what());
    return EXIT_FAILURE;
}
