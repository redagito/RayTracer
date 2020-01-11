#include "Sphere.h"

#include <cmath>

#include "Config.h"

Sphere::Sphere(glm::dvec3 center, double radius) : center(center), radius(radius) {}

bool Sphere::hit(const Ray& ray, double& tMin, ShadeRec& shadeRec) const
{
    auto displacement = ray.origin - center;

    auto a = glm::dot(ray.direction, ray.direction);
    auto b = 2.0 * glm::dot(displacement, ray.direction);
    auto c = glm::dot(displacement, displacement) - radius * radius;
    auto discrimenant = b * b - 4.0 * a * c;

    // No hit
    if (discrimenant < 0.0)
        return false;

    // Quadric equation, solve for either smaller or larger root
    auto e = std::sqrt(discrimenant);
    auto denominator = 2.0 * a;

    // Smaller root
    auto t = (-b - e) / denominator;

    if (t <= epsilon)
    {
        // Larger root
        t = (-b + e) / denominator;
    }

    if (t <= epsilon)
    {
        // No hit
        return false;
    }

    // Hit
    tMin = t;
    shadeRec.normal = (displacement + t * ray.direction) / radius;
    shadeRec.point = ray.origin + ray.direction * t;
    shadeRec.material = material;

    return true;
}