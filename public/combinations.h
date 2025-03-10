#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <array>

#include "macros.h"

enum combs {x5000=0, x4000=2, x4001=5, x4002=500, x4003=30, x4004=500};

x0100<combs, x0005> seek_combinations(x0100<x1001, x0005> x0200);

bool two_of_a_kind(std::array<int, 10>& array);
bool three_of_a_kind(std::array<int, 10>& array);
bool five_of_a_kind(std::array<int, 10>& array);
bool straight_of_three(std::array<int, 10>& array);
bool straight_of_five(std::array<int, 10>& array);


#endif //COMBINATIONS_H