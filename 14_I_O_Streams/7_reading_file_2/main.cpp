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
    string text;
    int num;
    float decimal;
    std::ifstream reader;
    reader.open("test.txt");

    if (!reader)
    {
        cerr << "File wasn't read successfully" << endl;
        return 1;
    }

    while (reader >> text >> num >> decimal) //! !reader.eof() CHECK if it is not the end of file
    {
        cout << std::setw(13) << std::left << text << std::setw(6) << num << std::setw(8) << decimal << endl;
    }

    reader.close();

    return 0;
}