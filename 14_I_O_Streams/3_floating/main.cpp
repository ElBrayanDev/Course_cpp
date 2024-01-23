/*
# Formatting floating point types
• Default when displaying floating point values is:
    • setprecision number of digits displayed (6)
    • fixed - not fixed to a specific number of digits after the decimal point
    • noshowpoint - trailing zeroes are not displayed
    • nouppercase - when displaying in scientific notation
    • noshowpos - no '+' is displayed for positive numbers

• These manipulators affect all further output to the stream

*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <memory>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    double num1{123456789.987654321};
    double num2{1234.5678};
    double num3{1234.0};

    //! using default settings
    cout << "--Defaults ----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    // # Note how since we can't display in precision 2 scientific notation is used
    cout << std::setprecision(2);
    cout << "--Precision 2----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    // Using precision 5
    cout << std::setprecision(5);
    cout << "--Precision 5----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    // Using precision 9
    cout << std::setprecision(9);
    cout << "--Precision 9----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    // # Using precision 3 and fixed
    cout << std::setprecision(3) << std::fixed;
    cout << "--Precision 3 - fixed ----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    // # Using precision  3, fixed and scientific notation
    //! Note precision is after the decimal
    cout << std::setprecision(3) << std::scientific;
    cout << "--Precision 3 - scientific  ----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    // # Same but display capital 'E' in scientific
    cout << std::setprecision(3) << std::scientific << std::uppercase;
    cout << "--Precision 3 - scientific - uppercase  ----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    // # Show '+' symbol for positive numbers
    cout << std::setprecision(3) << std::fixed << std::showpos;
    cout << "--Precision 3 - fixed - showpos ----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    //! Back to defaults
    cout.unsetf(std::ios::scientific | std::ios::fixed);
    cout << std::resetiosflags(std::ios::showpos);

    // # Show trailing zeroes up to precision 10

    cout << std::setprecision(10) << std::showpoint;
    cout << "-- precision 10 - showpoint ----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    //! Back to defaults
    cout.unsetf(std::ios::scientific | std::ios::fixed);
    cout << std::setprecision(6);
    cout << std::resetiosflags(std::ios::showpos);
    cout << std::resetiosflags(std::ios::showpoint);

    cout << "--Back to defaults----------------------------" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    return 0;
}