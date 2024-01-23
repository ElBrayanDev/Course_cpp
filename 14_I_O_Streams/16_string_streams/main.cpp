/*
# Using string streams

• Allow us to read or write from strings in memory much as we would read and write to files
• Very powerful
• Very useful for data validation

! stringstream, istringstream and ostringstream

1. #include <sstream>
2. Declare an stringstream, istringstream or ostringstream object
3. Connect it to a std::string
4. Read/write data from/to the string stream using formatted I/O
*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <fstream>
#include <sstream>
#include <limits> // cleans int input

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int num{};
    double total{};
    string name{};

    string info{"Moe 100 1234.5"};
    std::istringstream iss{info};

    iss >> name >> num >> total;
    cout << std::setw(10) << std::left << name
         << std::setw(5) << num
         << std::setw(10) << total << endl;

    cout << "\n---------------------------------------" << endl;

    std::ostringstream oss{};
    oss << std::setw(10) << std::left << name
        << std::setw(5) << num
        << std::setw(10) << total << endl;
    cout << oss.str() << endl;

    cout << "\n--- Data validation ------------------------------------" << endl;

    int value{};
    std::string entry{};
    bool done = false;
    do
    {
        cout << "Please enter an integer: ";
        std::cin >> entry;
        std::istringstream validator{entry};
        if (validator >> value)
            done = true;
        else
            cout << "Sorry, that's not an integer" << endl;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // # discards the input buffer (may be decimals or chars)
    } while (!done);

    cout << "You entered the integer: " << value << endl;

    cout << endl;
    return 0;
}