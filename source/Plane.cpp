#include "Plane.h"

#include "Config.h"

bool Plane::hit(const Ray& ray, double& tMin, ShadeRec& shadeRec) const
{
	// Distance to the plane
    double distance = glm::dot(point - ray.origin, normal) / glm::dot(ray.direction, normal);

	// No hit
    if (distance <= epsilon)
        return false;

	// Hit
    tMin = distance;
    shadeRec.normal = normal;
    shadeRec.point = ray.origin + ray.direction * distance;
    shadeRec.material = material;

    return true;
}