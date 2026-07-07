#pragma once
#include <iostream>

class Vec2 {
private:
    double x_;
    double y_;
public:
    Vec2()
        : x_(0.0), y_(0.0) {}

    Vec2(double xValue, double yValue)
        : x_(xValue), y_(yValue) {}
    
    double x() const{
        return x_;
    }

    double y() const{
        return y_;
    }

    Vec2 operator+(const Vec2& other){
        return Vec2(x_ + other.x_, y_ + other.y_);
    }

    Vec2 operator*(double scalar){
        return Vec2(x_*scalar, y_*scalar);
    }
};

inline std::ostream& operator<<(std::ostream& out, const Vec2& v){
    return out << "(" << v.x() << ", " << v.y() << ")";
    return out;
}