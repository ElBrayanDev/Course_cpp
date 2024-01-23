/*
! ASSIGNMENT
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int num1{10}, num2{20}; //! Declaration

    num1 = num2; //? Assignment

    cout << "num1 is: " << num1 << endl;
    cout << "num2 is: " << num2 << endl;

    //! double assignment, num2 is a 1000, then num1 = 1000. From right to left
    cout << "\nTwo assignments at same time: " << endl;
    num1 = num2 = 1000; //? Assignment

    cout << "\nnum1 is: " << num1 << endl;
    cout << "num2 is: " << num2 << endl;

    //! Printing operation itself
    cout << " \nPrinting operation itself: " << endl;

    num1 = 200;
    num2 = 100;

    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;

    //! Save operation on another variable
    cout << " \nSaving operation on another variable: " << endl;
    int result = num1 + num2;

    cout << num1 << " + " << num2 << " = " << result << endl;

    cout << num2 << " / " << num1 << " = " << num1 / num2 << endl;

    //! use DOUBLES with division operation

    cout << num1 << " / " << num2 << " = " << num2 / num1 << endl;

    cout << "Double variables for division and modulo " << endl;

    double y{100}, x{200};
    double division_result = y / x;

    cout << num1 << " / " << num2 << " = " << division_result << endl;

    return 0;
}