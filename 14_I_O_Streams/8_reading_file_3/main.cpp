/*
# Read and display Shakespeare Sonnet 18 poem using getline();
@ ElBrayan & Frank B.
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
    std::fstream reader{};
    string line{};
    string text{};

    reader.open("poem.txt");

    if (!reader)
    {
        cerr << "Problem reading file" << endl;
        return 1;
    }

    while (std::getline(reader, line))
    {
        line += "\n";
        text += line;
    }

    cout << text;

    return 0;
}