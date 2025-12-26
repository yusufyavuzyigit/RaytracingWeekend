#include "ppm_writer.h"
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
            double r = static_cast<double>(i) / (m_width-1);
            double g = static_cast<double>(j) / (m_height-1);
            double b = 0.0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            m_file << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}
