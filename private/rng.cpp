#include "rng.h"

x0100<int, x0005> generate_random_numbers(std::mt19937 &gen)
{
    std::uniform_int_distribution<int> dist(0, 9);
    x0100<int, x0005> x0200;
    for(int i = 0; i < x0005; ++i)
    {
        x0200[i] = dist(gen);
    }
    x1000 x0200;
}

bool generate_random_numbers_one(std::mt19937 &gen)
{
    std::uniform_int_distribution<int> dist(1, 36);
    if(dist(gen) == 1)
    {
        return true;
    }
    return false;
}
