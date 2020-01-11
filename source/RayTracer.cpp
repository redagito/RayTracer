#include "RayTracer.h"

Image RayTracer::render(const Scene& scene, const ViewPlane& viewPlane) const
{
    Image image{viewPlane.horizontalResolution, viewPlane.verticalResolution};

    for (unsigned int vertical = 0; vertical < viewPlane.verticalResolution; ++vertical)
    {
        for (unsigned int horizontal = 0; horizontal < viewPlane.horizontalResolution; ++horizontal)
        {
			// Ray origin in world coordinates
			// World coordinate system is right-handed
            //
			// +y
			// |     -z
			// |    /
			// |  /
			// |/_________+x
			//
			// View plane is centered at x/y = 0/0
            double x = viewPlane.pixelSize * (horizontal - 0.5 * (viewPlane.horizontalResolution - 1.0));
            double y = viewPlane.pixelSize * (vertical - 0.5 * (viewPlane.verticalResolution - 1.0));
			
			Ray ray;
            ray.direction = viewPlane.rayDirection;
            ray.origin = glm::dvec3{x, y, viewPlane.zPos};

			auto pixelColor = trace(scene, ray);
			// Image coordinates start in top left corner
			// Need to flip over x axis
            image.set(horizontal, viewPlane.verticalResolution - vertical - 1, pixelColor);
		}
    }

	return image;
}

glm::vec3 RayTracer::trace(const Scene& scene, const Ray& ray) const {
	ShadeRec shadeRec;
	double tMin;

	scene.hit(ray, tMin, shadeRec);
	return shadeRec.material->color;
}