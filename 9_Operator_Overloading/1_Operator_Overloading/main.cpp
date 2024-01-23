/*  OPERATOR OVERLOADING

! Can't overload
::
:?
.*
.
sizeof

* Precedence and Associativity cannot be changed
* 'ariaty' cannot be changed (you can't make a division with one operator)
* Can't overload operators for primitive types (int, double)
* Can't create new operators
# [], (), ->, =, must be declared as member methods
* Other operators can be declared as member methods or global functions
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Mystring.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    Mystring empty;
    Mystring brayan("Brayan");
    Mystring brayan_copy{brayan}; //copy CTOR

    empty.display();
    brayan.display();
    brayan_copy.display();
    
    return 0;
}