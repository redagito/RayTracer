#include "Scene.h"

bool Scene::hit(const Ray& ray, double& tMin, ShadeRec& shadeRec) const {
	shadeRec.material = material;
	shadeRec.hit = false;

	for (const auto& object : geometry)
    {
		ShadeRec sr;
		double distance = 0.0;
		if (object->hit(ray, distance, sr))
        {
			// Ray hit an object
            if (shadeRec.hit == false || (shadeRec.hit == true && distance < tMin))
            {
				shadeRec = sr;
				shadeRec.hit = true;
				tMin = distance;
			}
		}
	}
	return shadeRec.hit;
}