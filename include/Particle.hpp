#pragma once
#include "Vec2.hpp"

struct Particle{
    Vec2 position;
    Vec2 velocity;

    Particle() : position(), velocity() {}

    Particle(const Vec2& startPosition, const Vec2& startVelocity) :
    position(startPosition), velocity(startVelocity) {}

    void update(double dt){
        position = position + velocity*dt;
    }
};