#include "Checking_Account.h"
#include "Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{name, balance}
{
}

Checking_Account::~Checking_Account()
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

std::ostream &operator<<(std::ostream &os, const Checking_Account &account)
{
    os << "[Checking Account: " << account.name << ": " << account.balance << ", Withdrawal fee: $" << account.withdrawal_fee << "]";
    return os;
}