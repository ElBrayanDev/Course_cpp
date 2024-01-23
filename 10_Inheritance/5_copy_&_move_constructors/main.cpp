/*
# Copy and Move constructor inheritance

• Not inherited from the Base class
    • You may not need to provide your own
        • Compiler-provided versions may be just fine

• We can explicitly invoke the Base class versions from the Derived class

! Often you do not need to provide your own

? If you DO NOT not define them in Derived
    then the compiler will create them and automatically and call the base class's version

? If you DO provide Derived versions
    then YOU must invoke the Base versions explicitly yourself

! Be careful with raw pointers
    • Especially if Base and Derived each have raw pointers
    • Provide them with deep copy semantics

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
    Base()
        : value{0}
    {
        cout << "Base no-args constructor" << endl;
    }
    Base(int x)
        : value{x}
    {
        cout << "int Base constructor" << endl;
    }
    Base(const Base &other)
        : value{other.value}
    {
        cout << "Base copy constructor" << endl;
    }

    Base &operator=(const Base &rhs)
    {
        // # If Derived arrives, it gets sliced to get its Base part only

        cout << "Base operator=" << endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }

    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base
{
private:
    int doubled_value;

public:
    Derived()
        : Base{}
    {
        cout << "Derived no-args constructor " << endl;
    }

    Derived(int x)
        : Base{x}, doubled_value{x * 2}
    {
        cout << "int Derived constructor" << endl;
    }

    Derived(const Derived &other)
        : Base(other), doubled_value{other.doubled_value}
    {
        cout << "Derived copy constructor" << endl;
    }

    Derived &operator=(const Derived &rhs)
    {
        cout << "Derived operator=" << endl;
        if (this == &rhs)
            return *this;
        Base::operator=(rhs);
        doubled_value = rhs.doubled_value;
        return *this;
    }
    ~Derived() { cout << "Derived destructor " << endl; }
};

int main()
{
    // Base b{100}; // Overloaded constructor
    // Base b1{b};  // Copy constructor
    // b = b1;      //   Copy assignment

    Derived d{100}; // Overloaded constructor
    Derived d1{d};  // Copy constructor
    d = d1;         // Copy assignment

    d = d;

    return 0;
}