#include <particlesystem/effect.h>

void GravityWell::move(std::vector<Particle>& particles){
    float diffX, diffY;

    for (size_t i = 0; i < particles.size(); i++) {

        diffX = position.x - particles[i].position.x;
        diffY = position.y - particles[i].position.y;

        if (diffX < 5 && diffY < 5) {
            particles[i].velocity.x += gravity * float(0.001) * diffX;
            particles[i].velocity.y += gravity * float(0.001) * diffY;
        }
    }
}

void Wind::move(std::vector<Particle>& particles) {
    float diffX, diffY;

    for (size_t i = 0; i < particles.size(); i++) {

        diffX = position.x - particles[i].position.x;
        diffY = position.y - particles[i].position.y;

        if (diffX < 0.5 && diffY < 0.5) {
            particles[i].velocity.x += float(0.001) * power;
            particles[i].velocity.y += float(0.001) * power;
        }
    }
}



