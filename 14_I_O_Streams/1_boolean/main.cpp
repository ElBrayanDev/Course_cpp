/*
# Stream manipulators
• Streams have useful member functions to control formatting

• Can be used on input and output streams

• The time of the effect on the stream varies

• Can be used as member functions or as a manipulator
   std::cout.width (10); // member function.
   std::cout << std::setw (10); // manipulator

• We'll focus on manipulator usage

# Formatting boolean types

• Default when displaying boolean values is 1 or 0
    ! cout << std::noboolalpha
• Sometimes the strings true or false are more appropriate
    ! cout << std::boolalpha

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

    cout << "noboolalpha - default  (10 == 10) : " << (10 == 10) << endl;
    cout << "noboolalpha - default  (10 == 20) : " << (10 == 20) << endl;

    // Set to true/false formatting
    cout << std::boolalpha; // # change to true/false
    cout << "boolalpha   (10 == 10) : " << (10 == 10) << endl;
    cout << "boolalpha   (10 == 20) : " << (10 == 20) << endl;

    // setting still stays for future boolean insertions
    cout << "boolalpha   (10 == 10) : " << (10 == 10) << endl;
    cout << "boolalpha   (10 == 20) : " << (10 == 20) << endl;

    cout << std::noboolalpha; // # Toggle to 0/1
    cout << "noboolalpha  (10 == 10) : " << (10 == 10) << endl;
    cout << "noboolalpha  (10 == 20) : " << (10 == 20) << endl;

    cout.setf(std::ios::boolalpha); // # Set back to true/false using setf method
    cout << "boolalpha   (10 == 10) : " << (10 == 10) << endl;
    cout << "boolalpha   (10 == 20) : " << (10 == 20) << endl;

    cout << std::resetiosflags(std::ios::boolalpha); // # resets to default which is 0/1
    cout << "Default  (10 == 10) : " << (10 == 10) << endl;
    cout << "Default  (10 == 20) : " << (10 == 20) << endl;
    return 0;
}