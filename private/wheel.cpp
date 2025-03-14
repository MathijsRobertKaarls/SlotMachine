#include "wheel.h"

#include <iostream>
#include <vector>

wheel::wheel(wheels wheel_type, std::mt19937& gen) : gen_(gen)
{
    if(wheel_type == WHEEL)
    {
        initialize_wheel();
    }
    if(wheel_type == LUCKYWHEEL)
    {
        initialize_lucky_wheel();
    }
    if(wheel_type == MEGAWHEEL)
    {
        initialize_mega_wheel();
    }
}

int wheel::multiplier()
{
    return multiplier_;
}

wheel::~wheel()
{
}

void wheel::initialize_wheel()
{
    std::vector<int> numbers;
    for(int i = 0; i < 5; ++i)
    {
        numbers.push_back(1);
    }
    for(int i = 0; i < 5; ++i)
    {
        numbers.push_back(3);
    }
    for(int i = 0; i < 3; ++i)
    {
        numbers.push_back(5);
    }
    for(int i = 0; i < 2; ++i)
    {
        numbers.push_back(10);
    }
    for(int i = 0; i < 2; ++i)
    {
        numbers.push_back(20);
    }
    for(int i = 0; i < 1; ++i)
    {
        numbers.push_back(0);
    }
    int number = std::uniform_int_distribution<int>(0, numbers.size())(gen_);
    multiplier_ += numbers[number] * EUR;
}    

void wheel::initialize_lucky_wheel()
{
    std::vector<int> numbers;
    for(int i = 0; i < 5; ++i)
    {
        numbers.push_back(1);
    }
    for(int i = 0; i < 5; ++i)
    {
        numbers.push_back(5);
    }
    for(int i = 0; i < 3; ++i)
    {
        numbers.push_back(10);
    }
    for(int i = 0; i < 1; ++i)
    {
        numbers.push_back(20);
    }
    for(int i = 0; i < 1; ++i)
    {
        numbers.push_back(50);
    }
    for(int i = 0; i < 1; ++i)
    {
        numbers.push_back(100);
    }
    for(int i = 0; i < 0; ++i)
    {
        numbers.push_back(0);
    }
    int number = std::uniform_int_distribution<int>(0, numbers.size())(gen_);
    multiplier_ += numbers[number] * EUR;
}

void wheel::initialize_mega_wheel()
{
    std::vector<int> numbers;
    for(int i = 0; i < 10; ++i)
    {
        numbers.push_back(10);
    }
    for(int i = 0; i < 10; ++i)
    {
        numbers.push_back(20);
    }
    for(int i = 0; i < 3; ++i)
    {
        numbers.push_back(50);
    }
    for(int i = 0; i < 2; ++i)
    {
        numbers.push_back(100);
    }
    for(int i = 0; i < 2; ++i)
    {
        numbers.push_back(250);
    }
    int number = std::uniform_int_distribution<int>(0, numbers.size())(gen_);
    multiplier_ += numbers[number] * EUR;
    number = std::uniform_int_distribution<int>(0, numbers.size())(gen_);
    multiplier_ += numbers[number] * EUR;
    number = std::uniform_int_distribution<int>(0, numbers.size())(gen_);
    multiplier_ += numbers[number] * EUR;
}
