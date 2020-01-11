#pragma once

#include <glm/glm.hpp>

#include "Geometry.h"

/**
* Infinite plane
*/
class Plane : public Geometry
{
   public:
	/**
	* Hit test for infinite plane
	*/
    bool hit(const Ray& ray, double& tMin, ShadeRec& shadeRec) const override;

	// Point on the plane in world coordinated
	glm::dvec3 point;

	// Normal vector of the plane
    glm::dvec3 normal;

};