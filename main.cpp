#include <iostream>
#include <random>
#include <array>

#include "account.h"
#include "rng.h"
#include "combinations.h"
#include "sminigames.h"
#include "bminigames.h"

int main()
{
	account acc(500, 5);
	std::random_device rd;
	std::mt19937 gen(rd());
	sminigames sminigame(gen);
	bminigames bminigame(gen);

	int smg = 0;
	int bmg = 0;
	int emp = 0;
	int spins = 0;

	while (acc.get_balance() > 5 * EUR)
	{
		spins++;

		int bal = acc.get_balance();
		int bet = acc.get_bet();

		bal -= bet;

		if(generate_random_numbers_one(gen))
		{
			acc.set_balance(bal);
			std::cout << "BALANCE: " << acc.get_balance() << "\n";
			emp++;
			continue;
		}
		
		int big_multiplier = bminigame.play_b_minigame();
		if(big_multiplier > 0)
		{
			bal += ((bet * big_multiplier) / EUR);
			acc.set_balance(bal);
			std::cout << "BALANCE: " << acc.get_balance() << "\n";
			bmg++;
			continue;
		}
		
		int small_multiplier = sminigame.play_s_minigame();
		if(small_multiplier > 0)
		{
			bal += ((bet * small_multiplier) / EUR);
			acc.set_balance(bal);
			std::cout << "BALANCE: " << acc.get_balance() << "\n";
			smg++;
			continue;
		}
		
		std::array<int, 5> values = generate_random_numbers(gen);
		std::array<payout_pattern, 5> order = seek_combinations(values);
		
		int multiplier = 0;
		for (int i = 0; i < 5; ++i)
		{
			std::cout << values[i] << " " << order[i] << "\n";

			if(order[i] > multiplier)
			{
				multiplier = order[i];
			}
		}

		bal += ((bet * multiplier) / EUR);
	
		acc.set_balance(bal);
		std::cout << "BALANCE: " << acc.get_balance() << "\n";
	}

	std::cout << "SPINS: " << spins << " " << "S: " << smg << "B: " << bmg << "E: " << emp;
}

