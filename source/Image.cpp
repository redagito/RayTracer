#include "Image.h"

#include <stdexcept>
#include <algorithm>

#include <lodepng.h>

Image::Image(unsigned int width, unsigned int height, const glm::vec3& color) : width(width), height(height)
{
    data.resize(static_cast<size_t>(width) * static_cast<size_t>(height));
    std::fill(data.begin(), data.end(), color);
}

void Image::set(unsigned int width, unsigned int height, const glm::vec3& color)
{
    if (width >= this->width || height >= this->height)
        throw std::runtime_error{"Exceeds image size"};

    size_t index = (static_cast<size_t>(height) * static_cast<size_t>(this->width) + width);
    data[index] = color;
}

const std::vector<glm::vec3>& Image::getData() const { return data; }

bool save(const Image& image, const std::string& fileName)
{
    std::vector<unsigned char> data;
    data.reserve(static_cast<size_t>(image.width) * static_cast<size_t>(image.height));

    for (const auto& pixel : image.getData())
    {
		data.push_back(static_cast<unsigned char>(pixel.r * 255.f));
		data.push_back(static_cast<unsigned char>(pixel.g * 255.f));
		data.push_back(static_cast<unsigned char>(pixel.b * 255.f));
    }

    return lodepng::encode(fileName, data, image.width, image.height, LCT_RGB) == 0;
}