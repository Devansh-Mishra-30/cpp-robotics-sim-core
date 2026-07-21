#include <iostream>
#include "Simulator.hpp"

Particle makeParticle(Vec2 position, Vec2 velocity) {
    return Particle{position, velocity};
}

void printParticle(std::size_t index, const Particle& particle) {
    std::cout << " Particle " << index+1
              << " | position: " << particle.position()
              << " | velocity: " << particle.velocity()
              << " | speed: " << particle.speed() << "\n"; 
}

void applyVelocityKick(Particle& particle, const Vec2& deltaVelocity) {
    particle.addVelocity(deltaVelocity);
}

void applyVelocityKickIfPresent(Particle* particle, const Vec2& deltaVelocity) {
    if (particle == nullptr) {
        std::cout << " No particle found. Kick skipped.\n";
        return;
    }

    particle->addVelocity(deltaVelocity);
}

int main(){
    
    Simulator sim;
    sim.addParticle(makeParticle(Vec2{0.0,0.0}, Vec2{1.0,2.0}));
    sim.addParticle(makeParticle(Vec2{10.0,0.0}, Vec2{-1.0,0.0}));
    sim.addParticle(makeParticle(Vec2{0.0,5.0}, Vec2{0.0,-0.5}));

    double dt = 0.1;

    std::cout << "Particle count: " << sim.particleCount() << "\n";

    std::cout << "\nInitial particles:\n";
    const std::vector<Particle>& particles = sim.getparticles();

    for(std::size_t i = 0; i<particles.size(); i++){
        printParticle(i, particles[i]);
    }

    std::cout << "\nApplying velocity kicks:\n";

    applyVelocityKick(sim.particleAt(0), Vec2{0.5, 0.0});
    applyVelocityKickIfPresent(sim.tryGetParticle(1), Vec2{0.0,1.0});
    applyVelocityKickIfPresent(sim.tryGetParticle(100), Vec2{10.0,1.0});

    std::cout << "\nAfter kicks:\n";

    for(std::size_t i = 0; i < particles.size(); i++ ) {
        printParticle(i, particles[i]);
    }

    for(int step = 1; step <=10; step++) {
        sim.update(dt);
    }

    std::cout << "\nAfter 10 steps:\n";
    for (std::size_t i = 0; i < particles.size(); i++) {
        printParticle(i, particles[i]);
    }

    return 0;
}