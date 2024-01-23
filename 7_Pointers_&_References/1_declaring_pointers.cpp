/*
# WHAT IS A POINTER?

- A variable
    + whose value is an address

- What can be at that address
    + Another variable
    + Afunction

- Pointers point to variables orfunctions?

- If x is an integer variable and its value is 10 then I can declare a pointer that points to it

- To use the data that the pointer is pointing to you must know its type

# WHY USE POINTERS?

"Can't I just use the variable or function itself?"
 - Yes, but not always

! Inside functions, pointers can be used to access data that are defined outside the function.
    ! Those variables may not be in scope so you can't access them by their name

- Pointers can be used to operate on arrays very efficiently

? We can allocate memory dynamically on the heap or free store.
    + This memory doesn't even have a variable name.
    * The only way to get to it is via a pointer

+ With OOP. pointers are how polymorphism works!

* Can access specific addresses in memory
    + useful in embedded (attached) and systems applications

# DECLARING POINTERS

Initializing pointer variables to ‘point nowhere’
! Always initialize pointers
* Uninitialized pointers contain garbage data and can ‘point anywhere’
+ Initializing to zero or nullptr (C++ 11) represents address zero
    - implies that the pointer is ‘pointing nowhere’

? If you don't initialize a pointer to point to a variable or function then
? you should initialize it to nullptr to ‘make it null’

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

int main()
{
    int *int_ptr{};

    double *double_ptr{nullptr};
    char *char_ptr{nullptr};
    string *string_ptr{nullptr};

    cout << int_ptr << endl;
    cout << double_ptr << endl;
    cout << char_ptr << endl;
    cout << string_ptr << endl;
    return 0;
}
