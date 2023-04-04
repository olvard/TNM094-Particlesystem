#include <rendering/window.h>

class Emitter {
public:
    glm::vec2 position = {0, 0};
    glm::vec2 velocity = {0, 0};
    double time;
    double delay;

    bool tick(double dt);

    virtual void addParticle(std::vector<Particle>& particles, float dt) = 0;
};

class Directional : public Emitter {

public:
    Directional(float angle) : Emitter(), angle(angle) {}

    void addParticle(std::vector<Particle>& particles, float dt) override;
    float angle;
};

class Uniform : public Emitter {

public:

    Uniform(int amount) : Emitter(), amount(amount) {}
    void addParticle(std::vector<Particle>& particles, float dt) override;
    int amount;
    ~Uniform();
};

class Explosion : public Emitter {

public:
    Explosion(int amount) : Emitter(), amount(amount) {}
    void addParticle(std::vector<Particle>& particles, float dt) override;
    int amount;

};

