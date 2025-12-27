#include "ppm_writer.h"

#include "vec3.h"
#include "color.h"

#include <iostream>


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


void PPMWriter::write()
{
    m_file << "P3\n";
    m_file << m_width << " " << m_height << "\n255\n";

    for (uint64_t j = 0; j < m_height; j++) {
        std::cout << "Remaining lines: " << m_height - j << "\n";
        for (uint64_t i = 0; i < m_width; i++) {
            color pixel_color = color(static_cast<double>(i) / (m_width-1), static_cast<double>(j) / (m_height-1), 0.0);

            write_color(m_file, pixel_color);
        }
    }
}
