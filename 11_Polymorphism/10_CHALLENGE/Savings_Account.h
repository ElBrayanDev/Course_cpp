#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#pragma once

#include "Account.h"

// Savings Account is a type of Account
//   adds an interest rate
// Withdraw - same as a regular account
// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100)
//      and then the updated amount will be deposited
//
class Savings_Account : public Account
{
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

    // # Unique for Savings Account
protected:
    double int_rate;

public:
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double) override;
    virtual bool withdraw(double) override;

    virtual void print(std::ostream &os) const override;

    virtual ~Savings_Account() = default;
};

#endif