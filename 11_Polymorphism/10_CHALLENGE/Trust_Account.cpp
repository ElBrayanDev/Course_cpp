#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, num_withdrawals{0}
{
}

bool Trust_Account::deposit(double amount)
{
    bool greater_than_min_deposit_for_bonus = false;
    if (amount >= min_deposit_for_bonus)
    {
        greater_than_min_deposit_for_bonus = true;
    }
    amount += (amount * (int_rate / 100));

    if (greater_than_min_deposit_for_bonus == true)
        amount += bonus_per_deposit;

    return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    if (num_withdrawals >= max_per_year_withdrawals || (amount > (balance * max_withdraw_percent)) || amount > balance)
    {
        return false;
    }

    ++num_withdrawals;
    return Savings_Account::withdraw(amount);
}

void Trust_Account::print(std::ostream &os) const
{
    os.precision(2);  // # Decimals
    os << std::fixed; // # pretier?
    os << "[Trust_Account: " << name << ": " << balance << ", " << int_rate << "%"
       << ", withdrawals made this year: " << num_withdrawals << "]";
}