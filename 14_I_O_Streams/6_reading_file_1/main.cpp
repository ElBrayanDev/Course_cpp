/*
#Input files (fstream and ifstream)

fstream and ifstream are commonly used for input files
1. #include <fstream>
2. Declare an fstream or ifstream object
3. Connect it to a file on your file system (opens it for reading)
4. Read data from the file via the stream
5. Close the stream

{"name.txt", std::ios::out | std::ios::binary};

.eof() - checks end of file
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
    string text;
    int num;
    float decimal;
    std::ifstream reader;
    reader.open("test.txt");

    if (!reader) // or !reader.is_open()
    {
        cerr << "File wasn't read successfully" << endl;
        return 1; //? std::exit(1)
    }
    // cout << "File was read successfully";

    reader >> text >> num >> decimal;
    cout << text << num << decimal;

    reader.close(); //! Always close the file

    return 0;
}