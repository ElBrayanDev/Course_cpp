/*
# Class-level exceptions

Exceptions can also be thrown from within a class:

• Method
    • These work the same way as they do for functions as we've seen

• Constructor
    • Constructors may fail
    • Constructors do not return any value
    • Throw an exception in the constructor if you cannot initialize an object

• Destructor
    • Do NOT throw exceptions from your destructor
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <memory>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"

using namespace std;

int main()
{
    try
    {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0); // # Negative balance
        std::cout << *moes_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << "Couldn't create account - negative balance" << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}