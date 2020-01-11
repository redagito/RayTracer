#include "sampler/Jittered.h"

#include <cmath>

#include "Random.h"

void Jittered::generate(size_t sampleCount, std::vector<glm::dvec2>& samples)
{
    size_t s = (size_t)std::sqrt(sampleCount);

    for (size_t i = 0; i < s; ++i)
    {
        for (size_t j = 0; j < s; ++j)
        {
            glm::dvec2 sample{(j + random<double>()) / s, (i + random<double>()) / s};
            samples.push_back(sample);
        }
    }
}
