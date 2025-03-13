#ifndef BMINIGAMES_H
#define BMINIGAMES_H

#include <iostream>
#include <random>
#include <array>

class bminigames
{
public:
    bminigames(std::mt19937& gen);
    ~bminigames();
    int play_b_minigame();
private:
    std::mt19937 gen_;
    std::array<int,3> random_values();
    int mega_wheel(); //30 wheel with 3 spins -> 10 tens, 10 twenties, 3 fifties, 2 hunderds, 1 twohunderdfifty
};

#endif //BMINIGAMES_H