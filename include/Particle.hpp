#pragma once
#include "Vec2.hpp"
class Particle{
private:
    Vec2 position_;
    Vec2 velocity_;
public:
    Particle() : position_(), velocity_() {}

    Particle(const Vec2& startPosition, const Vec2& startVelocity)
        : position_(startPosition), velocity_(startVelocity) {}
    
    Vec2 position() const {
        return position_;
    }

    Vec2 velocity() const {
        return velocity_;
    }

    double speed() const{
        return velocity_.length();
    }

    void update(double dt){
        position_ = position_ + velocity_ * dt;
    }
};