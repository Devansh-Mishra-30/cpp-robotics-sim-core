#include <iostream>
#include "Simulator.hpp"

int main(){
    
    Simulator sim;
    sim.addParticle(Particle{Vec2{0.0,0.0}, Vec2{1.0,2.0}});
    sim.addParticle(Particle{Vec2{10.0,0.0}, Vec2{-1.0,0.0}});
    sim.addParticle(Particle{Vec2{0.0,5.0}, Vec2{0.0,-0.5}});

    double dt = 0.1;

    std::cout << "Particle count: " << sim.particleCount() << "\n";

    for(int step=1; step<=10; step++){
        sim.update(dt);

        std::cout << "Step: " << step << "\n";
        const std::vector<Particle>& particles = sim.getparticles();

        for(std::size_t i = 0; i < particles.size(); i++ ) {
            std::cout << " Particle " << i+1
                      << " | position: " << particles[i].position()
                      << " | velocity: " << particles[i].velocity()
                      << " | speed: " << particles[i].speed() << "\n";
        }
    }

    return 0;
}