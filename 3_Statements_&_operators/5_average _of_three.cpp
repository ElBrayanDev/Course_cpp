/*
    Ask the user to enter 3 integers
    Calculate the sum of the integers then
    Calculate the average of the 3 integers.

    Display the 3 integers entered
    The sum of the integers and
    The average of the 3 integers.
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
    cout << "Enter three integers separated by spaces: " << endl;
    int num1{0}, num2{0}, num3{0};
    cin >> num1 >> num2 >> num3;

    int sum = num1 + num2 + num3;
    double average = static_cast<double>(sum) / 3; //!

    cout << "Num 1: " << num1 << "\nNum 2: " << num2 << "\nNum 3: " << num3 << endl;
    cout << "Sum equals: " << sum << endl;
    cout << "Average is: " << average << endl;
    return 0;
}