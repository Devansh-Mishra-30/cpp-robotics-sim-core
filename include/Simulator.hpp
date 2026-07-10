#pragma once

#include <cstddef>
#include <vector>

#include "Particle.hpp"

class Simulator {
private:
    std::vector<Particle> particles_;

public:
    Simulator() = default;
    
    void addParticle(const Particle& particle) {
        particles_.push_back(particle);
    }

    std::size_t particleCount() const {
        return particles_.size();
    }

    const std::vector<Particle>& getparticles() const {
        return particles_;
    }

    void update(double dt) {
        for(Particle& particle : particles_){
            particle.update(dt);
        }
    }
};
