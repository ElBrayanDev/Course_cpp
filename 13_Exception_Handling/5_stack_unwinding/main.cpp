/*
# STACK UNWINDING

If an exception is thrown but not caught in the current scope
C++ tries to find a handler for the exception by unwinding the stack

• Function in which the exception was not caught terminates
and is removed from the call stack

• If a try block was used to then catch blocks are checked for a match

• If no try block was used or the catch handler doesn't match
   stack unwinding occurs again

• If the stack is unwound back to main and no catch handler handles the exception
   the program terminates

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

void func_a();
void func_b();
void func_c();

void func_a()
{
    std::cout << "Starting func_a" << std::endl;
    func_b();
    std::cout << "Ending func_a" << std::endl;
}

void func_b()
{
    std::cout << "Starting func_b" << std::endl;
    try
    {
        func_c();
    }
    catch (int &ex)
    {
        std::cout << "Caught error in func_b" << std::endl;
    }
    std::cout << "Ending func_b" << std::endl;
}

void func_c()
{
    std::cout << "Starting func_c" << std::endl;
    throw 100;
    std::cout << "Ending func_c" << std::endl;
}

int main()
{

    std::cout << "Starting main" << std::endl;
    try
    {
        func_a();
    }
    catch (int &ex)
    {
        std::cout << "Caught error in main" << std::endl;
    }
    std::cout << "Finishing main" << std::endl;
    return 0;
}