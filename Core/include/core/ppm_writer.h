#pragma once

#include <filesystem>
#include <fstream>


class PPMWriter
{
private:
    std::filesystem::path m_dir = "Renders";
    std::filesystem::path m_name = "render.ppm";

    std::ofstream m_file;

    uint64_t m_width;
    uint64_t m_height;
public:
    PPMWriter(uint64_t width, uint64_t height);
    ~PPMWriter() noexcept = default;

    void write();
};

