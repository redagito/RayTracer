#pragma once

#include <glm/glm.hpp>

#include "Geometry.h"

class Sphere : public Geometry
{
   public:
    Sphere() = default;
    Sphere(glm::dvec3 center, double radius);

    bool hit(const Ray& ray, double& tMin, ShadeRec& shadeRec) const override;

	glm::dvec3 center;
    double radius = 0.0;
};