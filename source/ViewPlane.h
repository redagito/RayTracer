#pragma once

/**
* View plane from which the scene is rendered
* The plane is centered on x/y/z = 0/0/100 and is looking along the negative z axis
*/
struct ViewPlane
{
    unsigned int horizontalResolution = 100;
    unsigned int verticalResolution = 100;

	// Lower pixel size to "zoom" in 
	float pixelSize = 1.0;
	// Gamma value of the monitor
    float gamma = 1.0;

	// Position along the z axis
    double zPos = 100.0;
    // Normalized ray direction in negative z axis
    glm::dvec3 rayDirection = glm::dvec3{0.0, 0.0, -1.0};
};