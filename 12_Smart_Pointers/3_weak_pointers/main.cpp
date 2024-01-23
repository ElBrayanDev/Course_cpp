/*
# WEAK POINTERS

weak_ptr
• Provides a non-owning "weak" reference

! std::weak_ptr<T>
    • Points to an object of type T on the heap
    • Does not participate in owning relationship
    • Always created from a shared_ptr
    • Does NOT increment or decrement reference use count
    • Used to prevent strong reference cycles which could prevent objects from being deleted

# Class A points (owns) class B, so if Class B has a pointer to A, it must be a weak_ptr
! preventing memory leaks

*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class B; // forward declaration

class A
{
    std::shared_ptr<B> b_ptr;

public:
    void set_B(std::shared_ptr<B> &b)
    {
        b_ptr = b;
    }
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B
{
    std::weak_ptr<A> a_ptr; // # make weak to break the strong circular reference, if shared then no constructors called (memory leak)
public:
    void set_A(std::shared_ptr<A> &a)
    {
        a_ptr = a;
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};

int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->set_B(b);
    b->set_A(a);

    return 0;
}