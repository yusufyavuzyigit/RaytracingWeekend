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
};

