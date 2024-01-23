/* SCOPE RULES

- C++ uses scope rules to determine where an identifier can be used
- C++ uses static or lexical scoping

# Local or Block scope:

    ~ Identifiers declared in a block {}

    ~ Function parameters have block scope

    ~ Only visible within the block { } where declared

    ~ Function local variables are only active while the function is executing

    ~ Local variables are NOT preserved between function calls

    ~ With nested blocks inner blocks can ‘see’ but outer blocks cannot ‘see’ in

    ! Preserve info by using static local variables (CONSTANTS)

- Global scope

    ~ Identifier declared outside any function or class

    ~ Visible to all parts of the program after the global identifier has been declared

    ~ Global constants are OK

    ~ Best practice - don't use global variables

*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void local_example();
void global_example();
void static_local_example();

int num{300}; // Global variable - declared outside any class or function

void global_example() //! Is modified every call
{
    cout << "\nGlobal num is: " << num << " in global_example - start" << endl;
    num *= 2; //! modifies every call
    cout << "Global num is: " << num << " in global_example - end" << endl;
}

void local_example(int x)
{
    int num{1000}; // local to local_example
    cout << "\nLocal num is: " << num << " in local_example - start" << endl;
    num = x;
    cout << "Local num is: " << num << " in local_example - end" << endl;
    // num1 in main is not within scope - so it can't be used here.
}

void static_local_example() //! This behaves like a global variable, but its scope is local, the entire program CANNOT see it or modify it
{
    static int num{5000}; //! local to static_local_example static - retains it value between calls
    cout << "\nLocal static  num is: " << num << " in static_local_example - start" << endl;
    num += 1000;
    cout << "Local static  num is: " << num << " in static_local_example - end" << endl;
}

int main()
{

    int num{100};  // Local to main
    int num1{500}; // Local to main

    cout << "Local num is : " << num << " in main" << endl;

    {                 // creates a new level of scope
        int num{200}; // local to this inner block
        cout << "Local num is: " << num << " in inner block in main" << endl;
        cout << "Inner block in main can see out - num1 is: " << num1 << endl;
    }

    cout << "Local num is : " << num << " in main" << endl;

    local_example(10);
    local_example(20);

    global_example();
    global_example();

    static_local_example();
    static_local_example();
    static_local_example();

    cout << endl;
    return 0;
}
