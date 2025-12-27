#pragma once

#include <cmath>
#include <iostream>

class vec3
{
public:
    double xyz[3];
    constexpr vec3() noexcept : xyz{0, 0, 0} {}
    constexpr explicit vec3(double x, double y, double z) noexcept : xyz{x, y, z} {}

    ~vec3() = default;

    constexpr double x() const noexcept {return xyz[0];}
    constexpr double y() const noexcept {return xyz[1];}
    constexpr double z() const noexcept {return xyz[2];}

    constexpr vec3 operator-() const noexcept {return vec3(-xyz[0], -xyz[1], -xyz[2]); }
    constexpr double operator[](uint64_t i) const noexcept{ return xyz[i]; }
    constexpr double& operator[](uint64_t i) noexcept { return xyz[i]; }

    constexpr vec3& operator+=(const vec3& v) noexcept {
        xyz[0] += v[0];
        xyz[1] += v[1];
        xyz[2] += v[2];
        return *this;
    }

    constexpr vec3& operator*=(double t) noexcept {
        xyz[0] *= t;
        xyz[1] *= t;
        xyz[2] *= t;
        return *this;
    }

    constexpr vec3& operator/=(double t) noexcept {
        return *this *= 1/t;
    }

    double length() const noexcept { //turns out, sqrt is constexpr in c++26
        return sqrt(length_squared());
    }

    constexpr double length_squared() const noexcept {
        return xyz[0] * xyz[0] + xyz[1] * xyz[1] + xyz[2] * xyz[2];
    }
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) { return out << v.xyz[0] << " " << v.xyz[1] << " " << v.xyz[2]; }

inline constexpr vec3 operator+(const vec3& u, const vec3& v) noexcept { return vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]); }

inline constexpr vec3 operator-(const vec3& u, const vec3& v) noexcept { return vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]); }

inline constexpr vec3 operator*(const vec3& u, const vec3& v) noexcept { return vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]); } // Hadamard Product

inline constexpr vec3 operator*(double t, const vec3& v) noexcept { return vec3(t * v[0], t * v[1], t * v[2]); } 

inline constexpr vec3 operator*(const vec3& v, double t) noexcept { return t * v; } 

inline constexpr vec3 operator/(const vec3& v, double t) noexcept { return (1 /t) * v; } 

inline constexpr double dot(const vec3& u, const vec3& v) noexcept { return u[0] * v[0] + u[1] * v[1] + u[2] * v[2]; }

inline constexpr vec3 cross(const vec3& u, const vec3& v) noexcept { 
    return vec3(
        u[1] * v[2] - u[2] * v[1],
        u[2] * v[0] - u[0] * v[2],
        u[0] * v[1] - u[1] * v[0]
    ); 
}

inline vec3 unit_vector(const vec3& v) noexcept { return v / v.length(); }

