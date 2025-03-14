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
    const void set_balance(int balance);
    const void set_bet(int bet);
private:
    x1001 balance_;
    x1001 bet_;
};

account::account(x1001 balance, x1001 bet) : balance_(balance), bet_(bet)
{
    balance_ = balance_ * EUR;
    bet_ = bet_ * EUR;
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

const inline void account::set_balance(int balance)
{
    balance_ = balance;
}

const inline void account::set_bet(int bet)
{
    bet_ = bet;
}

#endif //ACCOUNT_H