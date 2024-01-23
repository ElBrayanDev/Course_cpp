/*
# Formatting integer types
• Default when displaying integer values is:
    • dec (base 10)
    • noshowbase - prefix used to show hexadecimal or octal
    • nouppercase - when displaying a prefix and hex values it will be lower case
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
    int num{255};

    // # Displaying using different bases
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // # Displaying showing the base prefix for hex and oct
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // # Display the hex value in uppercase
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;

    // # Display the + sign in front of positive base 10 numbers
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl; // works on decimals
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // # setting using the set method
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);

    // # resetting to defaults
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);

    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "Enter an integer            : ";
    std::cin >> num;

    std::cout << "Decimal default             : " << num << std::endl;

    std::cout << "Hexadecimal default         : " << std::hex << num << std::endl;
    std::cout << "Hexadecimal uppercase       : " << std::hex << std::uppercase << num << std::endl;
    std::cout << "Hexadecimal still uppercase : " << std::hex << num << std::endl;
    std::cout << "Hexadecimal lowercase       : " << std::hex << std::nouppercase << num << std::endl;

    std::cout << "Octal                       : " << std::oct << num << std::endl;
    std::cout << "Hexadecimal w base          : " << std::hex << std::showbase << num << std::endl;
    std::cout << "Octal w base                : " << std::oct << num << std::endl;

    std::cout << std::endl
              << std::endl;
    return 0;
}