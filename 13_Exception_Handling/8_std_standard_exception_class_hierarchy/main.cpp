/*
C++ provides a class hierarchy of exception classes
    ! std::exception is the base class
    • all subclasses implement the what () virtual function
    • we can create our own user-defined exception subclasses

virtual const char *what () const noexcept;


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

class ThrowException : public std::exception
{
public:
    ThrowException() noexcept = default;
    ~ThrowException() = default;
    virtual const char *what() const noexcept
    {
        return "Illegal balance exception";
    }
};

/*
Account::Account (std::string name, double balance)
    : name {name}, balance {balance} {
    if (balance < 0.0)
        throw IllegalBalanceException{};
}

*/

/*
int main()
{
try {
    std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account> ("Moe", -100.0);

    std::cout << "Use moes account" << std::endl;
}
catch (const IllegalBalanceException &ex)
{
    cerr << ex.what () << endl; //# displays "Illegal balance exception"
}
}

*/