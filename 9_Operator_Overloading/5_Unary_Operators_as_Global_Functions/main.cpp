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

    Mystring larry{"Larry"};
    larry.display(); // Larry

    larry = -larry;
    larry.display(); // larry

    cout << std::boolalpha << endl;
    Mystring moe{"Moe"};
    Mystring stooge = larry;

    cout << (larry == moe) << endl;    // false
    cout << (larry == stooge) << endl; // true

    //  Mystring stooges = larry + "Moe";
    Mystring stooges = "Larry" + moe; // Now OK with non-member function
    stooges.display();                // LarryMoe

    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display(); // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display(); // Moe larry Curly

    return 0;
}