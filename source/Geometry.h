#pragma once

#include <memory>

#include "Ray.h"
#include "ShadeRec.h"
#include "material/Material.h"

class Geometry
{
   public:
    virtual ~Geometry();

    /**
     * Hit test for geometry
     * @param ray Ray to test for hit
     * @param tMin Ray distance until closest hit
     * @param shadeRec Stores hit info if hit
     */
    virtual bool hit(const Ray& ray, double& tMin, ShadeRec& shadeRec) const = 0;

    std::shared_ptr<Material> material = std::make_shared<Material>();
};