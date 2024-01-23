/*

! CONSTRUCTOR (Father to Son)
• A Derived class inherits from its Base class
• The Base part of the Derived class MUST be initialized BEFORE theDerived class is initialized
• When a Derived object is created
   • Base class constructor executes then
   • Derived class constructor executes

! DESTRUCTOR (Son to Father)
• Class destructors are invoked in the reverse order as constructors
• The Derived part of the Derived class MUST be destroyed BEFORE the Base class destructor is invoked
• When a Derived object is destroyed
   • Derived class destructor executes then
   • Base class destructor executes
   • Each destructor should free resources allocated in it's own constructors

• A Derived class does NOT inherit
    • Base class constructors
    • Base class destructor
    • Base class overloaded assignment operators
    • Base class friend functions
• However, the derived class constructors, destructors, and overloaded
assignment operators can invoke the base-class versions

? C++11 allows explicit inheritance of base 'non-special' constructors with
? using Base::Base; anywhere in the derived class declaration
    ! Lots of rules involved, often better to define constructors yourself

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
    Base() : value{0} { cout << "Base no-args constructor" << endl; }
    Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base
{
    using Base::Base; // # Inheritates the non-specialized Class method (Overload constructor)

private:
    int doubled_value;

public:
    Derived() : doubled_value{0} { cout << "Derived no-args constructor " << endl; }
    Derived(int x) : doubled_value{x * 2} { cout << "Derived (int) overloaded constructor" << endl; }
    ~Derived() { cout << "Derived destructor " << endl; }
};

int main()
{
    // Base b;
    // Base b{100};
    // Derived d;
    Derived d(1000);

    return 0;
}