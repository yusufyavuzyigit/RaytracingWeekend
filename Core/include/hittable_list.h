#pragma once

#include "core.h"

#include "hittable.h"

#include <vector>

class hittable_list : public hittable
{
public:
    std::vector<std::shared_ptr<hittable>> objects;

    hittable_list() {}
    explicit hittable_list(std::shared_ptr<hittable> object) { add(object); }

    void clear() noexcept { objects.clear(); }

    void add(const std::shared_ptr<hittable>& object) { objects.push_back(object); }

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        hit_record temp;
        bool hit_anything = false;
        auto closest_so_far = ray_tmax;

        for (const auto& object : objects) {
            if (object->hit(r, ray_tmin, closest_so_far, temp)) {
                hit_anything = true;
                closest_so_far = temp.t;
                rec = temp;
            }
        }

        return hit_anything;
    }
};