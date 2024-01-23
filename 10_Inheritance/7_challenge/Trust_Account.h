#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#pragma once

#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

protected:
    int num_withdrawals;
    double max_withdrawal_amount;

private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

    static constexpr double min_deposit_for_bonus = 5000.00;
    static constexpr double bonus_per_deposit = 50.00;
    static constexpr double max_per_year_withdrawals = 3;
    static constexpr double max_withdraw_percent = .2;

public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif