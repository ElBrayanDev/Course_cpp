/*
# CUSTOM DELETERS

! if used, you cannot use make_shared or make_unique, specialized way to create and delete

• Sometimes when we destroy a smart pointer we need more than to just
destroy the object on the heap

• These are special use-cases

• C++ smart pointers allow you to provide custom deleters

• Lots of way to achieve this
    • Functions
    • Lambdas
    • Others...

# pass the deleter to the pointer initialization

Ex:

void my_deleter (Test *ptr) {
    cout << "In my custom deleter" << end;
    delete ptr;
}

shared_ptr<Test> ptr { new Test{}, my_deleter };

# Lambda

shared_ptr<Test> ptr (new Test{100}, [] (Test *ptr) {
      cout << "\tUsing my custom deleter" << endl;
      delete ptr;
});

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

class Test
{
private:
    int data;

public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data{data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// # Custom deleter
void my_deleter(Test *ptr)
{
    std::cout << "\tUsing my custom function deleter" << std::endl;
    delete ptr;
}

int main()
{
    {
        // # Using a function
        std::shared_ptr<Test> ptr1{new Test{100}, my_deleter}; //! Creates the object on the heap, and passes the deleter
    }

    std::cout << "====================" << std::endl;
    {
        // # Using a Lambda expression
        std::shared_ptr<Test> ptr2(new Test{1000},
                                   [](Test *ptr)
                                   {
            std::cout << "\tUsing my custom lamdba deleter" << std::endl;
            delete ptr; });
    }

    return 0;
}