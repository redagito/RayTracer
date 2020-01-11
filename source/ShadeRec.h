#pragma once

#include <memory>

#include <glm/glm.hpp>

#include "material/Material.h"

/**
 * Stores shading information for a ray-geometry hit
 * TODO Better name
 */
struct ShadeRec
{
	// Did the ray hit
	// TODO Duplicate info, is returned from hit function
    bool hit = false;

	// Coordinates of hit point in world space
	glm::dvec3 point;

	// Normal vector at hit point in world space
	glm::dvec3 normal;

	// Material of the geometry object that has been hit
	std::shared_ptr<Material> material;
};