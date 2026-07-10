#pragma once
#include <iostream>
#include <cmath>

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

    double squaredLength() const{
        return x_ * x_ + y_ * y_; 
    }

    double length() const{
        return std::sqrt(squaredLength()); 
    }

    double dot(const Vec2& other) const{
        return x_ * other.x_ + y_ * other.y_;
    }

    Vec2 operator+(const Vec2& other) const{
        return Vec2(x_ + other.x_, y_ + other.y_);
    }

    Vec2 operator-(const Vec2& other) const{
        return Vec2(x_ - other.x_, y_ - other.y_);
    }

    Vec2& operator+=(const Vec2& other) {
        x_+=other.x_;
        y_+=other.y_;
        return *this;
    }

    Vec2& operator-=(const Vec2& other) {
        x_-=other.x_;
        y_-=other.y_;
        return *this;
    }

    Vec2& operator*=(const double d) {
        x_*=d;
        y_*=d;
        return *this;
    }

    Vec2 normalized() const {
        double len = length();
        if(len < 1e-9){
            return Vec2{0.0,0.0};
        }
        return Vec2{x_/len, y_/len};
    }

    bool isNearZero(double epsilon = 1e-9) const {
        return squaredLength() < epsilon * epsilon;
    }

    Vec2 operator*(double scalar) const{
        return Vec2(x_*scalar, y_*scalar);
    }
};

inline std::ostream& operator<<(std::ostream& out, const Vec2& v){
    return out << "(" << v.x() << ", " << v.y() << ")";
}