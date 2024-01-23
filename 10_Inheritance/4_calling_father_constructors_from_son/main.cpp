/*
# CALLING FATHER CONSTRUCTORS FROM SON CLASSES

! If we don't invoke Father Constructor, the no-args Constructor would be called.

? The Base part of a Derived class must be initialized first

- How can we control exactly which Base class constructor is used during
initialization?

- We can invoke the whichever Base class constructor we wish in the initialization
list of the Derived class

# We do this by using the " : " after Son constructor
Ex.

Son::Son(int x)
    : Father{x}, Param1{y}, etc.

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

class Base
{
private:
    int value;

public:
    Base() : value{0}
    {
        cout << "Base no-args constructor" << endl;
    }
    Base(int x) : value{x}
    {
        cout << "Base (int) overloaded constructor" << endl;
    }
    ~Base()
    {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base
{
private:
    int doubled_value;

public:
    Derived()
        : Base{}, doubled_value{0} //! Calls Base{} to set by default
    {
        cout << "Derived no-args constructor " << endl;
    }
    Derived(int x)
        : Base{x}, doubled_value{x * 2} //! Calls Base{x} to set 'value' parameter
    {
        cout << "Derived (int) constructor" << endl;
    }
    ~Derived()
    {
        cout << "Derived destructor " << endl;
    }
};

int main()
{
    //  Derived d;
    Derived d{1000};
    return 0;
}