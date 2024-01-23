/*
! Pre and After increment

? ++counter makes the variable to increase, before that line.
* otherwise counter++ increases the variable after that line.


! static_cast<type> explicit Type Casting - For Mixed Type Expressions
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int num1{100}, num2{8};
    double result = num1 / num2;

    cout << result << endl;

    result = static_cast<double>(num1) / num2;
    cout << result << endl;

    return 0;
}