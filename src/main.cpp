#include <cstddef>
#include <iostream>
#include <vector>
#include "Simulator.hpp"

// create particle from position and velocity

Particle makeParticle(Vec2 startPosition, Vec2 startVelocity){
    return Particle{startPosition,startVelocity};
}

// print one particle without copying or modifying it


void printParticle(std::size_t index, const Particle& particle){
    std::cout << " Particle: " << index + 1 << "\n"
    << " | position: " << particle.position() << "\n"
    << " | velocity: " << particle.velocity() << "\n"
    << " | speed: " << particle.speed() << "\n";
}

void printParticleIfPresent(const Particle* particle){
    if(particle == nullptr){
        std::cout << " No particle found for printing.\n";
        return;
    }

    std::cout << " Optional Particle: "
    << " | position: " << particle->position() << "\n"
    << " | velocity: " << particle->velocity() << "\n"
    << " | speed: " << particle->speed() << "\n";
}

// particle must exist; mutate real particle by reference
void applyVelocityKick(Particle& particle, const Vec2& deltaVelocity){
    particle.addVelocity(deltaVelocity);
}

// particle may not exist; pointer can be null pointer
void applyVelocityKickIfPresent(Particle* particle, const Vec2& deltaVelocity){
    if (particle == nullptr){
        std::cout << " No particle found. Kick skipped" << "\n";
        return;
    }
    particle->addVelocity(deltaVelocity);
}

void runCopyLifetimeDemo() {
    std::cout << "\n=== Day 7 Copy lifetime demo\n";

    Particle original{Vec2{1.0,1.0}, Vec2{2.0,0.0}};

    std::cout << "\nCreating copied from original:\n";
    Particle copied = original;

    std::cout << "\nCreating assigned, then assigning original into it:\n";
    Particle assigned;
    assigned = original;

    std::cout << "\nPushing particles into vector:\n";
    std::vector<Particle> demoParticles;

    std::cout << "Initial capacity: " << demoParticles.capacity() << "\n";

    demoParticles.push_back(original);
    std::cout << "After push 1 | size: " << demoParticles.size()
              << " | capacity: " << demoParticles.capacity() << "\n";

    demoParticles.push_back(copied);
    std::cout << "After push 2 | size: " << demoParticles.size()
              << " | capacity: " << demoParticles.capacity() << "\n";

    demoParticles.push_back(assigned);
    std::cout << "After push 3 | size: " << demoParticles.size()
              << " | capacity: " << demoParticles.capacity() << "\n";

}

int main() {
    
    runCopyLifetimeDemo();
    
    Simulator sim;
    sim.addParticle(makeParticle(Vec2{0.0,0.0},Vec2{0.0,0.0}));
    sim.addParticle(makeParticle(Vec2{5.0,0.0},Vec2{0.0,2.0}));
    sim.addParticle(makeParticle(Vec2{0.0,-2.0},Vec2{1.0,2.0}));

    double dt = 0.1;

    std::cout << "Particle count: " << sim.particleCount() << "\n";
    std::cout << "\nInitial particles: \n";
    const std::vector<Particle>& particles = sim.getparticles();

    for(std::size_t i = 0; i < particles.size(); i++){
        printParticle(i, particles[i]);
    }

    const Simulator& readOnlySim = sim;
    printParticleIfPresent(readOnlySim.tryGetParticle(0));
    printParticleIfPresent(readOnlySim.tryGetParticle(100));


    std::cout << "\n Applying velocity kicks: \n ";
    // particleAt(index): must-exist access. Throws if index is invalid.
    // tryGetParticle(index): maybe-exists access. Returns nullptr if index is invalid.
    applyVelocityKick(sim.particleAt(0), Vec2{0.0,0.5});
    applyVelocityKickIfPresent(sim.tryGetParticle(1), Vec2{0.0,1.0});
    applyVelocityKickIfPresent(sim.tryGetParticle(100), Vec2{10.0,1.0});

    std::cout << "\nAfter kicks: \n";

    for(std::size_t i = 0; i < particles.size(); i++){
        printParticle(i, particles[i]);
    }

    for(int step = 1; step <= 10; step++){
        sim.update(dt);
    }

    std::cout << "\n After update: \n";

    for(std::size_t i = 0; i < particles.size(); i++){
        printParticle(i, particles[i]);
    }

    return 0;
}