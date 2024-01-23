#include "Checking_Account.h"
#include "Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{name, balance}
{
}

bool Checking_Account::withdraw(double amount)
{
    if ((balance - (amount + withdrawal_fee)) >= 0)
    {
        balance -= (amount + withdrawal_fee);
        return true;
    }
    else
    {
        return false;
    }
}

bool Checking_Account::deposit(double amount)
{
    return Account::deposit(amount);
}

void Checking_Account::print(std::ostream &os) const
{
    os.precision(2);  // # Decimals
    os << std::fixed; // # pretier?
    os << "[Checking Account: " << name << ": " << balance << ", Withdrawal fee: $" << withdrawal_fee << "]";
}