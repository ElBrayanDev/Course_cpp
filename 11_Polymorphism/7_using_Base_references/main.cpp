/*
# USING BASE CLASS REFERENCES

• We can also use Base class references with dynamic polymorphism
• Useful when we pass objects to functions that expect a Base class reference

*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {}
};

class Checking : public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {}
};

class Savings : public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {}
};

class Trust : public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {}
};

// # dynamic withdraw(Account &, double);
void do_withdraw(Account &account, double amount)
{
    account.withdraw(amount); // withdraw(double) is virtual, and dynamic
}

int main()
{

    Account a;
    Account ref = a;
    ref.withdraw(1000); // In Account::withdraw

    Trust t;
    Account &ref1 = t;   // # Refers to trust account
    ref1.withdraw(1000); // In Trust::withdraw

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    do_withdraw(a1, 1000); // In Account::withdraw
    do_withdraw(a2, 2000); // In Savings::withdraw
    do_withdraw(a3, 3000); // In Checking::withdraw
    do_withdraw(a4, 4000); // In Trust::withdraw

    return 0;
}