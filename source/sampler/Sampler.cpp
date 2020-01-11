#include "sampler/Sampler.h"

void Sampler::generate()
{
    samples.clear();
    samples.reserve(sampleCount * setCount);

    for (size_t s = 0; s < setCount; ++s)
    {
        generate(sampleCount, samples);
    }
}

void Sampler::shuffleIndices() {}

void Sampler::shuffleSamples() {}

glm::dvec2 Sampler::sampleUnitSquare() { return glm::dvec2(); }