#ifndef ACCOUNT_UTIL_H
#define ACCOUNT_UTIL_H

#pragma once

#include <vector>
#include "Account.h"

// Utility helper functions for Account * classes

void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);

#endif