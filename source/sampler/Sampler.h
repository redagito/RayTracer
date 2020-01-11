#pragma once

#include <vector>

#include <glm/glm.hpp>

/**
 * Sampler base class
 * Provides sample point on an area
 */
class Sampler
{
   public:
    // Generate sample patterns in unit square
    void generate();

    // Shuffle indices
    void shuffleIndices();

    // Shuffle samples in each pattern
    void shuffleSamples();

    // Get next sample in unit square
    glm::dvec2 sampleUnitSquare();

   protected:
    // Generate sample pattern in unit square
    virtual void generate(size_t sampleCount, std::vector<glm::dvec2>& samples) = 0;

   private:
    size_t sampleCount = 0;
    size_t setCount = 0;
    std::vector<glm::dvec2> samples;
};