#include <particlesystem/particle.h>
#include <particlesystem/emitter.h>
#include <rendering/window.h>

bool Emitter::tick(double dt) {
    time += dt;
    if (time > delay) {
        time = 0;
        return true;
    }
    return false;
}

void Directional::addParticle(std::vector<Particle>& particles, float dt) {
    delay = 0.25;

    Particle particle;
    particle.position = {0.5, -0.5};
    particle.lifetime = 5;

    if (tick(dt)) {

        particle.color = {0.4, 0.9, 0.4, 1};

        particle.velocity.y = float(sin(angle));
        particle.velocity.x = float(cos(angle));

        particle.radius = float(10);

        particles.push_back(particle);
    }
}

void Uniform::addParticle(std::vector<Particle>& particles, float dt) {
    delay = 0.5;
    const int numParticles = 30;
    const float angleStep = 2 * 3.14 / numParticles;
    Particle particle;
    particle.position = {-0.5, 0.5};
    particle.lifetime = 5;
    particle.color = {0.9, 0.1, 1, 1};

    if (tick(dt)) {
        for (int i = 0; i < numParticles; i++) {
            particle.velocity.y = sin(angleStep * i);
            particle.velocity.x = cos(angleStep * i);
            particle.radius = float(10);
            particles.push_back(particle);
        }
    }
}

void Explosion::addParticle(std::vector<Particle>& particles, float dt) {

    delay = 0.01;

    Particle particle;
    particle.position = {0, 0};
    particle.lifetime = 5;

    particle.color = {
        rand() / (float)(RAND_MAX), rand() / (float)(RAND_MAX), rand() / (float)(RAND_MAX), 1

    };

     if (tick(dt)) {
        for (int i = 0; i < amount; i++) {

            particle.velocity.y = float(cos(rand()));
            particle.velocity.x = float(sin(rand()));

            particle.radius = float(10);

            particles.push_back(particle);
        }
    }
}