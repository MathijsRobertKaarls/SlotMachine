#include <iostream>
#include <random>
#include <array>

#include "rng.h"
#include "combinations.h"

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	if(generate_random_numbers_one(gen))
	{
		std::cout << "GAME OVER" << "\n";
		return 0;
	}

	std::array<int, 5> res = generate_random_numbers(gen);

	std::array<combs, 5> comb = seek_combinations(res);

	for(int i = 0; i < 5; ++i)
	{
		std::cout <<  "NUMBER: " << res[i] << "WON: " << comb[i] << "x" << "\n";
	}
	
	return 0;
}