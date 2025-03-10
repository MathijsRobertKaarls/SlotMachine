#ifndef RNG_H
#define RNG_H

#include <random>
#include <array>

#include "macros.h"

x0100<int, x0005> generate_random_numbers(std::mt19937& gen);

bool generate_random_numbers_one(std::mt19937& gen);

#endif //RNG_H