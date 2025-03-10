#include <iostream>
#include <random>
#include <array>

#include "rng.h"

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());


	int boom = 0;

	for(int i = 0; i < 100; ++i)
	{
		if(generate_random_numbers_one(gen))
		{
			boom++;
			std::cout << "BOOM" << "\n";
		}
		else
		{
			std::array<int, 5> f = generate_random_numbers(gen);
			for(int i = 0; i < 5; ++i)
			{
				std::cout << f[i] << "\n";
			}
			std::cout << "\n";
		}
	}

	std::cout << "BOOM: " << boom << "\n";
	
	return 0;
}