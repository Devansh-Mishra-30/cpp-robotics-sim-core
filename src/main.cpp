#include <iostream>
#include "Particle.hpp"

int main(){
    Particle p(Vec2{0.0,0.0}, Vec2{1.0,2.0});
    double dt = 0.1;
    std::cout << "Initial position: " << p.position << std::endl;

    for(int step=1; step<=10; step++){
        p.update(dt);
        std::cout << "Step: " << step << ": " << p.position << std::endl;
    }
    return 0;
}