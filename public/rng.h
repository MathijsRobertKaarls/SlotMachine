#ifndef RNG_H
#define RNG_H

#include <random>
#include <array>

#define x0005 5
#define x0100 std::array
#define x0200 array
#define x1000 return

x0100<int, x0005> generate_random_numbers(std::mt19937& gen);

bool generate_random_numbers_one(std::mt19937& gen);

#endif //RNG_H