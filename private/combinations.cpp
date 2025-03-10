#include "combinations.h"

x0100<combs, 5> seek_combinations(x0100<x1001, x0005> x0200)
{
   std::array<int, 10> bitmask {0};

   for(int i = 0; i < 5; ++i)
   {
       bitmask[x0200[i]] += 1; 
   }

   std::array<combs, 5> res {x5000};


   if(five_of_a_kind(bitmask)) res[0] = x4002;  
   if(three_of_a_kind(bitmask)) res[1] = x4001;
   if(two_of_a_kind(bitmask)) res[2] = x4000; 
   if(straight_of_five(bitmask)) res[3] = x4004;
   if(straight_of_three(bitmask)) res[4] = x4003;

   return res;
}

bool two_of_a_kind(std::array<int, 10>& array)
{
    for(int i = 0; i < 10; ++i)
    {
        if(array[i] == 2)
        {
            return true;
        }
    }
    return false;
}

bool three_of_a_kind(std::array<int, 10>& array)
{
    for(int i = 0; i < 10; ++i)
    {
        if(array[i] == 3)
        {
            return true;
        }
    }
    return false;
}

bool five_of_a_kind(std::array<int, 10>& array)
{
    for(int i = 0; i < 10; ++i)
    {
        if(array[i] == 5)
        {
            return true;
        }
    }
    return false;
}

bool straight_of_three(std::array<int, 10>& array)
{
    for(int i = 0; i < 8; ++i)
    {
        if(array[i] == 1 && array[i + 1] == 1 && array[i + 2] == 1)
        {
            return true;
        }
    }
    return false;
}

bool straight_of_five(std::array<int, 10>& array)
{
    for(int i = 0; i < 6; ++i)
    {
        if(array[i] == 1 && array[i + 1] == 1 && array[i + 2] == 1 && array[i + 3] == 1 && array[i + 4] == 1)
        {
            return true;
        }
    }
    return false;
}


