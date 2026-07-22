#pragma once
#include "Vec2.hpp"
class Particle{
private:
    Vec2 position_;
    Vec2 velocity_;
public:
    Particle() : position_(Vec2{0.0,0.0}), velocity_(Vec2{0.0,0.0}) {};
    Particle(const Vec2& startPosition, const Vec2& startVelocity) : position_(startPosition), velocity_(startVelocity) {}; 
    const Vec2& position() const{
        return position_;
    }
    const Vec2& velocity() const{
        return velocity_;
    }
    double speed() const{
        return velocity_.length();
    }
    void update(double dt){
        position_ += velocity_ * dt;
    }
    void setVelocity(const Vec2& newVelocity){
        velocity_ = newVelocity;
    }
    void addVelocity(const Vec2& deltaVelocity){
        velocity_ += deltaVelocity;
    }
    void translate(const Vec2& displacement){
        position_ += displacement;
    }
};
