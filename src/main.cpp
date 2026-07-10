#include <iostream>
#include "Particle.hpp"

int main(){
    Vec2 a{3.0,4.0};
    Vec2 b{1.0,2.0};
    Particle p(Vec2{0.0,0.0}, Vec2{1.0,2.0});
    double dt = 0.1;
    Vec2 zero;

    std::cout << "a: " << a << "\n" << "b: " << b << "\n"
    << "a length: " << a.length() << "\n"
    << "a normalized: " << a.normalized() << "\n";

    Vec2 c = a + b;
    std::cout << "c = a + b: " << c << "\n";

    a+=b;
    std::cout << "after a += b, a: " << a << "\n";

    a*=2.0;
    std::cout << "after a *= 2, a: " << a << "\n";

    std::cout << "zero: " << zero << "\n" << "zero is near zero: " 
    << zero.isNearZero() << "\n" << "zero normalized: " 
    << zero.normalized() << "\n";

    for(int step = 1; step <=10; step++){
        p.update(dt);
    }

    std::cout << "particle final position: " << p.position() 
    << "\n" << "particle speed: " << p.speed() << "\n";

    return 0;
}