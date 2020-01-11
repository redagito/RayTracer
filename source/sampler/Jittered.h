#pragma once

#include "sampler/Sampler.h"

class Jittered : public Sampler
{
   private:
    void generate(size_t sampleCount, std::vector<glm::dvec2>& samples) override;
};