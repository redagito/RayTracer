#pragma once

#include "Scene.h"
#include "ViewPlane.h"
#include "Image.h"
#include "Ray.h"
#include "ShadeRec.h"

class RayTracer
{
   public:
    Image render(const Scene& scene, const ViewPlane& viewPlane) const;

   private:
    /**
	* Trace single ray in scene
	*/
    glm::vec3 trace(const Scene& scene, const Ray& ray) const;
};