#include <iostream>
#include <random>
#include <array>

#include "rng.h"

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	int sample_money = 1000;

	return 0;
}