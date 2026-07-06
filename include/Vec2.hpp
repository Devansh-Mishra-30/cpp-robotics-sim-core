#pragma once
#include <iostream>

struct Vec2{
    double x;
    double y;


Vec2() : x(0.0),y(0.0) {}

Vec2(double xValue,double yValue) : x(xValue),y(yValue) {}

Vec2 operator+(const Vec2& other) const {
    return Vec2(x+other.x, y+other.y);
}

Vec2 operator*(double scalar) const {
    return Vec2(x*scalar, y*scalar);
}
};

inline std::ostream& operator<<(std::ostream& out, const Vec2& v){
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}