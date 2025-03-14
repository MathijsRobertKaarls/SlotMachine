#include "bminigames.h"

#include "wheel.h"

bminigames::bminigames(std::mt19937 &gen) : gen_(gen)
{
}

bminigames::~bminigames()
{
}

int bminigames::play_b_minigame()
{
    for(int i = 0; i < 3; ++i)
    {
        std::array<int, 3> random_generation_one = random_values();
        std::array<int, 3> random_generation_two = random_values();
        for(int j = 0; j < 3; ++j)
        {
            if (random_generation_one[j] == random_generation_two[j])
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
    }
    return mega_wheel();
}

std::array<int, 3> bminigames::random_values()
{
    std::array<int, 3> array;
    for(int i = 0; i < 3; ++i)
    {
        array[i] = std::uniform_int_distribution<int>(0,2)(gen_);
    }
    return array;
}

int bminigames::mega_wheel()
{
    wheel awheel(MEGAWHEEL, gen_);
    std::cout << "MEGA WHEEL: " << awheel.multiplier() << "\n";
    return awheel.multiplier();
}
