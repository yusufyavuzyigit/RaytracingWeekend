#pragma once

#include "core.h"
#include "hittable.h"

class sphere : public hittable {
public:
    constexpr sphere(const point3& center, double radius) noexcept : m_center(center), m_radius(radius) {}

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        auto oc = m_center - r.origin();
        auto a = dot(r.direction(), r.direction());
        auto h = dot(r.direction(), oc);
        auto c = dot(oc, oc) - m_radius * m_radius;
        auto discriminant = h * h - a * c;
        if (discriminant < 0)
            return false;
        
        auto sqrtd = sqrt(discriminant);

        auto root = (h- sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root) {
            root = (h + sqrtd) / a;
            if (root <= ray_tmin || ray_tmax <= root)
                return false;
        }
        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - m_center) / m_radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    }
private:
    point3 m_center;
    double m_radius;
};