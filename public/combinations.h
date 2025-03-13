#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <array>
#include <vector>

#include "macros.h"

enum payout_pattern {x5000=0, x4000=20, x4001=50, x4003=1000, x4002=5000, x4004=5000};

struct pattern_order
{
    payout_pattern pp = x5000;
    std::array<int, 5> o = {0};
};

struct data_table
{
    std::array<int, 5> original {0};
    std::array<int, 10> bitmask {0};  
    std::vector<pattern_order> vector {0};
};

x0100<payout_pattern, x0005> seek_combinations(x0100<x1001, x0005> x0200);

pattern_order two_of_a_kind(data_table& dt);
pattern_order three_of_a_kind(data_table& dt);
pattern_order five_of_a_kind(data_table& dt);
pattern_order straight_of_three(data_table& dt);
pattern_order straight_of_five(data_table& dt);


#endif //COMBINATIONS_H