#include <iostream>
#include <random>
#include <array>

#include "account.h"
#include "rng.h"
#include "combinations.h"
#include "sminigames.h"
#include "bminigames.h"

void print_stats();

int main()
{
	account acc(100, 1);
	std::random_device rd;
	std::mt19937 gen(rd());
	sminigames sminigame(gen);
	bminigames bminigame(gen);

	return 0;
}

void print_stats()
{

}
