/*

# REDIFINING (implementing) father methods

• Derived class can directly invoke Base class methods
• Derived class can override or redefine Base class methods
• Very powerful in the context of polymorphism

# Static binding of method calls

• Binding of which method to use is done at compile time
    • Default binding for C++ is static
    • Derived class objects will use Derived::deposit
    • But, we can explicitly invoke Base::deposit from Derived::deposit
    • OK, but limited - much more powerful approach is dynamic binding which we
    will see in the next section

*/
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include "Savings_Account.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    cout << "\n===== Account class ===================" << endl;
    Account a1{1000.0};
    cout << a1 << endl; // Account balance: 1000

    a1.deposit(500.0);
    cout << a1 << endl; // Account balance: 1500

    a1.withdraw(1000); // Account balance: 500
    cout << a1 << endl;

    a1.withdraw(5000.0); // Insufficient funds
    cout << a1 << endl;  // Account balance: 500

    cout << "\n===== Savings Account class ===========" << endl;
    Savings_Account s1{1000, 5.0};
    cout << s1 << endl; // Savings Account balance: 1000, Interest rate: 5

    s1.deposit(1000);
    cout << s1 << endl; // Savings Account balance: 2050, Interest rate: 5

    s1.withdraw(2000);
    cout << s1 << endl; // Savings Account balance: 50, Interest rate: 5

    s1.withdraw(1000);  // Insufficient funds
    cout << s1 << endl; // Savings Account balance: 50, Interest rate: 5

    return 0;
}