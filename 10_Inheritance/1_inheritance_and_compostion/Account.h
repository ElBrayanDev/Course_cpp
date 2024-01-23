#ifndef ACCOUNT_H
#define ACCOUNT_H

#pragma once

#include <string>

class Account
{
public:
    double balance;
    std::string name;
    void deposit(double amount);
    void withdraw(double amount);
    Account();
    ~Account();
};

#endif