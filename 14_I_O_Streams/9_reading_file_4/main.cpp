/*
# Read a char at the time

@ElBrayan
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

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    std::ifstream reader{};
    string text{};
    char c{};

    reader.open("poem.txt");

    if (!reader)
    {
        cerr << "Problem reading file" << endl;
        return 1;
    }
    while (reader.get(c))
    {
        text += c; //! No line jump needed as in "reading_file_3"
    }

    cout << text;
    reader.close();

    return 0;
}