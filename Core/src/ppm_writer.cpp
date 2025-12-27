#include "ppm_writer.h"



// TODO: LOOK AT ADDING DIFFERENT OPTIONS WITH STBIMAGE

PPMWriter::PPMWriter(uint64_t width, uint64_t height)
    : m_width(width), m_height(height), m_file(m_dir/m_name, std::ofstream::out | std::ofstream::trunc)
{
    if (!std::filesystem::exists(m_dir))
        std::filesystem::create_directory(m_dir);

    if (!m_file.is_open()) {
        std::cerr << "Failed to create render.ppm file" << std::endl;
    }
}

// Camera
color ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }
    
    vec3 unit_dir = unit_vector(r.direction());
    float a = 0.5*(unit_dir.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

void PPMWriter::write()
{
    //Camera stuff, here for now
    float focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (static_cast<double>(m_width)/m_height);
    point3 camera_center = point3(0, 0, 0);

    hittable_list world;

    world.add(std::make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(std::make_shared<sphere>(point3(0,-100.5,-1), 100));

    vec3 viewport_u = vec3(viewport_width, 0, 0);
    vec3 viewport_v = vec3(0, -viewport_height, 0);

    vec3 pixel_delta_u = viewport_u / m_width;
    vec3 pixel_delta_v = viewport_v / m_height;

    auto viewport_upper_left = camera_center
                             - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    //

    m_file << "P3\n";
    m_file << m_width << " " << m_height << "\n255\n";

    for (uint64_t j = 0; j < m_height; j++) {
        std::cout << "Remaining lines: " << m_height - j << "\n";
        for (uint64_t i = 0; i < m_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, world);
            write_color(m_file, pixel_color);
        }
    }
}
