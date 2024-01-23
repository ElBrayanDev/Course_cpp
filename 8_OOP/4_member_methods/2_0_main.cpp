#include "Account.h" //!
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    Account brayan_account;
    brayan_account.set_name("Brayan's account");
    brayan_account.set_balance(1000.0);

    if (brayan_account.deposit(200))
        cout << "Deposit OK" << endl;
    else
        cout << "Deposit Not allowed" << endl;

    if (brayan_account.withdraw(500.0))
        cout << "Withdrawal OK" << endl;
    else
        cout << "Not sufficient funds" << endl;

    if (brayan_account.withdraw(1500.0))
        cout << "Withdrawal OK" << endl;
    else
        cout << "Not sufficient funds" << endl;

    return 0;
}
