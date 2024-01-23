/*

(++, --, -, !)

ReturnType Type::operator++(); //! pre-increment

ReturnType Type::operator++(int); //! post-increment

*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include "Mystring.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    cout << std::boolalpha << endl;

    Mystring larry{"Larry"};
    Mystring moe{"Moe"};

    Mystring stooge = larry;
    larry.display(); // Larry
    moe.display();   // Moe

    cout << (larry == moe) << endl;    // false
    cout << (larry == stooge) << endl; // true

    larry.display(); // Larry
    Mystring larry2 = -larry;
    larry2.display(); // larry

    Mystring stooges = larry + "Moe"; // ok with member function
    // Mystring stooges = "Larry" + moe;                                 // Compiler error

    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();
    // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display(); //  Moe Larry Curly

    return 0;
}