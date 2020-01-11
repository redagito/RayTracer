#pragma once

#include <glm/glm.hpp>

class Material
{
   public:
    virtual ~Material();

	// Diffuse color
    glm::vec3 color = glm::vec3{1, 0.1, 0.6};
};