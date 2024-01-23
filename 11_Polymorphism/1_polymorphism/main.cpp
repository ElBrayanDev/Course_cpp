/*
# STATIC BINDING

• Fundamental to Object-Oriented Programming

• Polymorphism
    • Compile-time/early binding/static binding
    ! Run-time / late binding / dynamic binding

• Runtime polymorphism
    • Being able to assign different meanings to the same function at run-time

• Allows us to program more abstractly
    • Think general vs. specific
    ! Let C++ figure out which function to call at run-time

• Not the default in C++, run-time polymorphism is achieved via
    • Inheritance
    • Base class pointers or references
    • virtual functions

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

#include <iostream>
#include <memory>

class Base
{
public:
    void say_hello() const
    {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived : public Base
{
public:
    void say_hello() const
    {
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

void greetings(const Base &obj)
{
    std::cout << "Greetings: ";
    obj.say_hello(); //! static binding
}

int main()
{
    Base b;
    b.say_hello();

    Derived d;
    d.say_hello(); // Works as supposed

    greetings(b);
    greetings(d); //! This doesn't call Derived say_hello() because it was static binded

    Base *ptr = new Derived();
    ptr->say_hello(); //@ ptr is pointing to a Base, so Base say_hello() is called

    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>(); //? Smart pointer
    ptr1->say_hello();

    delete ptr;

    return 0;
}