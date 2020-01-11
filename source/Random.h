#pragma once

#include <cmath>

template <typename T>
T random() { return (T)std::rand() / (T)RAND_MAX; }