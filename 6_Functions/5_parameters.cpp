/*  PARAMETERS

* Parameters are the data you pass to the function between () in the DEFINITION
* They are ARGUMENTS in the function call
! Must match in number, order and type

You pass a copy of the data to the function
the changes made to that data, does not affect the original one

! Formal vs Actual parameters
    * Formal are the parameters defined in the function header
    * Actual are the parameters used in the fucntion call, the ARGUMENTS
_______________________________________________________________________________________________

 If a function returns a value then it must use a return statement that returns a value
 If a function does not return a value (void) then the return statement is optional
 return statement can occur anywhere in the body of the function

 return statement immediately exits the function

* We can have multiple return statements in a function
    #Avoid many return statements in a function

* The return value is the result of the function call

*/

// # Pass by value (copy)

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void change_num(int num);

void change_num(int num)
{
    num += 999;
    cout << "num in change_num function is: " << num << endl;
}

int main()
{
    int num{5};

    cout << "Num is: " << num << endl;
    change_num(num);

    cout << "Original num stills being: " << num << endl;

    return 0;
}