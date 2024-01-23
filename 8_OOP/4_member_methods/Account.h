#ifndef ACCOUNT_H
#define ACCOUNT_H

#pragma once
#include <string>

class Account
{
private:
    // atributes
    std::string name;
    double balance;

public:
    // methods
    void set_balance(double bal)
    {
        balance = bal;
    }
    double get_balance()
    {
        return balance;
    }
    //! methods implementations outside the class (Account.cpp)
    void set_name(std::string n);
    std::string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif