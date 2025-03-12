#include <iostream>
#include <random>
#include <array>

#include "rng.h"
#include "combinations.h"

int money = EUR * 10;
int bet = EUR;
int spins = 1;

int s5 = 0;
int s3 = 0;
int k5 = 0;
int k3 = 0;
int k2 = 0;
int empty = 0;

void print_stats();

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());



	for(int i = 0; i < 1000; ++i)
	{
		if(money < bet)
		{
			break;
		}
		money -= bet;
		spins = i;

		std::array<int, 5> res = generate_random_numbers(gen);

		std::array<combs, 5> comb = seek_combinations(res);

		if(generate_random_numbers_one(gen))
		{
			std::cout << "0 0 0 0 0" << "\n";
			continue;
		}

		int stored = 0;
		for(int j = 0; j < 5; ++j)
		{
			std::cout << "NUMBER: " << res[j] << " " << "WON: " << comb[j] << "\n";
			if(comb[j] > stored)
			{
				stored = comb[j];
			}
		}

		if(stored == 0) empty++;
		if(stored == 20) k2++;
		if(stored == 50) k3++;
		if(stored == 1000) s3++;
		if(stored == 5000) s5++;

		money += ((bet / EUR) * stored);

		std::cout << money << "\n";
	}	

	print_stats();

	return 0;
}

void print_stats()
{
	std::cout << "\n";
	std::cout << "SPINS: " << spins << "\n";
	std::cout << "EMPTY: " << empty << "\n";
	std::cout << "S5: " << s5 << "\n";
	std::cout << "S3: " << s3 << "\n";
	std::cout << "K3: " << k3 << "\n";
	std::cout << "K2: " << k2 << "\n";
}
