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

    Particle& particleAt(std::size_t index) {
        return particles_.at(index);
    }

    const Particle& particleAt(std::size_t index) const {
        return particles_.at(index);
    }

    Particle* tryGetParticle(std::size_t index) {
        if (index >= particles_.size()) {
            return nullptr;
        }

        return &particles_[index];
    }

    const Particle* tryGetParticle(std::size_t index) const {
        if (index >= particles_.size()) {
            return nullptr;
        }

        return &particles_[index];
    }

    void update(double dt) {
        for(Particle& particle : particles_){
            particle.update(dt);
        }
    }
};
