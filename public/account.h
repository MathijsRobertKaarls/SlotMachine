#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "macros.h"

class account
{
public:
    account(x1001 balance, x1001 bet);
    ~account();
    const x1001 get_balance();
    const x1001 get_bet();
private:
    x1001 balance_;
    x1001 bet_;
};

account::account(x1001 balance, x1001 bet) : balance_(balance), bet_(bet)
{
    balance_ * EUR;
    bet_ * EUR;
}

account::~account()
{
    balance_ = x0000;
}

inline const x1001 account::get_balance()
{
    return balance_;
}

inline const x1001 account::get_bet()
{
    return bet_;
}

#endif //ACCOUNT_H