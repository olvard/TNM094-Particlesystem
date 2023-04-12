#include <catch2/catch_all.hpp>
#include <particlesystem/effect.h>
#include <particlesystem/particle.h>
#include <particlesystem/emitter.h>

SCENARIO("Explosion emitter", "[emitter]") {
    GIVEN("test") { 
        Explosion emitter(1);
        WHEN("addParticle is called") { 
            Particle p;
            std::vector<Particle> particles;
            for (int i = 0; i < 5; i++) {
                emitter.addParticle(particles, 0.1);
            }

            THEN("5 particles with expected properties ") {

                REQUIRE(particles.size() == 5);

                for (const auto& particle : particles) {

                    REQUIRE(particle.radius == Catch::Approx(4));

                    REQUIRE(particle.lifetime == Catch::Approx(5));
                }
            }
        }
    }
}