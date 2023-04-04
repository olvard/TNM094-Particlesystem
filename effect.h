#include <rendering/window.h>
#include <particlesystem/particle.h>

#pragma once
class Effect {
public:
    glm::vec2 position = {0, -0.2};

    virtual void move(std::vector<Particle>& particles) = 0;
};

class GravityWell : public Effect {

public:
    GravityWell(float gravity) : Effect(), gravity(gravity) {}

    void move(std::vector<Particle>& particles) override;

    float gravity;
};

class Wind : public Effect {
public:
    Wind(float power) : Effect(), power(power) {}

    void move(std::vector<Particle>& particles) override;
    float power;
};

