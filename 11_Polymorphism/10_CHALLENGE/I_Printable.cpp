#include "I_Printable.h"

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

/// @brief Overloaded insertion operator for I_Printable objs
/// @param os output
/// @param obj I_Printable obj, usually Accounts
/// @return os output
std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.print(os); // # Uses polymorphism to call each type of obj .print() method
    return os;
}

void print(std::ostream &os) {}
