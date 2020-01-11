#pragma once

#include <array>

#include "Geometry.h"

class Triangle : public Geometry
{
   public:
    bool hit(const Ray& ray, double& tMin, ShadeRec& shadeRec) const override;

	std::array<glm::dvec3, 3> vertices;
};