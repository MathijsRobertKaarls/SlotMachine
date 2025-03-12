#include "combinations.h"

#include <iostream>

x0100<combs, 5> seek_combinations(x0100<x1001, x0005> x0200)
{
    data_table dt;
    dt.original = x0200;

    for(int i = 0; i < 5; ++i)
    {
        dt.bitmask[x0200[i]] += 1;
    }

    dt.vector.push_back(five_of_a_kind(dt));
    dt.vector.push_back(three_of_a_kind(dt)); 
    dt.vector.push_back(two_of_a_kind(dt));  
    dt.vector.push_back(straight_of_five(dt)); 
    dt.vector.push_back(straight_of_three(dt)); 

    std::array<combs, 5> ca;
    for(int i = 0 ; i < dt.vector.size(); ++i)
    {
        ca[i] = dt.vector[i].c;
    }

    return ca;
}

combs_order two_of_a_kind(data_table &dt)
{
    for(int i : dt.original)
    {
        if(i == 0)
        {
            return combs_order{};
        }
    }

    for(int i = 0; i < 10; ++i)
    {
        if(dt.bitmask[i] == 2)
        {
            std::array<int, 5> arr {i};
            return combs_order{x4000, arr};
        }
    }
    return combs_order{};
}

combs_order three_of_a_kind(data_table &dt)
{
    for(int i : dt.original)
    {
        if(i == 0)
        {
            return combs_order{};
        }
    }

    for(int i = 0; i < 10; ++i)
    {
        if(dt.bitmask[i] == 3)
        {
            std::array<int, 5> arr {i};
            return combs_order{x4001, arr};
        }
    }
    return combs_order{};
}

combs_order five_of_a_kind(data_table &dt)
{
    for(int i : dt.original)
    {
        if(i == 0)
        {
            return combs_order{};
        }
    }

    for(int i = 0; i < 10; ++i)
    {
        if(dt.bitmask[i] == 5)
        {
            std::array<int, 5> arr {i};
            return combs_order{x4002, arr};
        }
    }
    return combs_order{};
}

combs_order straight_of_three(data_table &dt)
{
    for(int i : dt.original)
    {
        if(i == 0)
        {
            return combs_order{};
        }
    }
    
    bool b_straight_of_three = false;
    for(int i = 0; i < 8; ++i)
    {
        if(dt.bitmask[i] == 1 && dt.bitmask[i + 1] == 1 && dt.bitmask[i + 2] == 1)
        {
            b_straight_of_three = true;
        }
    }

    if(b_straight_of_three)
    {
        for(int i = 0; i < 3; ++i)
        {
            if(dt.original[i + 1] == dt.original[i] + 1 && dt.original[i + 2] == dt.original[i] + 2)
            {    
                return combs_order{x4003, dt.original};
            }
        }
    }
    return combs_order{};
}

combs_order straight_of_five(data_table &dt)
{
    for(int i : dt.original)
    {
        if(i == 0)
        {
            return combs_order{};
        }
    }

    bool b_straight_of_five = false;
    for(int i = 0; i < 6; ++i)
    {
        if(dt.bitmask[i] == 1 && dt.bitmask[i + 1] == 1 && dt.bitmask[i + 2] == 1 && dt.bitmask[i + 3] == 1 && dt.bitmask[i + 4] == 1)
        {
            b_straight_of_five = true;
        }
    }

    if(straight_of_five)
    {
        if(dt.original[0 + 1] == dt.original[0] + 1 && dt.original[0 + 2] == dt.original[0] + 2 && dt.original[0 + 3] == dt.original[0] + 3 && dt.original[0 + 4] == dt.original[0] + 4) 
        {    
            return combs_order{x4004, dt.original};
        }
    }
    return combs_order{};
}
