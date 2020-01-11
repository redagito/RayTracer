#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>

/**
 * \brief Stores RGB image data
 * Currently supports loading from and saving to png files
 * Image coordinates start at top left corner with 0/0
 * and end in the bottom right corner with width-1/height-1
 */
class Image
{
   public:
    const unsigned int width;
    const unsigned int height;

    /**
     * \brief Default constructor
     */
    Image(unsigned int width, unsigned int height, const glm::vec3& color = {0.f, 0.f, 0.f});

    /**
     * \brief Sets pixel at position to specified value
     */
	void set(unsigned int width, unsigned int height, const glm::vec3& color);

    /**
     * \brief Returns image data
     */
    const std::vector<glm::vec3> &getData() const;

   private:
    std::vector<glm::vec3> data;
};

/**
* \brief Save to image file
* Saving clamps values
*/
bool save(const Image& image, const std::string& fileName);