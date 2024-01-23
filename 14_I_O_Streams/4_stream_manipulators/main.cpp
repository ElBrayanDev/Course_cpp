/*
# Field width, align and fill

• Default when displaying floating point values is:
    • setw - not set by default
    • left - when no field width, right - when using field width
    • fill - not set by default - blank space is used

• Some of these manipulators affect only the next data element put on the stream

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

void ruler()
{
    std::cout << "\n12345678901234567890123456789012345678901234567890" << std::endl;
}

int main()
{
    int num1{1234};
    double num2{1234.5678};
    string hello{"Hello"};

    // Defaults
    cout << "\n--Defaults -------------------------------------------------------------------" << std::endl;
    ruler();
    cout << num1
         << num2
         << hello
         << std::endl;

    // Defaults - one per line
    cout << "\n--Defaults - one per line-----------------------------------------------------" << std::endl;
    ruler();
    cout << num1 << endl;
    cout << num2 << endl;
    cout << hello << endl;

    // # Set field width to 10
    //! Note the default justification is right for num1 only!
    cout << "\n--width 10 for num1-----------------------------------------------------------" << endl;
    ruler();
    cout << std::setw(10) << num1
         << num2
         << hello
         << endl;

    // Set field width to 10 for the first 2 outputs
    // Note the default justification is right for both
    cout << "\n--width 10 for num1 and num2------------------------------------------------" << endl;
    ruler();
    cout << std::setw(10) << num1
         << std::setw(10) << num2
         << hello
         << endl;

    // # Set field width to 10 for all 3 outputs
    //! Note the default justification is right for all
    cout << "\n--width 10 for num1 and num2 and hello--------------------------------------" << endl;
    ruler();
    cout << std::setw(10) << num1
         << std::setw(10) << num2
         << std::setw(10) << hello
         << endl;

    // Set field width to 10 for all 3 outputs and justify all left
    cout << "\n--width 10 for num1 and num2 and hello left for all---------------------------" << endl;
    ruler();
    cout << std::setw(10) << std::left << num1
         << std::setw(10) << std::left << num2
         << std::setw(10) << std::left << hello
         << endl;

    // # setfill to a dash, this is persistent
    //  Then repeat the previous display
    cout << std::setfill('-');
    cout << "\n--width 10 for num1 and num2 and hello left for all setfill to dash------------" << endl;
    ruler();
    cout << std::setw(10) << std::left << num1
         << std::setw(10) << std::left << num2
         << std::setw(10) << std::left << hello
         << endl;

    // # Set width to 10 for all, left justify all and cary the setfill character
    cout << "\n--width 10 for num1 and num2 and hello - setfill varies------------------------" << endl;
    ruler();
    cout << std::setw(10) << std::left << std::setfill('*') << num1
         << std::setw(10) << std::left << std::setfill('#') << num2
         << std::setw(10) << std::left << std::setfill('-') << hello
         << endl;

    cout << endl
         << endl;
    return 0;
}