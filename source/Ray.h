#pragma once

#include <glm/glm.hpp>

struct Ray
{
	// Origin of the ray in world coordinates
    glm::dvec3 origin;
	// Normalized direction vector of the ray
    glm::dvec3 direction;
};