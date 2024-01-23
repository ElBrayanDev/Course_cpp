#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#pragma once
#include "Account.h"
#include <string>
#include <iostream>

class Checking_Account : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);

private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double withdrawal_fee = 1.50;

public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
    ~Checking_Account();
};

#endif