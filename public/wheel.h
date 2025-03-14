#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#include <random>

#include "macros.h"

enum wheels {WHEEL = 0, LUCKYWHEEL = 1, MEGAWHEEL = 2};

class wheel
{
public:
    wheel(wheels wheel_type, std::mt19937& gen);
    int multiplier();
    ~wheel();
private:
    void initialize_wheel();
    void initialize_lucky_wheel();
    void initialize_mega_wheel();

    int multiplier_ = 0;

    std::mt19937 gen_;
};

#endif //WHEEL_H

