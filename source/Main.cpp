#include <chrono>
#include <iostream>

#include "RayTracer.h"
#include "Scene.h"
#include "ViewPlane.h"

#include "Sphere.h"

void addSphere(Scene& scene, const glm::dvec3& position, double radius, const glm::vec3& color) {
    auto sphere = std::make_unique<Sphere>(position, radius);
    sphere->material->color = color;
    scene.geometry.push_back(std::move(sphere));
}

// Scene building function
Scene build()
{
    Scene scene;
    scene.material->color = glm::vec3{0.f, 0.f, 0.f};
	// Mid
	addSphere(scene, {0.0, 0.0, 0.0}, 60.0, {1.f, 0.f, 0.f});
	// Left top
	addSphere(scene, {-100.0, 100.0, 0.0}, 30.0, {0.f, 0.f, 1.f});
	// Right bottom
	addSphere(scene, {50.0, -50.0, 0.0}, 20.0, {0.f, 1.f, 0.f});
	// Mid top
	addSphere(scene, {0.0, 50.0, 0.0}, 30.0, {1.f, 1.f, 0.f});
	// Mid front
	addSphere(scene, {0.0, 0.0, 60.0}, 10.0, {1.f, 0.f, 1.f});

    return scene;
}

Image render(const Scene& scene, const RayTracer& tracer, const ViewPlane& viewPlane)
{
    std::cout << "Start rendering scene" << std::endl;

    // Scene render with time measurement
    std::chrono::high_resolution_clock hrc;
    auto begin = hrc.now();
    auto image = tracer.render(scene, viewPlane);
    auto end = hrc.now();

    // Rendering time in milliseconds
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "End rendering scene" << std::endl;
    std::cout << "Rendering time: " << diff.count() / 1000.f << " seconds" << std::endl;

    return image;
}

int main(int argc, const char** argv)
{
    Scene scene = build();
    RayTracer tracer;

    ViewPlane viewPlane;
    viewPlane.verticalResolution = 200;
    viewPlane.horizontalResolution = 200;
    viewPlane.pixelSize = 1.0;
    viewPlane.gamma = 1.0;

    auto image = render(scene, tracer, viewPlane);

    if (!save(image, "out.png"))
    {
        std::cout << "Failed to write image file" << std::endl;
        return 0;
    }
    std::cout << "Image written to file" << std::endl;

    return 0;
}