/*
# POINTERS

• C++ provides absolute flexibility with memory management
    • Allocation
    • Deallocation
    • Lifetime management
• Some potentially serious problems
    • Uninitialized (wild) pointers
    • Memory leaks
    • Dangling pointers
    • Not exception safe
 • Ownership?
    • Who owns the pointer?
    • When should a pointer be deleted?

# SMART POINTERS

•Objects
• Can only point to heap-allocated memory
• Automatically call delete when no longer needed
• Adhere to RAII principles

#include <memory>

• Defined by class templates
    • Wrapper around a raw pointer

• Overloaded operators
    • Dereference (*)
    • Member selection (->)
    ! Pointer arithmetic not supported (++,--, etc.)

• Can have custom deleters

#RAII - Resource Acquisition Is Initialization

• Common idiom or pattern used in software design based on container object lifetime
• RAIl objects are allocated on the stack
• Resource Acquisition
    • Open a file
    • Allocate memory
    • Acquire a lock

• Is Initialization
    • The resource is acquired in a constructor

• Resource relinquishing
    • Happens in the destructor
    • Close the file
    • Deallocate the memory
    • Release the lock
*/

/*
# UNIQUE POINTERS

! std::unique_ptr<Type> name

• Simple smart pointer - very efficient!

• unique_ptr<T>
    • Points to an object of type T on the heap
    • It is unique - there can only be one unique_ptr<T> pointing to the object on the heap
    • Owns what it points to
    • Cannot be assigned or copied
    • CAN be moved
    • When the pointer is destroyed, what it points to is automatically destroyed


! Use make_unique to create objects on the heap
Ex:
auto pointer = std::make_unique<Account>("Brayan", 500);

//# You can use auto since make_unique returns a unique smart pointer
*/

#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Test
{
private:
    int data;

public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

using namespace std;

int main()
{
    // Test *t1 = new Test {1000};
    //  delete t1;
    //   std::unique_ptr<Test> t1 {new Test{100}};
    //   std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
    //
    //   std::unique_ptr<Test> t3;
    //   t3 = std::move(t1);
    //   if (!t1)
    //       std::cout << "t1 is nullptr" << std::endl;

    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    std::cout << *a1 << std::endl;
    a1->deposit(5000);
    std::cout << *a1 << std::endl;

    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Checking_Account>("James", 1000));
    accounts.push_back(make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back(make_unique<Trust_Account>("Bobby", 5000, 4.5));

    for (const auto &acc : accounts)
        std::cout << *acc << std::endl;
    return 0;
}
