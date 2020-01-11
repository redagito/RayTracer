#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "Geometry.h"

/**
* Stores geometry for rendering
*/
class Scene : public Geometry
{
   public:
	std::vector<std::unique_ptr<Geometry>> geometry;
	
    bool hit(const Ray& ray, double& tMin, ShadeRec& shadeRec) const;
};